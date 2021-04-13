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
    SDL_Log("Initialisation réussie.");
    int run = 1;
    while(run > 0) {
        while(SDL_PollEvent(&event))
        {
            switch (event.type) {
                case SDL_QUIT:
                    SDL_Log("Fermeture de la fenêtre.");
                    my_exitWindows(window);
                    run = 0;
                    return 0;
            }
        }
        switch (run) {
            case 0:
                my_exitWindows(window);
                return 0;
            case 1:
                SDL_Log("Choix -> Menu.");
                run = my_mainMenu(window);
                break;
            case 2:
                SDL_Log("Choix -> Join a game.");
                run = my_joinGame(window);
                break;
            case 3:
                SDL_Log("Choix -> Create a game.");
                run = my_createGame(window);
                break;
            case 4:
                SDL_Log("Choix -> Play.");
                run = my_playGame(window);
                break;

        }
        SDL_UpdateWindowSurface(window);
    }

    SDL_Log("SDL -> Fermeture de la fenetre.");
    my_exitWindows(window);
    return 0;
}