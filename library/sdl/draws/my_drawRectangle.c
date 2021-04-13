/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_drawRectangle.c
** File description:
**      
*/


#include "../../../include/game.h"

void my_drawRectangle(SDL_Renderer *renderer, SDL_Rect rectangle, int red , int green , int blue) {
    SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
    SDL_RenderFillRect(renderer, &rectangle);
}