/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_drawImage.c
** File description:
**      
*/


#include "./../../include/game.h"

void my_clearWindows(SDL_Window* window) {
    SDL_Surface* surfaceScreen = SDL_GetWindowSurface( window );
    SDL_FillRect(surfaceScreen, NULL, SDL_MapRGB(surfaceScreen->format, 255, 255, 255));  
    return; 
}