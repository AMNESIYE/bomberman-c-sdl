/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_playGame.c
** File description:
**
*/

#include "../../../include/game.h"
#include "../../../include/objects.h"
#include "../../../include/server.h"

static int TestThread() {
    int count = 0;

    // Si un truc à faire/compter pour le thread

    return count;
}

void my_setupOverlay(SDL_Renderer *renderer) {
    my_drawLine(renderer, 0, 99, 600, 99, 0, 0, 0);
}

void my_refreshPlayScene(SDL_Renderer *renderer, struct character charTable[], int playersNumber) {
    SDL_Log("PlayScene -> Entering refresh scene");

    my_clearWindows(renderer);
    my_setupOverlay(renderer);
    for (int i = 0; i < playersNumber; i++) {
        if (charTable[i].hitbox.w == 30 && charTable[i].hitbox.h == 30) {
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

void my_initializeCharactersPosition(struct character charTable[]) {
    charTable[0].hitbox.x = 30;
    charTable[0].hitbox.y = 130;
    charTable[0].name = "player1";

    charTable[1].hitbox.x = 540;
    charTable[1].hitbox.y = 130;
    charTable[0].name = "player2";

    if (charTable[2].hitbox.w == 30 && charTable[2].hitbox.h == 30) {
        charTable[2].hitbox.x = 30;
        charTable[2].hitbox.y = 640;
        charTable[0].name = "player3";
    }

    if (charTable[3].hitbox.w == 30 && charTable[3].hitbox.h == 30) {
        charTable[3].hitbox.x = 540;
        charTable[3].hitbox.y = 640;
        charTable[0].name = "player4";
    }
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

    my_refreshPlayScene(renderer, charTableI, playersNumber);

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
    printf("\tEnvoyé: %s", bufferC);
    if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
        SDL_Log("CLIENT_ID -> Recv Failed");
    }
    printf("\tReçu: %s", bufferS);
    clientID = bufferS[0] - '0';
    printf("THIS CLIENT ID IS N°%i\n", clientID);
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
                            strcpy(bufferC, "SET_UP\n");
                            if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
                                close(socketCli);
                                return -1;
                            }
                            if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
                                SDL_Log("SDLK_UP -> Recv Failed");
                            }
                            break;
                        case SDLK_RIGHT:
                            strcpy(bufferC, "SET_RIGHT\n");
                            if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
                                close(socketCli);
                                return -1;
                            }
                            if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
                                SDL_Log("SDLK_RIGHT -> Recv Failed");
                            }
                            break;
                        case SDLK_DOWN:
                            strcpy(bufferC, "SET_DOWN\n");
                            if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
                                close(socketCli);
                                return -1;
                            }
                            if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
                                SDL_Log("SDLK_DOWN -> Recv Failed");
                            }
                            break;
                        case SDLK_LEFT:
                            strcpy(bufferC, "SET_LEFT\n");
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

        strcpy(bufferC, "GET_PLAYER_1_x\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        //x
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_PLAYER_x -> Recv Failed");
        }
        for (int i = 0; bufferS[i] != '\0'; i++) {
            if (bufferS[i] == '\n'){
                bufferS[i] = '\0';
            }
            if (bufferS[i] == '\0')
                break;
        }
        charTableI[0].hitbox.x = atoi(bufferS);
        //y
        strcpy(bufferC, "GET_PLAYER_1_y\n");
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
            SDL_Log("GET_PLAYER_1_y -> Recv Failed");
        }
        for (int i = 0; bufferS[i] != '\0'; i++) {
            if (bufferS[i] == '\n'){
                bufferS[i] = '\0';
            }
            if (bufferS[i] == '\0')
                break;
        }
        charTableI[0].hitbox.y = atoi(bufferS);

        my_refreshPlayScene(renderer, charTableI, playersNumber);

        if ((1000 / FPS) > SDL_GetTicks() - baseTick) {
            SDL_Delay(1000 / FPS - (SDL_GetTicks() - baseTick));
        }
    }
    return 0;
}