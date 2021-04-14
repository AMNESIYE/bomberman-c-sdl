/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_mainMenu.c
** File description:
**      
*/

#include "../../../include/game.h"

void my_initializeMainMenu(SDL_Renderer *renderer) {
    SDL_Log("Main Menu -> Generate button.");
    SDL_Log("Main Menu -> Generate text.");
    SDL_Log("Main Menu -> Generate image");
    my_clearWindows(renderer);

    //drawImage
    SDL_Rect image[2] = {{400, 400, 150, 200}, {0, 0, 600, 150}};
    my_drawImage(renderer, image[0] , "./library/assets/logo.bmp");
    my_drawImage(renderer, image[1] , "./library/assets/title.bmp");


    SDL_Rect blockPos = {550 , 625 , 50 , 75};
    for (int i = 0; i < 12; i++) {
        my_drawImage(renderer, blockPos , "./library/assets/block/block (75).bmp");
        blockPos.x = blockPos.x - 50;
    }
    //drawRectangle
    SDL_Rect rect[3] = {{50, 250, 250, 75},
                        {50, 350, 250, 75},
                        {50, 450, 250, 75}};
    my_drawRectangle(renderer, rect[0], 0, 150, 0);
    my_drawRectangle(renderer, rect[1], 0, 0, 150);
    my_drawRectangle(renderer, rect[2], 150, 0, 0);

    //drawText
    SDL_Rect text[3] = {{140, 270, 70, 30},
                        {150, 370, 50, 30},
                        {150, 470, 50, 30}};
    my_drawText(renderer, text[0], 0, 0, 0, "Create");
    my_drawText(renderer, text[1], 0, 0, 0, "Join");
    my_drawText(renderer, text[2], 0, 0, 0, "Quit");

    SDL_RenderPresent(renderer);
}

int my_mainMenu(SDL_Window *window, SDL_Renderer *renderer) {
    TTF_Init();
    SDL_Event event;
    my_initializeMainMenu(renderer);
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    my_clearWindows(renderer);
                    SDL_RenderPresent(renderer);
                    my_exitWindows(window, renderer);
                    return 0;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.x >= 50 && event.button.x <= 50 + 250 && event.button.y >= 250 &&
                        event.button.y <= 250 + 75) {
                        my_clearWindows(renderer);
                        SDL_RenderPresent(renderer);
                        return 3;
                    } else if (event.button.x >= 50 && event.button.x <= 150 + 250 && event.button.y >= 350 &&
                               event.button.y <= 350 + 75) {
                        my_clearWindows(renderer);
                        SDL_RenderPresent(renderer);
                        return 2;
                    } else if (event.button.x >= 50 && event.button.x <= 150 + 250 && event.button.y >= 450 &&
                               event.button.y <= 450 + 75) {
                        my_clearWindows(renderer);
                        SDL_RenderPresent(renderer);
                        return 0;
                    }
                    break;
            }
        }
    }
    return 0;
}