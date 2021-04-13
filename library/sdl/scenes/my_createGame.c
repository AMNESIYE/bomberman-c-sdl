/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_createGame.c
** File description:
**      
*/

#include "../../../include/game.h"

int my_createGame(SDL_Window *window) {
    TTF_Init();
    my_clearWindows(window);
    SDL_Event event;
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    my_exitWindows(window);
                    return 0;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.x >= 30 && event.button.x <= 30 + 250 && event.button.y >= 605 &&
                        event.button.y <= 605 + 75) {
                        return 4;
                    } else if (event.button.x >= 330 && event.button.x <= 330 + 250 && event.button.y >= 605 &&
                               event.button.y <= 605 + 75){
                        return 1;
                    }
                    break;
            }
        }
        my_drawText(window, 0, 0, 600, 700, 255, 0, 0, "It's createGame Scene");
        //Play button
        my_drawRectangle(window, 30, 605, 250, 75, 0, 0, 150);
        my_drawText(window, -130, -625, 600, 700, 0, 0, 0, "Play");
        my_drawText(window, -130, -625, 600, 700, 0, 0, 0, "Play");
        // Back button
        my_drawRectangle(window, 330, 605, 250, 75, 150, 0, 0);
        my_drawText(window, -430, -625, 600, 700, 0, 0, 0, "Back");
        SDL_UpdateWindowSurface(window);

    }
    return 0;
}