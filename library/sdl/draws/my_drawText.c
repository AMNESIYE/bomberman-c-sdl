/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_drawText.c
** File description:
**      
*/


#include "../../../include/game.h"

void my_drawText(SDL_Window* window, int posX , int posY , int width , int height , int red , int green , int blue ,char *str) {
    SDL_Surface* surface = NULL;
    surface = SDL_GetWindowSurface(window);
    TTF_Font * font = TTF_OpenFont("./library/assets/text.ttf", 25);
    red = my_checkColor(red);
    green = my_checkColor(green);
    blue = my_checkColor(blue);
    SDL_Color color = { red, green, blue };
    SDL_Surface * text = TTF_RenderText_Solid(font, str , color);
    SDL_Rect rectangle = { posX , posY , width , height};
    SDL_BlitSurface(text, &rectangle , surface, NULL);
    SDL_FreeSurface(surface);
    SDL_FreeSurface(text);
    TTF_CloseFont(font);
    return;
}