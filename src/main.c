/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** main
** File description:
**      main
*/

#include "game.h"
#include "server.h"
#include "client.h"
#include "basical.h"

int main(int argc, char *argv[]) {
    if (argc == 3 && strcmp(argv[0], "./bomberman") == 0 && strcmp(argv[1], "--serv") == 0 &&
        strcmp(argv[2], "2") == 0) {
        serverInit(2);
    } else if (argc == 3 && strcmp(argv[0], "./bomberman") == 0 && strcmp(argv[1], "--serv") == 0 &&
               strcmp(argv[2], "3") == 0) {
        serverInit(3);
    } else if (argc == 3 && strcmp(argv[0], "./bomberman") == 0 && strcmp(argv[1], "--serv") == 0 &&
               strcmp(argv[2], "4") == 0) {
        serverInit(4);
    } else if (argc == 1 && strcmp(argv[0], "./bomberman") == 0) {
        my_createWindows(600, 700);
    } else
        puts("Main -> Erreur : Paramètres invalides.");
    return 0;
}
