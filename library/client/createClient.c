/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** CreateClient
** File description:
**      CreateClient
*/

#include "../../include/server.h"


int clientInit(char *portNb) {
    if (my_portCheck(portNb) == -1) {
        return -1;
    }
    int port = my_atoi(portNb);
    if (port == -1) {
        return -1;
    }

    int n;
    char bufferC[BUFFER_SIZE], bufferS[BUFFER_SIZE];
    int socketCli;
    struct sockaddr_in addr;
    socketCli = socket(AF_INET, SOCK_STREAM, 0);
    if (socketCli < 0) {
        return -1;
    }

    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(socketCli, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        return -1;
    }

    while (1) {
        memset(bufferC, '\0', BUFFER_SIZE);
        fgets(bufferC, BUFFER_SIZE, stdin);
        if (send(socketCli, bufferC, strlen(bufferC), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        printf("\tEnvoyé: %s\n", bufferC);
        if (recv(socketCli, bufferS, BUFFER_SIZE, 0) >= 0) {
            printf("\tReçu: %s", bufferS);
        }
        memset(bufferS, '\0', BUFFER_SIZE);
    }
    close(socketCli);
    return 0;


}