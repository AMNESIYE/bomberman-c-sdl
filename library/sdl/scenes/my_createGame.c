/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_createGame.c
** File description:
**      
*/

#include "../../../include/game.h"

//block (74).bmp

void my_refreshCreateGame(SDL_Renderer *renderer) {
    SDL_Rect blockPos = {550 , 625 , 50 , 75};
    for (int i = 0; i < 12; i++) {
        my_drawImage(renderer, blockPos , "./library/assets/block/block (75).bmp");
        blockPos.x = blockPos.x - 50;
    }
    SDL_Rect backButtonPos = {515, 525 , 50, 50};
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, backButtonPos , "./library/assets/block/block (31).bmp");
        backButtonPos.x = backButtonPos.x - 50;
    }
    backButtonPos.x = 515;
    backButtonPos.y = backButtonPos.y + 25;
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, backButtonPos , "./library/assets/block/block (31).bmp");
        backButtonPos.x = backButtonPos.x - 50;
    }
    SDL_Rect twoPlayButtonPos = {235, 525 , 50, 50};
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, twoPlayButtonPos , "./library/assets/block/block (30).bmp");
        twoPlayButtonPos.x = twoPlayButtonPos.x - 50;
    }
    twoPlayButtonPos.x = 235;
    twoPlayButtonPos.y = twoPlayButtonPos.y + 25;
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, twoPlayButtonPos , "./library/assets/block/block (30).bmp");
        twoPlayButtonPos.x = twoPlayButtonPos.x - 50;
    }
    SDL_Rect threePlayButtonPos = {235, 425 , 50, 50};
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, threePlayButtonPos , "./library/assets/block/block (30).bmp");
        threePlayButtonPos.x = threePlayButtonPos.x - 50;
    }
    threePlayButtonPos.x = 235;
    threePlayButtonPos.y = threePlayButtonPos.y + 25;
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, threePlayButtonPos , "./library/assets/block/block (30).bmp");
        threePlayButtonPos.x = threePlayButtonPos.x - 50;
    }
    SDL_Rect fourPlayButtonPos = {235, 325 , 50, 50};
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, fourPlayButtonPos , "./library/assets/block/block (30).bmp");
        fourPlayButtonPos.x = fourPlayButtonPos.x - 50;
    }
    fourPlayButtonPos.x = 235;
    fourPlayButtonPos.y = fourPlayButtonPos.y + 25;
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, fourPlayButtonPos , "./library/assets/block/block (30).bmp");
        fourPlayButtonPos.x = fourPlayButtonPos.x - 50;
    }
    SDL_Rect textPos[4] = {{}

                          };
    SDL_RenderPresent(renderer);
}

int my_createGame(SDL_Window *window, SDL_Renderer *renderer) {
    TTF_Init();
    SDL_Event event;
    my_refreshCreateGame(renderer);

    int serverInitialized = 0;
    //system("gnome-terminal -- ./bomberman --serv 2");
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    my_exitWindows(window, renderer);
                    return 0;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.x >= 315 && event.button.x <= 315 + 250 && event.button.y >= 525 && event.button.y <= 525 + 75) {
                        return 1;
                    }
                    else if (event.button.x >= 35 && event.button.x <= 35 + 250 && event.button.y >= 525 && event.button.y <= 525 + 75) {
                        system("gnome-terminal -- ./bomberman --serv 2");
                        return 4;
                    }
                    else if (event.button.x >= 35 && event.button.x <= 35 + 250 && event.button.y >= 425 && event.button.y <= 425 + 75) {
                        system("gnome-terminal -- ./bomberman --serv 3");
                        return 4;
                    }
                    else if (event.button.x >= 35 && event.button.x <= 35 + 250 && event.button.y >= 325 && event.button.y <= 325 + 75) {
                        system("gnome-terminal -- ./bomberman --serv 4");
                        return 4;
                    }
                    break;
            }
        }
    }
    return 0;
}