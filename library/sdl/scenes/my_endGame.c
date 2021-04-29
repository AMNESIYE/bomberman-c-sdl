/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_mainMenu.c
** File description:
**      
*/

#include "../../../include/game.h"
#include "../../../include/basical.h"

static void my_refreshWinGame(SDL_Renderer* renderer, int result) {
    my_clearWindows(renderer);
    SDL_Rect blockPos = {90 , 125 , 400 , 400};
    SDL_Rect menuBut = {230 , 600 , 50 , 50};
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, menuBut , "./library/assets/block/block (32).bmp");
        menuBut.x = menuBut.x - 50;
    }
    menuBut.x = 230;
    menuBut.y = menuBut.y  + 25;
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, menuBut , "./library/assets/block/block (32).bmp");
        menuBut.x = menuBut.x - 50;
    }
    //quit button
    SDL_Rect quitBut = {530 , 600 , 50 , 50};
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, quitBut , "./library/assets/block/block (31).bmp");
        quitBut.x = quitBut.x - 50;
    }
    quitBut.x = 530;
    quitBut.y = quitBut.y + 25;
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, quitBut , "./library/assets/block/block (31).bmp");
        quitBut.x = quitBut.x - 50;
    }

    SDL_Rect buttonQuit = {430 , 600, 50,  50};
    SDL_Rect buttonMenu = {100, 600, 120,  50};
    my_drawText(renderer, buttonMenu , 0, 0, 0, "Main Menu");
    my_drawText(renderer, buttonQuit , 0, 0, 0, "Quit");

    if (result == 1) {
        my_drawImage(renderer, blockPos , "./library/assets/win.bmp");
    } else {
        my_drawImage(renderer, blockPos , "./library/assets/lose.bmp");
    }
    SDL_RenderPresent(renderer);
}

int my_endGame(SDL_Window *window, SDL_Renderer *renderer, int result) {
    TTF_Init();
    SDL_Event event;
    my_refreshWinGame(renderer, result);
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    my_clearWindows(renderer);
                    SDL_RenderPresent(renderer);
                    my_exitWindows(window, renderer);
                    return 0;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.x >= 30 && event.button.x <= 30 + 250 && event.button.y >= 600 && event.button.y <= 600 + 75) {
                        return 1;
                    }
                    if (event.button.x >= 330 && event.button.x <= 330 + 250 && event.button.y >= 600 && event.button.y <= 600 + 75) {
                        my_clearWindows(renderer);
                        SDL_RenderPresent(renderer);
                        my_exitWindows(window, renderer);
                    }
            }
        }
    }
    return 0;
}