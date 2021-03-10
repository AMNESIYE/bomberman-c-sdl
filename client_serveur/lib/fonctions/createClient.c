/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** CreateClient
** File description:
**      CreateClient
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "../../include/server.h"


int clientInit(char *portNb , char *ipAddr) {
    if (validatePort(portNb) == -1) {
        return -1;
    }
    int port = my_atoi(portNb);
    if (port == -1) {
        return -2;
    }

    int socketCli;
    struct sockaddr_in addr;
    socketCli = socket(AF_INET , SOCK_STREAM , 0);
    if (socketCli < 0) {
        return -3;
    }

    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ipAddr);

    if (connect(socketCli , (struct sockaddr *)&addr , sizeof(addr)) < 0) {
        return -4;
    }
    send(socketCli , "Hello\n" , 6 , 0);
    return 0;


}