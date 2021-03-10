/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** gestionArg
** File description:
**      gestionArg
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "../../include/server.h"


int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;
	while (s1[i] != '\0') {
		if (s1[i] != s2[i])
			return (s2[i] - s1[i]);
		i = i + 1;
	}
	return (0);
}

void argumentGest(int arrLen , char *arr[]) {
    int res;
    if (my_strcmp(arr[1] , "-C") == 0) {
        res = clientInit(arr[3] , arr[2]);
        printf("%i" , res);
    } else if (my_strcmp(arr[1] , "-S") == 0) {
        res = serverInit(arr[2]);
        printf("%i" , res);
    }
}