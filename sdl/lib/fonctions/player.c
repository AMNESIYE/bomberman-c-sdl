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
    player.x = 80;
    player.y = 80;
    player.w = 40;
    player.h = 40;
    return player;
}

SDL_Rect drawPlayer(SDL_Rect player , SDL_Renderer *render , SDL_Rect bomb) {
    SDL_SetRenderDrawColor(render, 255, 0, 255, 255);
    SDL_RenderFillRect(render, &player);
    SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
    SDL_RenderPresent(render);
    return player;
}

SDL_Rect verticalPlayerMove(SDL_Rect player , SDL_Renderer *render , char info, SDL_Rect bomb) {
    clearPosPlayer(player , render);
    int posPlayerY =  player.y;
    if (info == 'h' && player.y - bomb.y < 40) {
        player.y = (posPlayerY - 40);
    }
    else if (player.y - bomb.y < 40){
        player.y = (posPlayerY + 40);
    }
    player = drawPlayer(player , render , bomb);
    return player;
}

SDL_Rect horizontalPlayerMove(SDL_Rect player , SDL_Renderer *render , char info, SDL_Rect bomb) {
    clearPosPlayer(player , render);
    int posPlayerX =  player.x;
    if (info == 'g') {
        player.x = (posPlayerX - 40);
    }
    else {
        player.x = (posPlayerX + 40);
    }
    player = drawPlayer(player , render , bomb);
    return player;
}

void clearPosPlayer(SDL_Rect player , SDL_Renderer *render) {
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderFillRect(render, &player);
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderPresent(render);
}