/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_drawRectangle.c
** File description:
**      
*/


#include "../../../include/game.h"

void my_drawRectangle(SDL_Window* window, int posX , int posY , int width , int height , int red , int green , int blue) {
    SDL_Surface* surface = NULL;
    surface = SDL_GetWindowSurface(window);
    SDL_Rect rectangle = { posX , posY , width , height};
    red = my_checkColor(red);
    green = my_checkColor(green);
    blue = my_checkColor(blue);
    SDL_FillRect(surface , &rectangle , SDL_MapRGB(surface->format, red, green, blue));
    SDL_FreeSurface(surface);
    return;
}