/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_requestMapToServer.c
** File description:
**
*/

#include "../../include/game.h"
#include "../../include/objects.h"
#include "../../include/server.h"
#include "../../include/basical.h"
#include "../../include/client.h"

int my_requestMapToServer(struct wall wallTable[], char *bufferC, char *bufferS,
                          int socketCli, char *request, int start, int end) {
    strcpy(bufferC, request);
    if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
        puts("L'envoi a échoué.");
        close(socketCli);
        return -1;
    }
    if (recv(socketCli, bufferS, BUFFER_SIZE, 0) < 0) {
        SDL_Log("GET_MAP -> Recv Failed");
    }
    for (int i = start, j = 0; i < end; i++, j++) {
        char sub[2];
        strncpy(sub, bufferS + j, 1);
        wallTable[i].breakable = atoi(sub);
    }
    return 0;
}
