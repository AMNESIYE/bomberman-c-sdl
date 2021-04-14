/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** CreateServer
** File description:
**      createServer
*/

#include "../../include/server.h"
#include "../../include/basical.h"

int write_client(int client, char *bufferS) {

    /*char bufferS[BUFFER_SIZE];
    strcpy(bufferS, "OK\n");*/

    if (send(client, bufferS, strlen(bufferS), MSG_DONTWAIT) >= 0) {
        printf("\tEnvoyé: %s", bufferS);
        return 1;
    } else {
        puts("\tLe retour d'envoi a échoué.");
        return -1;
    }
}

int read_client(int client) {
    int n;
    char bufferC[BUFFER_SIZE];

    if (client == -1) {
        return 1;
    }

    n = 0;
    memset(bufferC, '\0', BUFFER_SIZE);
    puts("read1");
    while ((n = recv(client, bufferC, BUFFER_SIZE, 0)) >= 0) {
        if (n == 0) {
            return -1;
        }
        printf("\tReçu: %s", bufferC);

        write_client(client, bufferC);

        if (bufferC[n - 1] == '\n') {
            memset(bufferC, '\0', BUFFER_SIZE);
            break;
        }
        puts("read2");
    }
    return 0;
}

int askClientNumber() {
    return 1;
}

int nbDisconnectedClient(int *clients[], int nbClient) {
    for (int i = 0, y = 0; i < nbClient; i++) {
        if (*clients[i] == -1)
            y++;
        if (y == nbClient)
            return -1;
    }
    return 1;
}

int serverInit(char* portNb) {
    if (my_portCheck(portNb) == -1) {
        return -1;
    }
    int port = my_atoi(portNb);
    if (port == -1) {
        return -1;
    }

    int socketSrv;
    int client1;
    int client2, client3, client4;
    int nbClient;
    int *clients[] = {&client1, &client2, &client3, &client4};

    socklen_t client_addr_len;
    struct sockaddr_in server;

    fd_set readfs;
    struct timeval tick;

    socketSrv = socket(AF_INET, SOCK_STREAM, 0);
    if (socketSrv < 0) {
        return -1;
    }

    server.sin_port = htons(port);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("0.0.0.0");

    if (bind(socketSrv, (struct sockaddr *) &server, sizeof(server)) < 0) {
        return -1;
    }
    if (listen(socketSrv, 5) < 0) {
        return -1;
    }

    puts("En attente de clients...");
    while (1) {
        puts("En attente de reponse du client hôte...");
        client1 = accept(socketSrv, (struct sockaddr *) &server, &client_addr_len);
        puts("Client hôte connecté.");

        nbClient = 4; // A bind pour choisir le nombre de clients

        for (int i = 1; i < nbClient; i++) {
            *clients[i] = accept(socketSrv, (struct sockaddr *) &server, &client_addr_len);
            puts("Nouveau client connecté.");
            if (i < nbClient) {
                puts("En attente de reponse d'un nouveau client...");
            } else {
                puts("La partie démarre !");
            }
        }

        for (int i = 0; i < nbClient; i++) {
            if (*clients[i] < 0) {
                printf("Le client n°%i n'a pas répondu...", i);
                return -1;
            }
        }

        while (1) {
            tick.tv_sec = 1;
            tick.tv_usec = 0;
            FD_ZERO(&readfs);

            for (int i = 0; i < nbClient; i++) {
                FD_SET(*clients[i], &readfs);
            }

            select(*clients[nbClient - 1] + 1, &readfs, NULL, NULL, &tick);

            for (int i = 0; i < nbClient; i++) {
                if (FD_ISSET(*clients[i], &readfs)) {
                    if (read_client(*clients[i]) == -1) {
                        printf("Client n°%i déconnecté", i);
                        close(*clients[i]);
                        *clients[i] = -1;
                    }
                }
            }

            if (*clients[0] == -1 || nbDisconnectedClient(clients, nbClient) == -1) {
                break;
            }
            puts("tick");
        }
    }
    close(socketSrv);
    return 1;
}
