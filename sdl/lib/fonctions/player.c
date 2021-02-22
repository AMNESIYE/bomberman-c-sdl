/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** player
** File description:
**      player
*/

#include <stdio.h>
#include <SDL2/SDL.h>
#include "../../include/game.h"


SDL_Rect initPlayer(SDL_Rect player) {
    player.x = 100;
    player.y = 100;
    player.w = 50;
    player.h = 50;
    return player;
}

SDL_Rect drawPlayer(SDL_Rect player , SDL_Renderer *render) {
    SDL_SetRenderDrawColor(render, 255, 0, 255, 255);
    SDL_RenderFillRect(render, &player);
    SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
    SDL_RenderPresent(render);
    return player;
}

SDL_Rect verticalPlayerMove(SDL_Rect player , SDL_Renderer *render , char info) {
    clearPosPlayer(player , render);
    int posPlayerY =  player.y;
    if (info == 'h') {
        player.y = (posPlayerY - 25);
    }
    else {
        player.y = (posPlayerY + 25);
    }
    player = drawPlayer(player , render);
    return player;
}

SDL_Rect horizontalPlayerMove(SDL_Rect player , SDL_Renderer *render , char info) {
    clearPosPlayer(player , render);
    int posPlayerX =  player.x;
    if (info == 'g') {
        player.x = (posPlayerX - 25);
    }
    else {
        player.x = (posPlayerX + 25);
    }
    player = drawPlayer(player , render);
    return player;
}

void clearPosPlayer(SDL_Rect player , SDL_Renderer *render) {
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderFillRect(render, &player);
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderPresent(render);
}