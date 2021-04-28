/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_mainMenu.c
** File description:
**      
*/

#include "../../../include/game.h"
#include "../../../include/basical.h"

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
    //quit//
    SDL_Rect quitPos = {250, 450 , 50, 50};
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, quitPos , "./library/assets/block/block (31).bmp");
        quitPos.x = quitPos.x - 50;
    }
    quitPos.x = 250;
    quitPos.y = quitPos.y + 25;
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, quitPos , "./library/assets/block/block (31).bmp");
        quitPos.x = quitPos.x - 50;
    }
    //join//
    SDL_Rect joinPos = {250, 350 , 50, 50};
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, joinPos , "./library/assets/block/block (30).bmp");
        joinPos.x = joinPos.x - 50;
    }
    joinPos.x = 250;
    joinPos.y = joinPos.y + 25;
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, joinPos , "./library/assets/block/block (30).bmp");
        joinPos.x = joinPos.x - 50;
    }
    //create
    SDL_Rect createPos = {250, 250 , 50, 50};
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, createPos , "./library/assets/block/block (32).bmp");
        createPos.x = createPos.x - 50;
    }
    createPos.x = 250;
    createPos.y = createPos.y + 25;
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, createPos , "./library/assets/block/block (32).bmp");
        createPos.x = createPos.x - 50;
    }
    

    //drawText
    SDL_Rect text[3] = {{140, 260, 70, 30},
                        {150, 360, 50, 30},
                        {150, 460, 50, 30}};
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