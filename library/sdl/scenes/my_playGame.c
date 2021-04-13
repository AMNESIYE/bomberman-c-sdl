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
    struct character myCharacter = my_initCharacter(MY_CHARACTER);
    struct character exampleEnemyCharacter = my_initCharacter(ENEMY_CHARACTER);
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    my_exitWindows(window);
                    return 0;
            }
        }
        my_drawText(window, 0, 0, 800, 600, 255, 0, 0, "It's playGame Scene");
        // Overlay separate line
        my_drawRectangle(window, 0, 99, 600, 1, 0, 0, 0);
        // Init my character
        my_drawRectangle(window, 30, 130, 30, 30, myCharacter.colors.red, myCharacter.colors.green,
                         myCharacter.colors.blue);
        // Init one enemy character
        my_drawRectangle(window, 540, 640, 30, 30, exampleEnemyCharacter.colors.red, exampleEnemyCharacter.colors.green,
                         exampleEnemyCharacter.colors.blue);
        SDL_UpdateWindowSurface(window);

    }
    return 0;
}