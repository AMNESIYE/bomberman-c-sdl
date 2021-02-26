/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** keyboard
** File description:
**      keyboard
*/

#include <stdio.h>
#include <SDL2/SDL.h>
#include "../../include/game.h"


SDL_Rect playerDetectionKey(SDL_Event event, SDL_Rect player, SDL_Renderer *render) {
    SDL_Rect bomb;
    switch (event.key.keysym.sym) {
        case SDLK_z:
            //clearPosPlayer(player, render);
            player = verticalPlayerMove(player, render, 'h', bomb);
            break;
        case SDLK_s:
            //clearPosPlayer(player, render);
            player = verticalPlayerMove(player, render, 'b', bomb);
            break;
        case SDLK_q:
            //clearPosPlayer(player, render );
            player = horizontalPlayerMove(player, render, 'g', bomb);
            break;
        case SDLK_d:
            //clearPosPlayer(player, render );
            player = horizontalPlayerMove(player, render, 'd', bomb);
            break;
        case SDLK_SPACE:
            bomb = makeBomb(player , render);
            break;
        default:
            interactDetectionKey(event, render);
    }
    drawBomb(bomb , render);
    return player;
}

void interactDetectionKey(SDL_Event event, SDL_Renderer *render) {
    switch (event.key.keysym.sym) {
        case SDLK_a:
            printf("je pose la bombe");
            break;

    }
}