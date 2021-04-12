/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_drawSquare.c
** File description:
**      
*/


#include "../../../include/game.h"

void my_drawSquare(SDL_Window* window, int posX , int posY , int width , int red , int green , int blue) {
    SDL_Surface* surface = NULL;
    surface = SDL_GetWindowSurface( window );
    SDL_Rect square = { posX , posY , width , width};
    red = my_checkColor(red);
    green = my_checkColor(green);
    blue = my_checkColor(blue);
    SDL_FillRect(surface , &square , SDL_MapRGB(surface->format, red, green, blue));
    SDL_FreeSurface(surface);
    return;
}

