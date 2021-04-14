/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_drawLine.c
** File description:
**
*/


#include "../../../include/game.h"

void my_drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2, int red, int green, int blue) {
    SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}