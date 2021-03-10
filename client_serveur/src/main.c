/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** main
** File description:
**      main
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "server.h"

int main()
{
    int res = serverInit("1234");
    printf("%i" , res);
    return 0;
}
