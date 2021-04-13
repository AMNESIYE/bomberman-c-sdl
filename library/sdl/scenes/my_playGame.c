/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_playGame.c
** File description:
**
*/

#include "../../../include/game.h"
#include "../../../include/objects.h"

int my_playGame(SDL_Window *window) {
    TTF_Init();
    my_clearWindows(window);
    SDL_Event event;
    struct character myCharacter;
    myCharacter.colors.red = 147;
    myCharacter.colors.green = 112;
    myCharacter.colors.blue = 219;
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    my_exitWindows(window);
                    return 0;
            }
        }
        my_drawText(window, 0, 0, 800, 600, 255, 0, 0, "It's playGame Scene");
        my_drawRectangle(window, 0, 200, 30, 30, myCharacter.colors.red, myCharacter.colors.green, myCharacter.colors.blue);
        SDL_UpdateWindowSurface(window);

    }
    return 0;
}