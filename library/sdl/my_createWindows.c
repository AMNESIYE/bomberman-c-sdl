/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_createWindows.c
** File description:
**      
*/

#include "../../include/game.h"

int my_createWindows (int sizeX , int sizeY)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        return -1;
    }
    TTF_Init();
    SDL_Window* window = NULL;
    SDL_Surface* surfaceScreen = NULL;
    SDL_Event event;
    window = SDL_CreateWindow( "Bomberman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sizeX, sizeY, 0);
    surfaceScreen = SDL_GetWindowSurface( window );
    SDL_FillRect(surfaceScreen, NULL, SDL_MapRGB(surfaceScreen->format, 255, 255, 255));
    SDL_UpdateWindowSurface(window);
    int run = 1;
    while(run > 0) {
        while(SDL_PollEvent(&event))
        {
            switch (event.type) {
                case SDL_QUIT:
                    my_exitWindows(window);
                    run = 0;
                    return 0;
                    break;
            }
        }
        switch (run) {
            case 0:
                my_exitWindows(window);
                return 0;
                break;
            case 1:
                run = my_mainMenu(window);
                break;
            case 2:
                run = my_playGame(window);
                break;
            case 3:
                run = my_createGame(window);
                break;
        }
        SDL_UpdateWindowSurface(window);
    }

    
    my_exitWindows(window);
    return 0;
}