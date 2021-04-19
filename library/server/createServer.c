/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** CreateServer
** File description:
**      createServer
*/

#include "../../include/server.h"
#include "../../include/basical.h"
#include "../../include/objects.h"

int write_client(int client, char *bufferS) {
    if (send(client, bufferS, strlen(bufferS), 0) >= 0) {
        printf("\tEnvoyé: %s", bufferS);
        memset(bufferS, '\0', BUFFER_SIZE);
        return 1;
    } else {
        puts("\tLe retour d'envoi a échoué.");
        return -1;
    }
}

int ask_Map(char *bufferC) {
    switch (bufferC[3]) {
        case '1':
            switch (bufferC[4]) {
                case '0':
                    return 9;
                case '1':
                    return 10;
                case '2':
                    return 11;
                case '3':
                    return 12;
                case '4':
                    return 13;
                case '5':
                    return 14;
                default:
                    return 0;
            }
        case '2':
            return 1;
        case '3':
            return 2;
        case '4':
            return 3;
        case '5':
            return 4;
        case '6':
            return 5;
        case '7':
            return 6;
        case '8':
            return 7;
        case '9':
            return 8;
        default:
            return -1;
    }
}

static char *ask_DB(char *bufferC, struct character charTable[], struct wall walls[], int client) {
    if (strcmp(bufferC, "CLIENT_ID\n") == 0) {
        char str[12];
        sprintf(str, "%d", client);
        strcpy(bufferC, strcat(str, "\n"));
    } else if (strcmp(bufferC, "P1x\n") == 0) {
        char str[12];
        sprintf(str, "%d", charTable[0].hitbox.x);
        strcpy(bufferC, strcat(str, "\n"));
    } else if (strcmp(bufferC, "P1y\n") == 0) {
        char str[12];
        sprintf(str, "%d", charTable[0].hitbox.y);
        strcpy(bufferC, strcat(str, "\n"));
    } else if (strcmp(bufferC, "P2x\n") == 0) {
        char str[12];
        sprintf(str, "%d", charTable[1].hitbox.x);
        strcpy(bufferC, strcat(str, "\n"));
    } else if (strcmp(bufferC, "P2y\n") == 0) {
        char str[12];
        sprintf(str, "%d", charTable[1].hitbox.y);
        strcpy(bufferC, strcat(str, "\n"));
    } else if (strcmp(bufferC, "UP\n") == 0) {
        for (int i = 0; charTable[i].hitbox.w == 40; i++) {
            if (charTable[i].client.clientID == client) {
                if (my_checkCollision(charTable[i], walls, 'u') == 0)
                    charTable[i].hitbox.y -= 40;
            }
        }
    } else if (strcmp(bufferC, "RIGHT\n") == 0) {
        for (int i = 0; charTable[i].hitbox.w == 40; i++) {
            if (charTable[i].client.clientID == client) {
                if (my_checkCollision(charTable[i], walls, 'r') == 0)
                    charTable[i].hitbox.x += 40;
            }
        }
    } else if (strcmp(bufferC, "DOWN\n") == 0) {
        for (int i = 0; charTable[i].hitbox.w == 40; i++) {
            if (charTable[i].client.clientID == client) {
                if (my_checkCollision(charTable[i], walls, 'd') == 0)
                    charTable[i].hitbox.y += 40;
            }
        }
    } else if (strcmp(bufferC, "LEFT\n") == 0) {
        for (int i = 0; charTable[i].hitbox.w == 40; i++) {
            if (charTable[i].client.clientID == client) {
                if (my_checkCollision(charTable[i], walls, 'l') == 0)
                    charTable[i].hitbox.x -= 40;
            }
        }
    } else if (strncmp(bufferC, "MAP", 3) == 0) {
        char bufferT[BUFFER_SIZE];
        memset(bufferT, '\0', BUFFER_SIZE);
        int range = ask_Map(bufferC);
        if (range == -1) {
            write_client(client, bufferC);
            return bufferC;
        }
        for (int i = range * 15; i < range * 15 + 15; i++) {
            char str[12];
            sprintf(str, "%d", walls[i].breakable);
            strcpy(bufferT, strcat(bufferT, str));
        }
        strcpy(bufferC, strcat(bufferT, "\n"));
    }
    write_client(client, bufferC);
    return bufferC;
}

int read_client(int client, struct character charTable[], struct wall walls[]) {
    int n;
    char bufferC[BUFFER_SIZE];

    if (client == -1) {
        return 1;
    }

    n = 0;
    memset(bufferC, '\0', BUFFER_SIZE);

    while ((n = recv(client, bufferC, BUFFER_SIZE, MSG_DONTWAIT)) >= 0) {
        if (n == 0) {
            return -1;
        }
        printf("\tReçu: %s", bufferC);

        strcpy(bufferC, ask_DB(bufferC, charTable, walls, client));

        if (bufferC[n - 1] == '\n') {
            memset(bufferC, '\0', BUFFER_SIZE);
            break;
        }
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

int serverInit(int numberPlayers) {
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

    server.sin_port = htons(PORT);
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

        struct character charTable[] = {my_initCharacter(MY_CHARACTER), my_initCharacter(ENEMY_CHARACTER),
                                        my_initCharacter(BLANK_CHARACTER), my_initCharacter(BLANK_CHARACTER)};
        struct character *charTableI = charTable;

        nbClient = numberPlayers; // A bind pour choisir le nombre de clients
        charTableI[0].client.clientID = client1;

        for (int i = 1; i < nbClient; i++) {
            *clients[i] = accept(socketSrv, (struct sockaddr *) &server, &client_addr_len);
            puts("Nouveau client connecté.");
            charTableI[i].client.clientID = *clients[i];
            if (i < nbClient) {
                puts("En attente de reponse d'un nouveau client...");
            } else {
                puts("La partie démarre !");
            }
        }

        my_initializeCharactersPosition(charTableI);

        for (int i = 0; i < nbClient; i++) {
            if (*clients[i] < 0) {
                printf("Le client n°%i n'a pas répondu...", i);
                return -1;
            }
        }

        struct wall wallTable[225];
        struct wall *wallTableI = wallTable;
        my_genMap("./library/assets/maps/map.txt", wallTableI);

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
                    if (read_client(*clients[i], charTableI, wallTableI) == -1) {
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