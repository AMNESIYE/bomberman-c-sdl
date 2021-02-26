/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** initWindow
** File description:
**      initWindow
*/

#include <stdio.h>
#include <SDL2/SDL.h>
#include "../../include/game.h"

void exit_SDL(SDL_Window *win , SDL_Renderer *render) {
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return;
}


int initWindow (int xSize , int ySize) {
    int doubleBuffering;
    SDL_GL_GetAttribute(SDL_GL_DOUBLEBUFFER, &doubleBuffering);
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("My first window SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, xSize, ySize, SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    int running = 1;
    SDL_Event event;
    SDL_Rect player;
    player = initPlayer(player);
    SDL_Rect bomb;
    while(running == 1)
    {
        while(SDL_PollEvent(&event))
        {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    exit_SDL(window , renderer);
                    break;
                case SDL_KEYDOWN:
                    player = playerDetectionKey( event , player , renderer);
                    break;
            }
        }
        player = drawPlayer(player , renderer , bomb);
        drawRectangle(renderer , 0 , 40 , 40 , 40);
        /*drawRectangle(renderer , (xSize - 40) , 0 , 40 , 40);
        drawRectangle(renderer , 0 , (ySize - 40) , 40 , 40);
        drawRectangle(renderer , (xSize - 40) , (ySize - 40), 40 , 40);*/
        
    }
    return 0;
}



