/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** keyboard
** File description:
**      keyboard
*/ 

#include <stdio.h>
#include <SDL2/SDL.h>
#include "../../include/game.h"



SDL_Rect playerDetectionKey(SDL_Event event , SDL_Rect player, SDL_Renderer *render) {
    switch (event.key.keysym.sym) {
        case SDLK_z:
            player = verticalPlayerMove(player , render , 'h');
            break;
        case SDLK_s:
            player = verticalPlayerMove(player , render, 'b');
            break;
        case SDLK_q:
            player = horizontalPlayerMove(player , render, 'g');
            break;
        case SDLK_d:
            player = horizontalPlayerMove(player , render , 'd');
            break;
        default:
            interactDetectionKey(event , render);
        }
    return player;
}

void interactDetectionKey(SDL_Event event , SDL_Renderer *render) {
    switch (event.key.keysym.sym) {
        case SDLK_a:
            printf("je pose la bombe");
            break;
    
        }
}