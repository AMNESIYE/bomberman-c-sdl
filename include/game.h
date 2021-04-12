/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** game.h
** File description:
**      headers for game function
*/


#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int my_createWindows (int sizeX , int sizeY);
int my_exitWindows(SDL_Window* window);
void my_drawRectangle(SDL_Window* window, int posX , int posY , int width , int height , int red , int green , int blue);
void my_drawSquare(SDL_Window* window, int posX , int posY , int width , int red , int green , int blue);
int my_checkColor(int colorNb);
void my_drawImage(SDL_Window* window, int posX , int posY , int width , int height , char* path);
void my_drawText(SDL_Window* window, int posX , int posY , int width , int height , int red , int green , int blue ,char *str);
void my_clearWindows(SDL_Window* window);
int my_mainMenu(SDL_Window* window);
int my_createGame(SDL_Window* window);
int my_playGame(SDL_Window* window);

#endif
