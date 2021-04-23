/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_joinGame.c
** File description:
**      
*/

#include "../../../include/game.h"

static void my_refreshJoinGame(SDL_Renderer* renderer) {
    my_clearWindows(renderer);
    SDL_Rect buttonBack = {430 , 525, 50,  30};
    SDL_Rect buttonPlay = {130, 525, 50,  30};    
    SDL_Rect playPos = {230 , 500 , 50 , 75};
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, playPos , "./library/assets/block/block (32).bmp");
        playPos.x = playPos.x - 50;
    }
    SDL_Rect backPos = {530 , 500 , 50 , 75};
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, backPos , "./library/assets/block/block (30).bmp");
        backPos.x = backPos.x - 50;
    }

    SDL_Rect blockPos = {550 , 625 , 50 , 75};
    for (int i = 0; i < 12; i++) {
        my_drawImage(renderer, blockPos , "./library/assets/block/block (75).bmp");
        blockPos.x = blockPos.x - 50;
    }
    my_drawText(renderer, buttonBack , 0, 0, 0, "Back");
    my_drawText(renderer, buttonPlay , 0, 0, 0, "Play");
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
                    if (event.button.x >= 280 && event.button.x <= 280 + 250 && event.button.y >= 500 &&
                        event.button.y <= 500 + 75) {
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