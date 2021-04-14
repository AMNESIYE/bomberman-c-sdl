/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_exitWindows.c
** File description:
**      
*/

#include "../../include/game.h"

int my_exitWindows(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_Log("SDL -> Closing window.");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    SDL_Quit();
    return 0;
}