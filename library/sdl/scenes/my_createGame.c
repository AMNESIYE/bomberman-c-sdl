/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_createGame.c
** File description:
**      
*/

#include "../../../include/game.h"

int my_createGame(SDL_Window* window)
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
            }
        }
     my_drawText(window , 0 , 0 , 800 , 600 , 255 , 0 , 0 , "je suis trop fort 2");
        SDL_UpdateWindowSurface(window);

    }
    return 0;
}