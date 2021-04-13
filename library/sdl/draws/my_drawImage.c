/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_drawImage.c
** File description:
**      
*/


#include "../../../include/game.h"

void my_drawImage(SDL_Renderer *renderer, SDL_Rect image, char* path) {
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = SDL_LoadBMP(path);

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, &image);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    return;
}