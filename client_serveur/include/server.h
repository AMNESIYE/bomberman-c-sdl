/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** server.h
** File description:
**      headers
*/

#ifndef MY_H_
#define MY_H_
#define BUFFER_SIZE 128

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>

int clientInit(char *portNb);
int validatePort(char *portNb);
int serverInit(char *portNb);
void argumentGest(int arrLen, char *arr[]);
int my_atoi(char *str);


void exit_SDL(SDL_Window *win , SDL_Renderer *render);
int init_SDL(int sizeX , int sizeY);

#endif
