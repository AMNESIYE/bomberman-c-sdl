/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_playGame.c
** File description:
**
*/

#include "../../../include/game.h"
#include "../../../include/objects.h"
#include "../../../include/server.h"
#include "../../../include/client.h"
#include "../../../include/basical.h"

static int TestThread() {
    int count = 0;
    return count;
}

static int checkEndGame(int playersNumber, struct character charTable[]) {
    int deathCount = 0;
    for (int i = 0; i < playersNumber; i++) {
        if (charTable[i].stats.lifePoints == 0)
            deathCount++;
    }
    if (deathCount >= playersNumber - 1)
        return 1;
    else
        return 0;
}

static void my_deathOverlay(SDL_Renderer *renderer) {
    SDL_Rect deathText = {215, 10, 200, 75};
    my_drawText(renderer, deathText, 150, 0, 0, "Vous etes mort");
    SDL_Rect deathBlock = {0, 40, 25, 25};
    for (int i = 0; i < 8; i++) {
        my_drawImage(renderer, deathBlock,
                     "./library/assets/block/block (75).bmp");
        deathBlock.x = deathBlock.x + 25;
    }
    deathBlock.x = deathBlock.x + 225;
    for (int i = 0; i < 9; i++) {
        my_drawImage(renderer, deathBlock,
                     "./library/assets/block/block (75).bmp");
        deathBlock.x = deathBlock.x + 25;
    }
}

static void my_waitingScreen(SDL_Renderer *renderer) {
    SDL_Rect waitText = {190, 10, 250, 75};
    my_drawText(renderer, waitText, 150, 0, 0, "En Attente de joueur...");

}

static void my_setupOverlay(SDL_Renderer *renderer) {
    my_drawLine(renderer, 0, 99, 600, 99, 0, 0, 0);
}

static void my_setupWall(SDL_Renderer *renderer, struct wall wallTable[]) {
    for (int i = 0; i < 225; i++) {
        if (wallTable[i].hitbox.w == 40) {
            if (wallTable[i].breakable == 0)
                wallTable[i].skin = "./library/assets/block/block (74).bmp";
            else if (wallTable[i].breakable == 1)
                wallTable[i].skin = "./library/assets/block/block (3).bmp";
            else if (wallTable[i].breakable == 4)
                wallTable[i].skin = "./library/assets/bomb40.bmp";
            else if (wallTable[i].breakable == 5)
                wallTable[i].skin = "./library/assets/bomb40trans.bmp";
            if (wallTable[i].breakable == 2)
                wallTable[i].skin = "";
            my_drawImage(renderer, wallTable[i].hitbox, wallTable[i].skin);
        }
    }
}

void checkCharLife(struct character charTable[], int playersNumber) {
    for (int i = 0; i < playersNumber; i++) {
        if (charTable[i].hitbox.y == 0)
            charTable[i].stats.lifePoints = 0;
    }
}

static void
my_refreshPlayScene(SDL_Renderer *renderer, struct character charTable[],
                    struct wall wallTable[], int playersNumber,
                    int amIAlive, int allConnected) {
    my_clearWindows(renderer);
    my_setupOverlay(renderer);
    my_setupWall(renderer, wallTable);
    checkCharLife(charTable, playersNumber);
    for (int i = 0; i < playersNumber; i++) {
        if (charTable[i].hitbox.w == 40 && charTable[i].hitbox.h == 40 &&
            charTable[i].stats.lifePoints > 0) {
            if (charTable[i].skin != NULL) {
                my_drawImage(renderer, charTable[i].hitbox, charTable[i].skin);
            } else {
                my_drawRectangle(renderer, charTable[i].hitbox,
                                 charTable[i].colors.red,
                                 charTable[i].colors.green,
                                 charTable[i].colors.blue);
            }
        }
    }
    if (amIAlive == 0) {
        my_deathOverlay(renderer);
    }
    if (allConnected == 0)
        my_waitingScreen(renderer);
    SDL_RenderPresent(renderer);
}

static int atoi_n(char *bufferS) {
    for (int i = 0; bufferS[i] != '\0'; i++) {
        if (bufferS[i] == '\n') {
            bufferS[i] = '\0';
        }
        if (bufferS[i] == '\0')
            break;
    }
    return atoi(bufferS);
}

int my_playGameClient(SDL_Window *window, SDL_Renderer *renderer, char *name, char *ip) {
    char bufferC[BUFFER_SIZE], bufferS[BUFFER_SIZE];
    int socketCli;
    struct sockaddr_in addr;
    socketCli = socket(AF_INET, SOCK_STREAM, 0);
    if (socketCli < 0) {
        return -1;
    }

    addr.sin_port = htons(PORT);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(socketCli, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        return 8;
    }

    int playersNumber = 4;

    // Fin partie client
    SDL_Thread *thread = NULL;

    struct character charTable[] = {my_initCharacter(MY_CHARACTER),
                                    my_initCharacter(ENEMY_CHARACTER),
                                    my_initCharacter(BLANK_CHARACTER),
                                    my_initCharacter(BLANK_CHARACTER)};
    struct character *charTableI = charTable;
    my_initializeCharactersPosition(charTableI);

    struct wall wallTable[225];
    struct wall *wallTableI = wallTable;
    my_genMap("./library/assets/maps/map.txt", wallTableI);

    int amIAlive = 1;
    int allConnected = 0;
    int endGame = 0;

    my_refreshPlayScene(renderer, charTableI, wallTable, playersNumber,
                        amIAlive, allConnected);

    strcpy(bufferC, "NBPLAYS\n");
    if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
        puts("L'envoi a échoué.");
        close(socketCli);
        return -1;
    }
    if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
        SDL_Log("NB_PLAYERS -> Recv Failed");
    }
    playersNumber = atoi_n(bufferS);
    printf("NB_PLAYERS -> %i\n", playersNumber);

    SDL_Event event;

    int baseTick;

    int clientID;

    strcpy(bufferC, "CLIENT_ID\n");
    if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
        puts("L'envoi a échoué.");
        close(socketCli);
        return -1;
    }
    if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
        SDL_Log("CLIENT_ID -> Recv Failed");
    }
    clientID = atoi_n(bufferS);
    printf("PLAY_GAME_CLIENT -> THIS CLIENT ID IS N°%i\n", clientID);

    allConnected++;

    while (1) {
        thread = SDL_CreateThread(TestThread, name, NULL);
        baseTick = SDL_GetTicks();

        memset(bufferC, '\0', BUFFER_SIZE);
        memset(bufferS, '\0', BUFFER_SIZE);

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    my_exitWindows(window, renderer);
                    SDL_WaitThread(thread, NULL);
                    return 0;
                case SDL_KEYDOWN:
                    if (amIAlive != 0) {
                        switch (event.key.keysym.sym) {
                            case SDLK_UP:
                                strcpy(bufferC, "UP\n");
                                if (send(socketCli, bufferC, strlen(bufferC),
                                         MSG_NOSIGNAL) < 0) {
                                    close(socketCli);
                                    return -1;
                                }
                                if (recv(socketCli, bufferS, BUFFER_SIZE, 0) <
                                    0) {
                                    SDL_Log("SDLK_UP -> Recv Failed");
                                }
                                break;
                            case SDLK_RIGHT:
                                strcpy(bufferC, "RIGHT\n");
                                if (send(socketCli, bufferC, strlen(bufferC),
                                         MSG_NOSIGNAL) < 0) {
                                    close(socketCli);
                                    return -1;
                                }
                                if (recv(socketCli, bufferS, BUFFER_SIZE, 0) <
                                    0) {
                                    SDL_Log("SDLK_RIGHT -> Recv Failed");
                                }
                                break;
                            case SDLK_DOWN:
                                strcpy(bufferC, "DOWN\n");
                                if (send(socketCli, bufferC, strlen(bufferC),
                                         MSG_NOSIGNAL) < 0) {
                                    close(socketCli);
                                    return -1;
                                }
                                if (recv(socketCli, bufferS, BUFFER_SIZE, 0) <
                                    0) {
                                    SDL_Log("SDLK_DOWN -> Recv Failed");
                                }
                                break;
                            case SDLK_LEFT:
                                strcpy(bufferC, "LEFT\n");
                                if (send(socketCli, bufferC, strlen(bufferC),
                                         MSG_NOSIGNAL) < 0) {
                                    close(socketCli);
                                    return -1;
                                }
                                if (recv(socketCli, bufferS, BUFFER_SIZE, 0) <
                                    0) {
                                    SDL_Log("SDLK_LEFT -> Recv Failed");
                                }
                                break;
                            case SDLK_SPACE:
                                strcpy(bufferC, "BOMB\n");
                                if (send(socketCli, bufferC, strlen(bufferC),
                                         MSG_NOSIGNAL) < 0) {
                                    close(socketCli);
                                    return -1;
                                }
                                if (recv(socketCli, bufferS, BUFFER_SIZE, 0) <
                                    0) {
                                    SDL_Log("SDLK_BOMB -> Recv Failed");
                                }
                                break;
                        }
                    }
                    break;
            }
        }

        if (my_requestMapToServer(wallTableI, bufferC, bufferS, socketCli, "MAP1\n", 0, 15) > 0)
            return -1;
        if (my_requestMapToServer(wallTableI, bufferC, bufferS, socketCli, "MAP2\n", 15, 30) > 0)
            return -1;
        if (my_requestMapToServer(wallTableI, bufferC, bufferS, socketCli, "MAP3\n", 30, 45) > 0)
            return -1;
        if (my_requestMapToServer(wallTableI, bufferC, bufferS, socketCli, "MAP4\n", 45, 60) > 0)
            return -1;
        if (my_requestMapToServer(wallTableI, bufferC, bufferS, socketCli, "MAP5\n", 60, 75) > 0)
            return -1;
        if (my_requestMapToServer(wallTableI, bufferC, bufferS, socketCli, "MAP6\n", 75, 90) > 0)
            return -1;
        if (my_requestMapToServer(wallTableI, bufferC, bufferS, socketCli, "MAP7\n", 90, 105) > 0)
            return -1;
        if (my_requestMapToServer(wallTableI, bufferC, bufferS, socketCli, "MAP8\n", 105, 120) > 0)
            return -1;
        if (my_requestMapToServer(wallTableI, bufferC, bufferS, socketCli, "MAP9\n", 120, 135) > 0)
            return -1;
        if (my_requestMapToServer(wallTableI, bufferC, bufferS, socketCli, "MAP10\n", 135, 150) > 0)
            return -1;
        if (my_requestMapToServer(wallTableI, bufferC, bufferS, socketCli, "MAP11\n", 150, 165) > 0)
            return -1;
        if (my_requestMapToServer(wallTableI, bufferC, bufferS, socketCli, "MAP12\n", 165, 180) > 0)
            return -1;
        if (my_requestMapToServer(wallTableI, bufferC, bufferS, socketCli, "MAP13\n", 180, 195) > 0)
            return -1;
        if (my_requestMapToServer(wallTableI, bufferC, bufferS, socketCli, "MAP14\n", 195, 210) > 0)
            return -1;
        if (my_requestMapToServer(wallTableI, bufferC, bufferS, socketCli, "MAP15\n", 210, 225) > 0)
            return -1;


        //x1
        strcpy(bufferC, "P1x\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_PLAYER_1_x -> Recv Failed");
        }
        charTableI[0].hitbox.x = atoi_n(bufferS);
        //y1
        strcpy(bufferC, "P1y\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_PLAYER_1_y -> Recv Failed");
        }
        charTableI[0].hitbox.y = atoi_n(bufferS);

        //x2
        strcpy(bufferC, "P2x\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_PLAYER_2_x -> Recv Failed");
        }
        charTableI[1].hitbox.x = atoi_n(bufferS);
        //y2
        strcpy(bufferC, "P2y\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_PLAYER_2_y -> Recv Failed");
        }
        charTableI[1].hitbox.y = atoi_n(bufferS);

        //x3
        if (playersNumber > 2) {
            strcpy(bufferC, "P3x\n");
            if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
                puts("L'envoi a échoué.");
                close(socketCli);
                return -1;
            }
            if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
                SDL_Log("GET_PLAYER_3_x -> Recv Failed");
            }
            charTableI[2].hitbox.x = atoi_n(bufferS);
            //y3
            strcpy(bufferC, "P3y\n");
            if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
                puts("L'envoi a échoué.");
                close(socketCli);
                return -1;
            }
            if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
                SDL_Log("GET_PLAYER_3_y -> Recv Failed");
            }
            charTableI[2].hitbox.y = atoi_n(bufferS);
            if (playersNumber > 3) {
                strcpy(bufferC, "P4x\n");
                if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) <
                    0) {
                    puts("L'envoi a échoué.");
                    close(socketCli);
                    return -1;
                }
                if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
                    SDL_Log("GET_PLAYER_4_x -> Recv Failed");
                }
                charTableI[3].hitbox.x = atoi_n(bufferS);
                //y3
                strcpy(bufferC, "P4y\n");
                if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) <
                    0) {
                    puts("L'envoi a échoué.");
                    close(socketCli);
                    return -1;
                }
                if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
                    SDL_Log("GET_PLAYER_4_y -> Recv Failed");
                }
                charTableI[3].hitbox.y = atoi_n(bufferS);
            }
        }

        // Am i alive ?
        strcpy(bufferC, "AMIA\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_PLAYER_1_y -> Recv Failed");
        }
        printf("Alive ? %s", bufferS);
        if (atoi_n(bufferS) == 0)
            amIAlive = 0;

        endGame = checkEndGame(playersNumber, charTableI);
        my_refreshPlayScene(renderer, charTableI, wallTable, playersNumber,
                            amIAlive, allConnected);
        if (endGame == 1) {
            if (amIAlive == 1)
                return 1;
            else
                return 2;
        }

        if ((1000 / FPS) > SDL_GetTicks() - baseTick) {
            SDL_Delay(1000 / FPS - (SDL_GetTicks() - baseTick));
        }

    }
    return 0;
}