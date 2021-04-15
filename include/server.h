/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** server.h
** File description:
**      headers for server functions 
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
#include <string.h>

enum _requestType {
    CLIENT_ID,
    GET_PLAYER_1
};

int serverInit(int numberPlayers);
int clientInit();


#endif
