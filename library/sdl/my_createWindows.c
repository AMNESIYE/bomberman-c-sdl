/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_createWindows.c
** File description:
**      
*/

#include "../../include/game.h"

int my_createWindows(int sizeX, int sizeY) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return -1;
    }
    TTF_Init();
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event event;
    SDL_CreateWindowAndRenderer(sizeX, sizeY, SDL_WINDOW_SHOWN, &window, &renderer);
    SDL_Log("SDL -> Initialization successfull.");
    int run = 1;
    while (run) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    my_clearWindows(renderer);
                    SDL_RenderPresent(renderer);
                    my_exitWindows(window, renderer);
                    return 0;
            }
        }
        switch (run) {
            case 0:
                my_exitWindows(window, renderer);
                return 0;
            case 1:
                SDL_Log("Redirection -> Menu.");
                run = my_mainMenu(window, renderer);
                break;
            case 2:
                SDL_Log("Redirection -> Join a game.");
                run = my_joinGame(window, renderer);
                break;
            case 3:
                SDL_Log("Redirection -> Create a game.");
                run = my_createGame(window, renderer);
                break;
            case 4:
                SDL_Log("Redirection -> Play.");
                run = my_playGame(window, renderer);
                break;

        }
        SDL_UpdateWindowSurface(window);
    }
    my_exitWindows(window, renderer);
    return 0;
}