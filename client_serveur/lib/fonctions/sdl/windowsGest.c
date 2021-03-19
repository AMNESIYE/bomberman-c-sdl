/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** windowsGest
** File description:
**      windowsGest
*/

#include "../../../include/server.h"


void exit_SDL(SDL_Window *win , SDL_Renderer *render) {
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return;
}

void drawRectangle(SDL_Renderer *render , int Xpos , int Ypos , int Wlength , int Hlength) {
    SDL_Rect rect;
    rect.x = Xpos;
    rect.y = -Ypos + 800;
    rect.w = Wlength;
    rect.h = Hlength;
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    SDL_RenderFillRect(render, &rect);
    SDL_RenderPresent(render);
    return;
}

int init_SDL(int sizeX , int sizeY) {
    int doubleBuffering;
    SDL_GL_GetAttribute(SDL_GL_DOUBLEBUFFER, &doubleBuffering);
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Bomberman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sizeX, sizeY, SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Event eventTrigger;

    while(1) {
        while(SDL_PollEvent(&eventTrigger))
        {
            switch (eventTrigger.type) {
                case SDL_QUIT:
                    return 0;
                    exit_SDL(window , renderer);
                    break;
            }
        }
        drawRectangle(renderer , 0 , 40 , 40 , 40);
    }
    return 0;    
    
}
