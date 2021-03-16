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
        n = read(0, buffer, 128);
        if (n <= 0) {
            return -1;
        }
        if (send(socketCli , buffer , n + 1 , MSG_NOSIGNAL) < 0) {
            puts("L'envoi a échoué.");
            close(socketCli);
            return -1;
        }
        printf("Envoyé: %s\n", buffer);
        //read(socketCli, buffer, 128);
    }
    close(socketCli);
    return 0;


}