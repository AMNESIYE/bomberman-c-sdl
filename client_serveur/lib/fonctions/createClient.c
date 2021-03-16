/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** CreateClient
** File description:
**      CreateClient
*/

#include "../../include/server.h"


int clientInit(char *portNb) {
    if (validatePort(portNb) == -1) {
        return -1;
    }
    int port = my_atoi(portNb);
    if (port == -1) {
        return -1;
    }

    int n;
    char buffer[128];
    int socketCli;
    struct sockaddr_in addr;
    socketCli = socket(AF_INET , SOCK_STREAM , 0);
    if (socketCli < 0) {
        return -1;
    }

    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(socketCli , (struct sockaddr *)&addr , sizeof(addr)) < 0) {
        return -1;
    }

    while(1) {
        memset(buffer, '\0', 128);
        fgets(buffer, 128, stdin);
        if (send(socketCli, buffer, strlen(buffer), MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        printf("\tEnvoyé: %s\n", buffer);
        recv(socketCli, buffer, 128, MSG_DONTWAIT);
    }
    close(socketCli);
    return 0;


}