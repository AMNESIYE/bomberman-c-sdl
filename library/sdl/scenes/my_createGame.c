/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_createGame.c
** File description:
**      
*/

#include "../../../include/game.h"

void my_refreshCreateGame(SDL_Renderer* renderer, SDL_Rect buttonBack[], SDL_Rect buttonPlay[], SDL_Rect buttonServer[], int colorPlay[]) {
    my_clearWindows(renderer);
    my_drawRectangle(renderer, buttonBack[0], 150, 0, 0);
    my_drawRectangle(renderer, buttonPlay[0], colorPlay[0], colorPlay[1], colorPlay[2]);
    my_drawRectangle(renderer, buttonServer[0], 240, 240, 240);

    my_drawText(renderer, buttonBack[1], 0, 0, 0, "Back");
    my_drawText(renderer, buttonPlay[1], 0, 0, 0, "Play");
    my_drawText(renderer, buttonServer[1], 0, 0, 0, "Serv");
    SDL_RenderPresent(renderer);
}

int my_createGame(SDL_Window *window, SDL_Renderer *renderer) {
    TTF_Init();
    SDL_Event event;

    int colorPlay[3] = {169, 169, 169};

    SDL_Rect buttonBack[2] = {{330, 605, 250, 75},
                              {430, 625, 50,  30}};
    SDL_Rect buttonPlay[2] = {{30,  605, 250, 75},
                              {130, 625, 50,  30}};
    SDL_Rect buttonServer[2] = {{330, 305, 250, 75},
                                {430, 325, 50,  30}};
    my_refreshCreateGame(renderer, buttonBack, buttonPlay, buttonServer, colorPlay);

    int serverInitialized = 0;

    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    my_exitWindows(window, renderer);
                    return 0;
                case SDL_MOUSEBUTTONDOWN:
                    if (serverInitialized == 1 && event.button.x >= 30 && event.button.x <= 30 + 250 &&
                        event.button.y >= 605 &&
                        event.button.y <= 605 + 75) {
                        return 4;
                    } else if (event.button.x >= 330 && event.button.x <= 330 + 250 && event.button.y >= 605 &&
                               event.button.y <= 605 + 75) {
                        return 1;
                    } else if (event.button.x >= 330 && event.button.x <= 330 + 250 &&
                               event.button.y >= 305 &&
                               event.button.y <= 305 + 75) {
                        colorPlay[0] = 0;
                        colorPlay[1] = 150;
                        colorPlay[2] = 0;
                        serverInitialized++;
                        system("gnome-terminal -- ./bomberman --serv");
                        my_refreshCreateGame(renderer, buttonBack, buttonPlay, buttonServer, colorPlay);
                    }
                    break;
            }
        }
    }
    return 0;
}