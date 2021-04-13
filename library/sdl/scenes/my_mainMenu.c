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
    SDL_Log("Main Menu -> Generate button.");
    SDL_Log("Main Menu -> Generate text.");
    SDL_Log("Main Menu -> Generate image");
    while (1) {
        while(SDL_PollEvent(&event))
        {
            switch (event.type) {
                case SDL_QUIT:
                    my_exitWindows(window);
                    return 0;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.x >= 50 && event.button.x <= 50 + 250 && event.button.y >= 250 && event.button.y <= 250 + 75) {
                        return 3;
                    }
                    else if (event.button.x >= 50 && event.button.x <= 150 + 250 && event.button.y >= 350 && event.button.y <= 350 + 75) {
                        return 2;
                    }
                    else if (event.button.x >= 50 && event.button.x <= 150 + 250 && event.button.y >= 450 && event.button.y <= 450 + 75) {
                        return 0;
                    }
                    break;
            }
        }

        //drawRectangle
        my_drawRectangle(window , 50 , 250 , 250 , 75 , 0 , 150 , 0);
        my_drawRectangle(window , 50 , 350 , 250 , 75 , 0 , 0 , 150);
        my_drawRectangle(window , 50 , 450 , 250 , 75 , 150 , 0 , 0);
        //drawText
        my_drawText(window , -75 , -270 , 600 , 700 , 0 , 0 , 0 , "Create");
        my_drawText(window , -75 , -370 , 600 , 700 , 0 , 0 , 0 , "Join");
        my_drawText(window , -75 , -470 , 600 , 700 , 0 , 0 , 0 , "Quit");
        //drawImage
        my_drawImage(window , 0 , 0 , 600 , 150 , "./library/assets/title.bmp");
        my_drawImage(window , -400 , -400 ,600 , 700 , "./library/assets/logo.bmp");
        SDL_UpdateWindowSurface(window);

    }
    return 0;
}