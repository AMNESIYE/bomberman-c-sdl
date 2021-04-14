/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_playGame.c
** File description:
**
*/

#include "../../../include/game.h"
#include "../../../include/objects.h"

void my_setupOverlay(SDL_Renderer *renderer) {
    my_drawLine(renderer, 0, 99, 600, 99, 0, 0, 0);
}

void my_refreshPlayScene(SDL_Renderer *renderer, struct character charTable[], int playersNumber) {
    SDL_Log("Entering refresh scene");

    my_clearWindows(renderer);
    my_setupOverlay(renderer);
    for (int i = 0; i < playersNumber; i++) {
        if (charTable[i].hitbox.w == 30 && charTable[i].hitbox.h == 30) {
            my_drawRectangle(renderer, charTable[i].hitbox, charTable[i].colors.red, charTable[i].colors.green,
                             charTable[i].colors.blue);
        }
    }
    SDL_RenderPresent(renderer);
}

void my_initializeCharactersPosition(struct character charTable[]) {
    charTable[0].hitbox.x = 30;
    charTable[0].hitbox.y = 130;

    charTable[1].hitbox.x = 540;
    charTable[1].hitbox.y = 130;

    if (charTable[2].hitbox.w == 30 && charTable[2].hitbox.h == 30) {
        charTable[2].hitbox.x = 30;
        charTable[2].hitbox.y = 640;
    }

    if (charTable[3].hitbox.w == 30 && charTable[3].hitbox.h == 30) {
        charTable[3].hitbox.x = 540;
        charTable[3].hitbox.y = 640;
    }
}

int my_playGame(SDL_Window *window, SDL_Renderer *renderer) {
    int playersNumber = 2; // A variabiliser

    struct character charTable[] = {my_initCharacter(MY_CHARACTER), my_initCharacter(ENEMY_CHARACTER),
                                    my_initCharacter(BLANK_CHARACTER), my_initCharacter(BLANK_CHARACTER)};
    struct character *charTableI = charTable;
    my_initializeCharactersPosition(charTableI);

    my_refreshPlayScene(renderer, charTableI, playersNumber);

    int thereIsAChange = 0;

    SDL_Event event;

    while (1) {
        int start = SDL_GetTicks();
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    my_exitWindows(window, renderer);
                    return 0;
            }
        }
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    my_exitWindows(window, renderer);
                    return 0;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_RIGHT:
                            SDL_Log("Go right.");
                            charTableI[0].hitbox.x += 30;
                            thereIsAChange++;
                            break;
                        case SDLK_LEFT:
                            SDL_Log("Go left.");
                            charTableI[0].hitbox.x -= 30;
                            thereIsAChange++;
                            break;
                        case SDLK_UP:
                            SDL_Log("Go up.");
                            charTableI[0].hitbox.y -= 30;
                            thereIsAChange++;
                            break;
                        case SDLK_DOWN:
                            SDL_Log("Go down.");
                            charTableI[0].hitbox.y += 30;
                            thereIsAChange++;
                            break;
                    }
                    break;
            }
        }
        if (thereIsAChange == 1) {
            my_refreshPlayScene(renderer, charTableI, playersNumber);
            thereIsAChange--;
        }
        int end = SDL_GetTicks() - start;
        int sleep = end - start;
        if (sleep > 0)
            SDL_Delay(sleep);

    }
    return 0;
}