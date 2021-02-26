/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** Draw
** File description:
**      Draw
*/

#include <stdio.h>
#include <SDL2/SDL.h>
#include "../../include/game.h"



void drawRectangle(SDL_Renderer *render , int Xpos , int Ypos , int Wlength , int Hlength) {
    SDL_Rect rect;
    rect.x = Xpos;
    rect.y = -Ypos + 800;
    rect.w = Wlength;
    rect.h = Hlength;
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    SDL_RenderFillRect(render, &rect);
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderPresent(render);
    return;
}