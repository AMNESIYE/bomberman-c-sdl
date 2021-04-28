/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** client.h
** File description:
**      headers for client functions
*/


#ifndef MY_H_CLIENT
#define MY_H_CLIENT

#define BUFFER_SIZE 1024
#define PORT 25565

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>
#include <pthread.h>

int my_requestMapToServer(struct wall wallTable[], char *bufferC, char *bufferS, int socketCli, char *request, int start, int end);


#endif
