/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** bomb
** File description:
**      bomb
*/

#include <stdio.h>
#include <SDL2/SDL.h>
#include "../../include/game.h"

// Récupérer position joueur
SDL_Rect initBomb(SDL_Rect bomb, SDL_Rect player) {
    bomb.x = player.x;
    bomb.y = player.y;
    bomb.w = player.w;
    bomb.h = player.h;
    return bomb;
}

SDL_Rect drawBomb(SDL_Rect bomb , SDL_Renderer *render) {
    SDL_SetRenderDrawColor(render, 0, 0, 255, 255);
    SDL_RenderFillRect(render, &bomb);
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderPresent(render);
    return bomb;
}

void clearPosBomb(SDL_Rect bomb , SDL_Renderer *render) {
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderFillRect(render, &bomb);
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderPresent(render);
}

SDL_Rect makeBomb(SDL_Rect player , SDL_Renderer *render) {
    SDL_Rect bomb;
    bomb =  initBomb(bomb, player);
    bomb = drawBomb(bomb, render);
    return bomb;
}