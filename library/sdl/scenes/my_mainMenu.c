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
                    if (event.button.x >= 250 && event.button.x <= 500 && event.button.y >= 150 && event.button.y <= 225) {
                        return 2;
                    }
                    else if (event.button.x >= 250 && event.button.x <= 500 && event.button.y >= 250 && event.button.y <= 325) {
                        return 3;
                    }
                    else if (event.button.x >= 250 && event.button.x <= 500 && event.button.y >= 350 && event.button.y <= 425) {
                        return 0;
                    }
                    break;
            }
        }
        my_drawRectangle(window , 250 , 150 , 250 , 75 , 0 , 150 , 0);
        my_drawText(window , -340 , -170 , 800 , 600 , 0 , 0 , 0 , "Jouer");
        my_drawRectangle(window , 250 , 250 , 250 , 75 , 0 , 0 , 150);
        my_drawText(window , -320 , -270 , 800 , 600 , 0 , 0 , 0 , "Rejoindre");
        my_drawRectangle(window , 250 , 350 , 250 , 75 , 150 , 0 , 0);
        my_drawText(window , -330 , -370 , 800 , 600 , 0 , 0 , 0 , "Quitter");
        SDL_UpdateWindowSurface(window);

    }
    return 0;
}