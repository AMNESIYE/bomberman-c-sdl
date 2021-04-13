/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_drawImage.c
** File description:
**      
*/


#include "./../../include/game.h"

void my_clearWindows(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    return;
}