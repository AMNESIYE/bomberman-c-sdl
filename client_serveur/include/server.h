/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** server.h
** File description:
**      headers
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <sys/socket.h>
#include <arpa/inet.h>


void clientInit();
int validatePort(char *portNb);
int serverInit(char *portNb);

#endif
