/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** checkPort
** File description:
**      checkPort
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <sys/socket.h>
#include <arpa/inet.h>


int my_atoi(char *str)
{
    int res = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i]> '9' || str[i]<'0')
            return -1;
        res = res*10 + str[i] - '0';
    }
    return res;
}

int validatePort(char *portNb) {
    int portNumber = my_atoi(portNb);
    if (portNumber < 0)
        return -1;
    else {
        if (portNumber > 0 && portNumber < 65536)
            return 1;
        else
            return -1;
    }
}

