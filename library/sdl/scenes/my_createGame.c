/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_createGame.c
** File description:
**      
*/

#include "../../../include/game.h"

void my_initializeCreateGame(SDL_Renderer
                             *renderer) {
    my_clearWindows(renderer);
    SDL_Rect buttonBack[2] = {{330, 605, 250, 75},
                              {430, 625, 50,  30}};
    SDL_Rect buttonPlay[2] = {{30, 605, 250, 75},
                              {130, 625, 50,  30}};

    // Button Back
    my_drawRectangle(renderer, buttonBack[0], 150, 0, 0);
    my_drawRectangle(renderer, buttonPlay[0], 0, 150, 0);
    my_drawText(renderer, buttonBack[1], 0, 0, 0, "Back");
    my_drawText(renderer, buttonPlay[1], 0, 0, 0, "Play");

    SDL_RenderPresent(renderer);
}

int my_createGame(SDL_Window *window, SDL_Renderer *renderer) {
    TTF_Init();
    my_clearWindows(renderer);
    SDL_Event event;
    my_initializeCreateGame(renderer);
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    my_exitWindows(window, renderer);
                    return 0;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.x >= 30 && event.button.x <= 30 + 250 && event.button.y >= 605 &&
                        event.button.y <= 605 + 75) {
                        return 4;
                    } else if (event.button.x >= 330 && event.button.x <= 330 + 250 && event.button.y >= 605 &&
                               event.button.y <= 605 + 75) {
                        return 1;
                    }
                    break;
            }
        }
    }
    return 0;
}