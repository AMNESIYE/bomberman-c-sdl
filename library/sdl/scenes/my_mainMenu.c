/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_mainMenu.c
** File description:
**      
*/

#include "../../../include/game.h"

int my_mainMenu(SDL_Window* window)
{
    TTF_Init();
    my_clearWindows(window);
    SDL_Event event;
    while (1) {
        while(SDL_PollEvent(&event))
        {
            switch (event.type) {
                case SDL_QUIT:
                    my_exitWindows(window);
                    return 0;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.x >= 150 && event.button.x <= 150 + 300 && event.button.y >= 150 && event.button.y <= 150 + 75) {
                        return 3;
                    }
                    else if (event.button.x >= 150 && event.button.x <= 150 + 300 && event.button.y >= 250 && event.button.y <= 250 + 75) {
                        return 2;
                    }
                    else if (event.button.x >= 150 && event.button.x <= 150 + 300 && event.button.y >= 350 && event.button.y <= 350 + 75) {
                        return 0;
                    }
                    break;
            }
        }
        my_drawRectangle(window , 150 , 150 , 300 , 75 , 0 , 150 , 0);
        my_drawText(window , -265 , -170 , 600 , 700 , 0 , 0 , 0 , "Create");
        my_drawRectangle(window , 150 , 250 , 300 , 75 , 0 , 0 , 150);
        my_drawText(window , -275 , -270 , 600 , 700 , 0 , 0 , 0 , "Join");
        my_drawRectangle(window , 150 , 350 , 300 , 75 , 150 , 0 , 0);
        my_drawText(window , -275 , -370 , 600 , 700 , 0 , 0 , 0 , "Quit");
        SDL_UpdateWindowSurface(window);

    }
    return 0;
}