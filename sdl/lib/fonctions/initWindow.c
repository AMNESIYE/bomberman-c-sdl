/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** initWindow
** File description:
**      initWindow
*/

#include <stdio.h>
#include <SDL2/SDL.h>

void exit_SDL(SDL_Window *win , SDL_Renderer *render) {
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return;
}
void drawRectangle(SDL_Renderer *render) {
    SDL_Rect rect;
    rect.x = 100;
    rect.y = 350;
    rect.w = 250;
    rect.h = 250;
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    SDL_RenderFillRect(render, &rect);
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderPresent(render);
    return;
}

int initWindow (int xSize , int ySize) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("My first window SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, xSize, ySize, SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    int running = 1;
    SDL_Event event;
    
    while(running == 1)
    {
        while(SDL_PollEvent(&event))
        {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    exit_SDL(window , renderer);
                    break;
                case SDL_KEYUP:
                    printf("keyUp\n");
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_z:
                            printf("je presse le boutton z");
                            break;
                    }
                    break;
            }
        }
        drawRectangle(renderer);
    }
    return 0;
}



