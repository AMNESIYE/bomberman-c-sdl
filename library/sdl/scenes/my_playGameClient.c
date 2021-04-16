/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_playGame.c
** File description:
**
*/

#include "../../../include/game.h"
#include "../../../include/objects.h"
#include "../../../include/server.h"
#include "../../../include/basical.h"

static int TestThread() {
    int count = 0;

    // Si un truc à faire/compter pour le thread

    return count;
}

void my_setupOverlay(SDL_Renderer *renderer) {
    my_drawLine(renderer, 0, 99, 600, 99, 0, 0, 0);
}

void my_setupWall(SDL_Renderer *renderer, struct wall wallTable[]) {
    for (int i = 0; i < 225; i++) {
        if (wallTable[i].hitbox.w == 40) {
            if (wallTable[i].breakable == 0)
                wallTable[i].skin = "./library/assets/block/block (74).bmp";
            else if (wallTable[i].breakable == 1)
                wallTable[i].skin = "./library/assets/block/block (3).bmp";
            if (wallTable[i].broken != 1)
                my_drawImage(renderer, wallTable[i].hitbox, wallTable[i].skin);
        }
    }
}

void
my_refreshPlayScene(SDL_Renderer *renderer, struct character charTable[], struct wall wallTable[], int playersNumber) {
    my_clearWindows(renderer);
    my_setupOverlay(renderer);
    my_setupWall(renderer, wallTable);
    for (int i = 0; i < playersNumber; i++) {
        if (charTable[i].hitbox.w == 40 && charTable[i].hitbox.h == 40) {
            if (charTable[i].skin != NULL) {
                my_drawImage(renderer, charTable[i].hitbox, charTable[i].skin);
            } else {
                my_drawRectangle(renderer, charTable[i].hitbox, charTable[i].colors.red, charTable[i].colors.green,
                                 charTable[i].colors.blue);
            }
        }
    }
    SDL_RenderPresent(renderer);
}

int atoi_n(char *bufferS) {
    for (int i = 0; bufferS[i] != '\0'; i++) {
        if (bufferS[i] == '\n') {
            bufferS[i] = '\0';
        }
        if (bufferS[i] == '\0')
            break;
    }
    return atoi(bufferS);
}

int my_playGameClient(SDL_Window *window, SDL_Renderer *renderer, char *name) {
    //Début Partie client
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
        return 1;
    }


    // Fin partie client
    SDL_Thread *thread = NULL;
    int playersNumber = 2; // A variabiliser

    struct character charTable[] = {my_initCharacter(MY_CHARACTER), my_initCharacter(ENEMY_CHARACTER),
                                    my_initCharacter(BLANK_CHARACTER), my_initCharacter(BLANK_CHARACTER)};
    struct character *charTableI = charTable;
    my_initializeCharactersPosition(charTableI);

    struct wall wallTable[225];
    struct wall *wallTableI = wallTable;
    my_genMap("./library/assets/maps/map.txt", wallTableI);
    //my_initWalls(wallTableI);

    my_refreshPlayScene(renderer, charTableI, wallTable, playersNumber);

    SDL_Event event;

    int baseTick;

    // Set Client_ID here
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
    // END


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
                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                            strcpy(bufferC, "UP\n");
                            if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
                                close(socketCli);
                                return -1;
                            }
                            if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
                                SDL_Log("SDLK_UP -> Recv Failed");
                            }
                            break;
                        case SDLK_RIGHT:
                            strcpy(bufferC, "RIGHT\n");
                            if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
                                close(socketCli);
                                return -1;
                            }
                            if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
                                SDL_Log("SDLK_RIGHT -> Recv Failed");
                            }
                            break;
                        case SDLK_DOWN:
                            strcpy(bufferC, "DOWN\n");
                            if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
                                close(socketCli);
                                return -1;
                            }
                            if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
                                SDL_Log("SDLK_DOWN -> Recv Failed");
                            }
                            break;
                        case SDLK_LEFT:
                            strcpy(bufferC, "LEFT\n");
                            if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
                                close(socketCli);
                                return -1;
                            }
                            if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
                                SDL_Log("SDLK_LEFT -> Recv Failed");
                            }
                            break;
                    }
                    break;
            }
        }
        //x1
        strcpy(bufferC, "P1x\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_PLAYER_x -> Recv Failed");
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
            SDL_Log("GET_PLAYER_x -> Recv Failed");
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
            SDL_Log("GET_PLAYER_1_y -> Recv Failed");
        }
        charTableI[1].hitbox.y = atoi_n(bufferS);
        //map A BIND pour envoyer et recevoir données map - découper CSV
        //
        //
        //
        strcpy(bufferC, "MAP1\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_MAP -> Recv Failed");
        }
        printf("oui:%s", bufferS);
        for (int i = 0; i < 15; i++) {
            char sub[2];
            memcpy(sub, &bufferS[i], 1);
            sub[1] = '\0';
            wallTable[i].broken = atoi(sub);
        }
        //L2
        strcpy(bufferC, "MAP2\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_MAP -> Recv Failed");
        }
        printf("oui:%s", bufferS);
        for (int i = 15; i < 30; i++) {
            char sub[2];
            memcpy(sub, &bufferS[i], 1);
            sub[1] = '\0';
            wallTable[i].broken = atoi(sub);
        }



        //
        //
        //
        my_refreshPlayScene(renderer, charTableI, wallTable, playersNumber);

        if ((1000 / FPS) > SDL_GetTicks() - baseTick) {
            SDL_Delay(1000 / FPS - (SDL_GetTicks() - baseTick));
        }
    }
    return 0;
}