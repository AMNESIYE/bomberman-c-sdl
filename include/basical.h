/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** basical.h
** File description:
**      headers for basical functions
*/


#ifndef MY_H_BASICAL
#define MY_H_BASICAL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "objects.h"

int my_atoi(char *str);

int my_portCheck(char *portNb);

void my_genMap(char *path, struct wall w[]);


#endif
