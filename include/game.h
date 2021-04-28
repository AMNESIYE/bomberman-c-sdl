/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** game.h
** File description:
**      headers for game function
*/


#ifndef MY_H_GAME
#define MY_H_GAME

#define FPS 60

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_thread.h>


int my_createWindows(int sizeX, int sizeY);

int my_exitWindows(SDL_Window *window, SDL_Renderer *renderer);

void my_drawRectangle(SDL_Renderer *renderer, SDL_Rect rectangle, int red, int green, int blue);

void my_drawSquare(SDL_Window *window, int posX, int posY, int width, int red, int green, int blue);

int my_checkColor(int colorNb);

void my_drawImage(SDL_Renderer *renderer, SDL_Rect image, char *path);

void my_drawText(SDL_Renderer *renderer, SDL_Rect rectangle, int red, int green, int blue, char *message);

void my_drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2, int red, int green, int blue);

void my_clearWindows(SDL_Renderer *renderer);

int my_mainMenu(SDL_Window *window, SDL_Renderer *renderer);

int my_createGame(SDL_Window *window, SDL_Renderer *renderer);

int my_joinGame(SDL_Window *window, SDL_Renderer *renderer , char *ip);

int my_playGameClient(SDL_Window *window, SDL_Renderer *renderer, char* name , char* ip);

#endif
