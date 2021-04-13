/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_playGame.c
** File description:
**
*/

#include "../../../include/game.h"
#include "../../../include/objects.h"

/*void my_initializePlayScene(SDL_Window *window) {
    my_drawText(window, 0, 0, 800, 600, 255, 0, 0, "It's playGame Scene");
    //my_drawRectangle(window, 0, 99, 600, 1, 0, 0, 0);
    my_drawImage(window, 0, 0, 30, 30, "./library/assets/bomb.bmp");
}*/

/*void my_refreshPlayScene(SDL_Window *window, struct character charTable[]) {
    SDL_Log("Entering refresh scene");
    //my_clearWindows(window);
    my_initializePlayScene(window);
    for (int i = 0; i < 2; i++) {
        SDL_Log("Refreshing character");
        my_drawRectangle(window, charTable[i].position.x, charTable[i].position.y, charTable[i].hitbox.charWidth,
                         charTable[i].hitbox.charHeight, charTable[i].colors.red, charTable[i].colors.green,
                         charTable[i].colors.blue);
    }
}*/

/*void my_initializeCharactersPosition(struct character charTable[]) {
    charTable[0].position.x = 30;
    charTable[0].position.y = 130;

    charTable[1].position.x = 540;
    charTable[1].position.y = 130;

    charTable[2].position.x = 30;
    charTable[2].position.y = 640;

    charTable[3].position.x = 540;
    charTable[3].position.y = 640;
}*/

int my_playGame(SDL_Window *window, SDL_Renderer *renderer) {
    my_clearWindows(renderer);

    SDL_Rect player1 = { 0, 0, 30, 30};

    SDL_Rect image = { 30, 0, 30, 30};

    my_drawRectangle(renderer, player1, 0, 0, 0);
    SDL_RenderPresent(renderer);
    SDL_Event event;
    SDL_RenderPresent(renderer);

    /*struct character charTable[] = {my_initCharacter(MY_CHARACTER), my_initCharacter(ENEMY_CHARACTER),
                                    my_initCharacter(BLANK_CHARACTER), my_initCharacter(BLANK_CHARACTER)};
    struct character *charTableInitialized = charTable;
    my_initializeCharactersPosition(charTableInitialized);*/
    int thereIsAChange = 0;

    //my_refreshPlayScene(window, charTableInitialized);
    //SDL_UpdateWindowSurface(window);

    /*SDL_Surface* screen = SDL_CreateRGBSurface(0, 30, 30, 32, 0, 0, 0, 0);
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 30;
    rect.h = 30;
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));*/
    /*my_drawRectangle(renderer, 0, 0, 30, 30, 0,0, 0);
    SDL_RenderPresent(renderer);*/
    while (1) {
        //SDL_Log("tick");
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
                            player1.x += 30;
                            thereIsAChange++;
                            break;
                    }
                    break;
            }
        }
        if (thereIsAChange == 1) {
            my_clearWindows(renderer);
            my_drawRectangle(renderer, player1, 0, 0, 0);
            SDL_RenderPresent(renderer);
            thereIsAChange--;
        }
        int end = SDL_GetTicks() - start;
        int sleep = end - start;
        if (sleep > 0)
            SDL_Delay(sleep);

    }
    return 0;
}