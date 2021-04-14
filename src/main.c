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

int main(int argc, char *argv[])
{
    if (argc == 2 && strcmp(argv[0], "./bomberman") == 0 && strcmp(argv[1], "--serv") == 0) {
        serverInit();
    } else if (argc == 2 && strcmp(argv[0], "./bomberman") == 0 && strcmp(argv[1], "--cli") == 0) {
        clientInit();
    } else if (argc == 1 && strcmp(argv[0], "./bomberman") == 0) {
        my_createWindows(600 , 700);
    } else {
        puts("Main -> Erreur : Paramètres invalides.");
    }
    return 0;
}
