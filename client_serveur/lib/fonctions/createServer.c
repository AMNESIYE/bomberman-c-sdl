/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** CreateServer
** File description:
**      createServer
*/

#include "../../include/server.h"

int serverInit (char *portNb) {
    if (validatePort(portNb) == -1) {
        return -1;
    }
    int port = my_atoi(portNb);
    if (port == -1) {
        return -1;
    }

    int socketSrv; 
    int client;
    socklen_t client_addr_len;
    struct sockaddr_in server;
    char buffer[128];
    int n;

    socketSrv = socket(AF_INET , SOCK_STREAM , 0);
    if (socketSrv < 0) {
        return -1;
    }

    server.sin_port = htons(port);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("0.0.0.0"); 

    if (bind(socketSrv , (struct sockaddr *)&server , sizeof(server)) < 0) {
        return -1;
    }
    if (listen(socketSrv , 5) < 0) {
        return -1;
    }

    memset(buffer, '\0', 128);

    puts("En attente de clients...");
    while(1){
        puts("En attente de reponse du client...");
        client = accept(socketSrv , (struct sockaddr *)&server , &client_addr_len);
        if (client < 0) {
            puts("Le client n'a pas répondu...");
            return -1;
        }
        puts("Nouveau client connecté.");
        while((n = read(client , buffer , 128)) > 0) {
            printf("Reçu: %s", buffer);
            memset(buffer, '\0', 128);
        }
        if (n <= 0){
            puts("Client fermé.");
        }
    }
    close(socketSrv);
    return 1;
}