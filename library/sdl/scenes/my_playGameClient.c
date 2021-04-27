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


void my_deathOverlay(SDL_Renderer *renderer) {
    SDL_Rect deathText = {215, 10, 200, 75 };
    my_drawText(renderer , deathText , 150 , 0 , 0 , "Vous etes mort");
    SDL_Rect deathBlock = {0 , 40 , 25 , 25};
    for (int i = 0 ; i < 8; i++) {
        my_drawImage(renderer , deathBlock , "./library/assets/block/block (75).bmp");
        deathBlock.x = deathBlock.x + 25;
    }
    deathBlock.x = deathBlock.x + 225;
    for (int i = 0 ; i < 9 ; i++) {
        my_drawImage(renderer , deathBlock , "./library/assets/block/block (75).bmp");
        deathBlock.x = deathBlock.x + 25;
    }
}

void my_waitingScreen(SDL_Renderer *renderer) {
    SDL_Rect waitText = {190, 10, 250, 75 };
    my_drawText(renderer , waitText , 150 , 0 , 0 , "En Attente de joueur...");
    
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
            if (wallTable[i].breakable == 2)
                wallTable[i].skin = "";
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
        //L1
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
        for (int i = 0, j = 0; i < 15; i++, j++) {
            char sub[2];
            strncpy(sub, bufferS + j, 1);
            printf("b1:%s ", sub);
            wallTable[i].breakable = atoi(sub);
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
        for (int i = 15, j = 0; i < 30; i++, j++) {
            char sub[2];
            strncpy(sub, bufferS + j, 1);
            printf("b2:%s ", sub);
            wallTable[i].breakable = atoi(sub);
        }
        //L3
        strcpy(bufferC, "MAP3\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_MAP -> Recv Failed");
        }
        printf("oui:%s", bufferS);
        for (int i = 30, j = 0; i < 45; i++, j++) {
            char sub[2];
            strncpy(sub, bufferS + j, 1);
            printf("b3:%s ", sub);
            wallTable[i].breakable = atoi(sub);
        }
        //L4
        strcpy(bufferC, "MAP4\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_MAP -> Recv Failed");
        }
        printf("oui:%s", bufferS);
        for (int i = 45, j = 0; i < 60; i++, j++) {
            char sub[2];
            strncpy(sub, bufferS + j, 1);
            printf("b4:%s ", sub);
            wallTable[i].breakable = atoi(sub);
        }
        //L5
        strcpy(bufferC, "MAP5\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_MAP -> Recv Failed");
        }
        printf("oui:%s", bufferS);
        for (int i = 60, j = 0; i < 75; i++, j++) {
            char sub[2];
            strncpy(sub, bufferS + j, 1);
            printf("b5:%s ", sub);
            wallTable[i].breakable = atoi(sub);
        }
        //L6
        strcpy(bufferC, "MAP6\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_MAP -> Recv Failed");
        }
        printf("oui:%s", bufferS);
        for (int i = 75, j = 0; i < 90; i++, j++) {
            char sub[2];
            strncpy(sub, bufferS + j, 1);
            printf("b6:%s ", sub);
            wallTable[i].breakable = atoi(sub);
        }
        //L7
        strcpy(bufferC, "MAP7\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_MAP -> Recv Failed");
        }
        printf("oui:%s", bufferS);
        for (int i = 90, j = 0; i < 105; i++, j++) {
            char sub[2];
            strncpy(sub, bufferS + j, 1);
            printf("b7:%s ", sub);
            wallTable[i].breakable = atoi(sub);
        }
        //L8
        strcpy(bufferC, "MAP8\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_MAP -> Recv Failed");
        }
        printf("oui:%s", bufferS);
        for (int i = 105, j = 0; i < 120; i++, j++) {
            char sub[2];
            strncpy(sub, bufferS + j, 1);
            printf("b8:%s ", sub);
            wallTable[i].breakable = atoi(sub);
        }
        //L9
        strcpy(bufferC, "MAP9\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_MAP -> Recv Failed");
        }
        printf("oui:%s", bufferS);
        for (int i = 120, j = 0; i < 135; i++, j++) {
            char sub[2];
            strncpy(sub, bufferS + j, 1);
            printf("b9:%s ", sub);
            wallTable[i].breakable = atoi(sub);
        }
        //L10
        strcpy(bufferC, "MAP10\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_MAP -> Recv Failed");
        }
        printf("oui:%s", bufferS);
        for (int i = 135, j = 0; i < 150; i++, j++) {
            char sub[2];
            strncpy(sub, bufferS + j, 1);
            printf("b10:%s ", sub);
            wallTable[i].breakable = atoi(sub);
        }
        //L10
        strcpy(bufferC, "MAP11\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_MAP -> Recv Failed");
        }
        printf("oui:%s", bufferS);
        for (int i = 150, j = 0; i < 165; i++, j++) {
            char sub[2];
            strncpy(sub, bufferS + j, 1);
            printf("b11:%s ", sub);
            wallTable[i].breakable = atoi(sub);
        }
        //L12
        strcpy(bufferC, "MAP12\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_MAP -> Recv Failed");
        }
        printf("oui:%s", bufferS);
        for (int i = 165, j = 0; i < 180; i++, j++) {
            char sub[2];
            strncpy(sub, bufferS + j, 1);
            printf("b12:%s ", sub);
            wallTable[i].breakable = atoi(sub);
        }
        //L13
        strcpy(bufferC, "MAP13\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_MAP -> Recv Failed");
        }
        printf("oui:%s", bufferS);
        for (int i = 180, j = 0; i < 195; i++, j++) {
            char sub[2];
            strncpy(sub, bufferS + j, 1);
            printf("b13:%s ", sub);
            wallTable[i].breakable = atoi(sub);
        }
        //L14
        strcpy(bufferC, "MAP14\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_MAP -> Recv Failed");
        }
        printf("oui:%s", bufferS);
        for (int i = 195, j = 0; i < 210; i++, j++) {
            char sub[2];
            strncpy(sub, bufferS + j, 1);
            printf("b14:%s ", sub);
            wallTable[i].breakable = atoi(sub);
        }
        //L10
        strcpy(bufferC, "MAP15\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_MAP -> Recv Failed");
        }
        printf("oui:%s", bufferS);
        for (int i = 210, j = 0; i < 225; i++, j++) {
            char sub[2];
            strncpy(sub, bufferS + j, 1);
            printf("b15:%s ", sub);
            wallTable[i].breakable = atoi(sub);
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