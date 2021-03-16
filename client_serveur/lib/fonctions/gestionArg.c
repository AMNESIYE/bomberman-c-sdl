/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** gestionArg
** File description:
**      gestionArg
*/

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

void argumentGest(int arrlen, char *arr[]) {
    if (arrlen == 3) {
        if (my_strcmp(arr[1] , "-C") == 0) {
            clientInit(arr[2]);
        } else if (my_strcmp(arr[1] , "-S") == 0) {
            serverInit(arr[2]);
        }
    } else {
        printf("INCORRECT.\nFormat attendu : \"./bomberman -C/-S -numéroDePort\"\n");
    }

}