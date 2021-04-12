/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_drawImage.c
** File description:
**      
*/


#include "../../../include/game.h"

void my_drawImage(SDL_Window* window, int posX , int posY , int width , int height , char* path) {
    SDL_Surface* surface = NULL;
    surface = SDL_GetWindowSurface(window);
    SDL_Surface* img = SDL_LoadBMP(path);
    SDL_Rect rectangle = { posX , posY , width , height};
    SDL_BlitSurface(img, &rectangle , surface, NULL);
    SDL_FreeSurface(img);
    SDL_FreeSurface(surface);
    return;
}