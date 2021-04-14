/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_joinGame.c
** File description:
**      
*/

#include "../../../include/game.h"

void my_initializeJoinGame(SDL_Renderer *renderer) {
    SDL_Log("Main Menu -> Generate button.");
    SDL_Log("Main Menu -> Generate text.");
    my_clearWindows(renderer);
    SDL_Rect buttonBack[2] = {{330, 605, 250, 75},
                              {430, 625, 50,  30}};
    my_drawRectangle(renderer, buttonBack[0], 150, 0, 0);
    my_drawText(renderer, buttonBack[1], 0, 0, 0, "Back");

   


    SDL_RenderPresent(renderer);
}

int my_joinGame(SDL_Window *window, SDL_Renderer *renderer) {
    TTF_Init();
    SDL_Event event;
    my_initializeJoinGame(renderer);

    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    my_clearWindows(renderer);
                    SDL_RenderPresent(renderer);
                    my_exitWindows(window, renderer);
                    return 0;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.x >= 330 && event.button.x <= 330 + 250 && event.button.y >= 605 &&
                        event.button.y <= 605 + 75) {
                        return 1;
                    }
                    break;
            }
        }
    }
    return 0;
}