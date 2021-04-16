/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_joinGame.c
** File description:
**      
*/

#include "../../../include/game.h"

static void my_refreshJoinGame(SDL_Renderer* renderer) {
    my_clearWindows(renderer);
    SDL_Rect buttonBack[2] = {{15, 15, 100, 50 },
                              {40 , 25, 50,  30}};
    SDL_Rect buttonPlay[2] = {{30,  500, 250, 75},
                              {130, 525, 50,  30}};

    my_drawRectangle(renderer, buttonBack[0], 150, 0, 0);
    my_drawRectangle(renderer, buttonPlay[0], 0, 150, 0);

    my_drawText(renderer, buttonBack[1], 0, 0, 0, "Back");
    my_drawText(renderer, buttonPlay[1], 0, 0, 0, "Play");

    SDL_Rect blockPos = {550 , 625 , 50 , 75};
    for (int i = 0; i < 12; i++) {
        my_drawImage(renderer, blockPos , "./library/assets/block/block (75).bmp");
        blockPos.x = blockPos.x - 50;
    }
    SDL_RenderPresent(renderer);
}

int my_joinGame(SDL_Window *window, SDL_Renderer *renderer) {
    TTF_Init();
    SDL_Event event;

    my_refreshJoinGame(renderer);

    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    my_clearWindows(renderer);
                    SDL_RenderPresent(renderer);
                    my_exitWindows(window, renderer);
                    return 0;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.x >= 15 && event.button.x <= 15 + 100 && event.button.y >= 15 &&
                        event.button.y <= 15 + 50) {
                        return 1;
                    } else if (event.button.x >= 30 && event.button.x <= 30 + 250 &&
                               event.button.y >= 500 &&
                               event.button.y <= 500 + 75) {
                        return 5;
                    }
                    break;
            }
        }
    }
    return 0;
}