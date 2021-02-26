/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** game.h
** File description:
**      headers
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct linked_list
{
    unsigned long key;
    //unsigned long data;
    struct linked_list *next;
    //struct linked_list *prev;
} linked_list_t;

int initWindow(int xSize , int ySize);
void drawRectangle(SDL_Renderer *render , int Xpos , int Ypos , int Wlength , int Hlength);
void clearPosPlayer(SDL_Rect player , SDL_Renderer *render);
SDL_Rect horizontalPlayerMove(SDL_Rect player , SDL_Renderer *render , char info, SDL_Rect bomb);
SDL_Rect verticalPlayerMove(SDL_Rect player , SDL_Renderer *render, char info, SDL_Rect bomb);
SDL_Rect drawPlayer(SDL_Rect player , SDL_Renderer *render , SDL_Rect bomb);
SDL_Rect initPlayer(SDL_Rect player);
SDL_Rect playerDetectionKey(SDL_Event event , SDL_Rect player ,SDL_Renderer *render);
void interactDetectionKey(SDL_Event event , SDL_Renderer *render);
SDL_Rect initBomb(SDL_Rect bomb, SDL_Rect player);
SDL_Rect drawBomb(SDL_Rect bomb , SDL_Renderer *render);
void clearPosBomb(SDL_Rect bomb , SDL_Renderer *render);
SDL_Rect makeBomb(SDL_Rect player , SDL_Renderer *render);

#endif
