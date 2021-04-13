/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_drawText.c
** File description:
**      
*/


#include "../../../include/game.h"

void my_drawText(SDL_Renderer *renderer, SDL_Rect rectangle, int red, int green, int blue, char* message) {
    TTF_Font* font = TTF_OpenFont("./library/assets/text.ttf", 25);
    SDL_Color color = {red, green, blue, 255};
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = TTF_RenderText_Solid(font, message, color);

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, &rectangle);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    return;
}