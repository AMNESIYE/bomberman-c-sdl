/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** CreateClient
** File description:
**      CreateClient
*/

#include "../../include/server.h"


int clientInit(char *portNb , char *ipAddr) {
    if (validatePort(portNb) == -1) {
        return -1;
    }
    int port = my_atoi(portNb);
    if (port == -1) {
        return -1;
    }

    int n = 0;
    char buffer[128];
    int socketCli;
    struct sockaddr_in addr;
    socketCli = socket(AF_INET , SOCK_STREAM , 0);
    if (socketCli < 0) {
        return -1;
    }

    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ipAddr);

    if (connect(socketCli , (struct sockaddr *)&addr , sizeof(addr)) < 0) {
        return -1;
    }


    while(1) {
        memset(buffer , '\n' , 128);
        n = read(0 , buffer , 128);
        if (n == 0) {
            return -1;
        }
        if (n < 0) {
            return -1;
        }
        send(socketCli , buffer , n , 0);
    }
    return 0;


}