/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** CreateServer
** File description:
**      createServer
*/

#include "../../include/server.h"

int read_client(int client) {
    int n;
    char buffer[128];

    if (client == -1) {
        return 1;
    }

    n = 0;
    memset(buffer, '\0', 128);
    while((n = recv(client , buffer , 128, 0)) >= 0) {
        if(n == 0) {
            return -1;
        }
        printf("\tReçu: %s", buffer);

        if (buffer[n - 1] == '\n') {
            memset(buffer, '\0', 128);
            break;
        }
    }
    return 0;
}

int serverInit (char *portNb) {
    if (validatePort(portNb) == -1) {
        return -1;
    }
    int port = my_atoi(portNb);
    if (port == -1) {
        return -1;
    }

    int socketSrv; 
    int client1;
    int client2;
    //int client3;
    //int client4;
    socklen_t client_addr_len;
    struct sockaddr_in server;

    fd_set readfs;
    struct timeval tick;

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

    puts("En attente de clients...");
    while(1){
        puts("En attente de reponse du premier client...");
        client1 = accept(socketSrv , (struct sockaddr *)&server , &client_addr_len);
        puts("Nouveau client connecté.");
        puts("En attente de reponse du deuxième client...");
        client2 = accept(socketSrv , (struct sockaddr *)&server , &client_addr_len);
        if (client1 < 0 || client2 < 0) {
            puts("L'un des clients n'a pas répondu...");
            return -1;
        }
        puts("Nouveau client connecté.");
        puts("La partie démarre !");
        while(1) {
            tick.tv_sec = 1;
            tick.tv_usec = 0;
            FD_ZERO(&readfs);
            FD_SET(client1, &readfs);
            FD_SET(client2, &readfs);

            select(client2 + 1, &readfs, NULL, NULL, &tick);

            if (FD_ISSET(client1, &readfs)) {
                if (read_client(client1) == -1) {
                    puts("Premier client déconnecté");
                    close(client1);
                    client1 = -1;
                }
            } else if (FD_ISSET(client2, &readfs)) {
                if (read_client(client2) == -1) {
                    puts("Deuxième client déconnecté");
                    close(client2);
                    client2 = -1;
                }
            }


            if (client1 == -1 && client2 == -1) {
                break;
            }
            puts("tick");
        }
    }
    close(socketSrv);
    return 1;
}