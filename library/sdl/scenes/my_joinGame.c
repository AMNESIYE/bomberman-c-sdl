/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_joinGame.c
** File description:
**      
*/

#include "../../../include/game.h"
#include "../../../include/basical.h"
#include "../../../include/client.h"
#include "../../../include/server.h"


static void my_drawNumPad(SDL_Renderer *renderer) {
    SDL_Rect NumPad[12] = {{165 , 100 , 75 , 75} , {265 , 100 , 75 , 75} , {365 , 100 , 75 , 75},
                           {165 , 200 , 75 , 75} , {265 , 200 , 75 , 75} , {365 , 200 , 75 , 75},
                           {165 , 300 , 75 , 75} , {265 , 300 , 75 , 75} , {365 , 300 , 75, 75},
                           {165 , 400 , 175, 75} , {365 , 400 , 75 , 75} , {65 , 100 , 75 , 75}};
    SDL_Rect TextNumPad[12] = {{180 , 110 , 50 , 50} , {280 , 110 , 50 , 50} , {380 , 110 , 50 , 50},
                               {180 , 210 , 50 , 50} , {280 , 210 , 50 , 50} , {380 , 210 , 50 , 50},
                               {180 , 310 , 50 , 50} , {280 , 310 , 50 , 50} , {380 , 310 , 50, 50},
                               {230 , 410 , 50, 50} , {395 , 400 , 25 , 50} , {80 , 110 , 50 , 50}};

    int xPos;
    int yPos;
    for (int i = 0; i < 12; i++) {
        SDL_Rect padBlock = NumPad[i];
        xPos = padBlock.x;
        yPos = padBlock.y;
        if( i == 11 ) {
            for (int i = 0; i < 5; i++) {
                my_drawImage(renderer, padBlock , "./library/assets/block/block (31).bmp");
            }
        } else {
            for (int i = 0; i < 5; i++) {
                my_drawImage(renderer, padBlock , "./library/assets/block/block (53).bmp");
            }
        }
        
        /*
        playPos.x = 230;
        playPos.y = playPos.y  + 25;
        for (int i = 0; i < 5; i++) {
            my_drawImage(renderer, playPos , "./library/assets/block/block (76).bmp");
            playPos.x = playPos.x - 50;
        }*/
    }
    my_drawText(renderer , TextNumPad[0] , 100 , 0 , 0 , "1");
    my_drawText(renderer , TextNumPad[1] , 100 , 0 , 0 , "2");
    my_drawText(renderer , TextNumPad[2] , 100 , 0 , 0 , "3");
    my_drawText(renderer , TextNumPad[3] , 100 , 0 , 0 , "4");
    my_drawText(renderer , TextNumPad[4] , 100 , 0 , 0 , "5");
    my_drawText(renderer , TextNumPad[5] , 100 , 0 , 0 , "6");
    my_drawText(renderer , TextNumPad[6] , 100 , 0 , 0 , "7");
    my_drawText(renderer , TextNumPad[7] , 100 , 0 , 0 , "8");
    my_drawText(renderer , TextNumPad[8] , 100 , 0 , 0 , "9");
    my_drawText(renderer , TextNumPad[9] , 100 , 0 , 0 , "0");
    my_drawText(renderer , TextNumPad[10] , 100 , 0 , 0 , ".");
    my_drawText(renderer , TextNumPad[11] , 0 , 0 , 0 , "DEL");
}
static void my_writeIp(SDL_Renderer* renderer , char* ip) {
    SDL_Rect TextIp = {150 , 25 , (50 + (strlen(ip) * 15)), 50};
    my_drawText(renderer , TextIp , 0 , 0 ,0 , ip);
}
static int isValidIpAddress(char *ipAddress)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
    return result != 0;
}

static void my_refreshJoinGame(SDL_Renderer* renderer , char* ip , int error) {
    my_clearWindows(renderer);
    if (error == 1) {
        SDL_Rect TextError = {215 ,585, 150 , 25};
        my_drawText(renderer , TextError , 255 , 0 , 0 , "Bad Address Ip");
    }
    SDL_Rect buttonBack = {430 , 500, 50,  50};
    SDL_Rect buttonPlay = {130, 500, 50,  50};    
    //play button
    SDL_Rect playPos = {230 , 500 , 50 , 50};
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, playPos , "./library/assets/block/block (32).bmp");
        playPos.x = playPos.x - 50;
    }
    playPos.x = 230;
    playPos.y = playPos.y  + 25;
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, playPos , "./library/assets/block/block (32).bmp");
        playPos.x = playPos.x - 50;
    }
    //back button
    SDL_Rect backPos = {530 , 500 , 50 , 50};
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, backPos , "./library/assets/block/block (31).bmp");
        backPos.x = backPos.x - 50;
    }
    backPos.x = 530;
    backPos.y = backPos.y + 25;
    for (int i = 0; i < 5; i++) {
        my_drawImage(renderer, backPos , "./library/assets/block/block (31).bmp");
        backPos.x = backPos.x - 50;
    }
    SDL_Rect blockPos = {550 , 625 , 50 , 50};
    for (int i = 0; i < 12; i++) {
        my_drawImage(renderer, blockPos , "./library/assets/block/block (75).bmp");
        blockPos.x = blockPos.x - 50;
    }
    my_drawText(renderer, buttonBack , 0, 0, 0, "Back");
    my_drawText(renderer, buttonPlay , 0, 0, 0, "Play");
    my_drawNumPad(renderer);
    my_writeIp(renderer , ip);
    SDL_RenderPresent(renderer);
}
static int my_validAddress(char *ipAddress)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
    return result != 0;
}



static char* my_numPadClik(SDL_Event event) {
    switch(event.type) {
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.x >= 165 && event.button.x <= 165 + 75 && event.button.y >= 100 && event.button.y <= 100 + 75) {
                return "1";
            }
            else if (event.button.x >= 65 && event.button.x <= 65 + 75 && event.button.y >= 100 && event.button.y <= 100 + 75) {
                return "D";
            }
            else if (event.button.x >= 265 && event.button.x <= 265 + 75 && event.button.y >= 100 && event.button.y <= 100 + 75) {
                return "2";
            }
            else if (event.button.x >= 365 && event.button.x <= 365 + 75 && event.button.y >= 100 && event.button.y <= 100 + 75) {
                return "3";
            }
            else if (event.button.x >= 165 && event.button.x <= 165 + 75 && event.button.y >= 200 && event.button.y <= 200 + 75) {
                return "4";
            }
            else if (event.button.x >= 265 && event.button.x <= 265 + 75 && event.button.y >= 200 && event.button.y <= 200 + 75) {
                return "5";
            }
            else if (event.button.x >= 365 && event.button.x <= 365 + 75 && event.button.y >= 200 && event.button.y <= 200 + 75) {
                return "6";
            }
            else if (event.button.x >= 165 && event.button.x <= 165 + 75 && event.button.y >= 300 && event.button.y <= 300 + 75) {
                return "7";
            }
            else if (event.button.x >= 265 && event.button.x <= 265 + 75 && event.button.y >= 300 && event.button.y <= 300 + 75) {
                return "8";
            }
            else if (event.button.x >= 365 && event.button.x <= 365 + 75 && event.button.y >= 300 && event.button.y <= 300 + 75) {
                return "9";
            }
            else if (event.button.x >= 165 && event.button.x <= 165 + 175 && event.button.y >= 400 && event.button.y <= 400 + 75) {
                return "0";
            }
            else if (event.button.x >= 365 && event.button.x <= 365 + 75 && event.button.y >= 400 && event.button.y <= 400 + 75) {
                return ".";
            }
            else {
                return "#";
            }
    }
}

int my_joinGame(SDL_Window *window, SDL_Renderer *renderer , char *ip) {
    TTF_Init();
    SDL_Event event;
    char *tmp;
    my_refreshJoinGame(renderer , ip , 0);
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    my_clearWindows(renderer);
                    SDL_RenderPresent(renderer);
                    my_exitWindows(window, renderer);
                    return 0;
                case SDL_MOUSEBUTTONDOWN:
                    tmp = my_numPadClik(event);
                    if (tmp[0] != '#' && strlen(ip) <= 15) {
                        if (tmp[0] == 'D') {
                            memset(ip , '\0' , 15);
                            my_refreshJoinGame(renderer , ip , 0);
                        }
                        else {
                            strcat(ip , tmp);
                            my_refreshJoinGame(renderer , ip , 0);
                        }
                    }
                    if (event.button.x >= 280 && event.button.x <= 280 + 250 && event.button.y >= 500 &&
                        event.button.y <= 500 + 75) {
                        return 1;
                    } else if (event.button.x >= 30 && event.button.x <= 30 + 250 && event.button.y >= 500 && event.button.y <= 500 + 75) {
                        if (my_validAddress(ip) == 1) {
                            return 5;
                        }
                        else {
                            my_refreshJoinGame(renderer , ip , 1);
                        }
                    }
                    break;
            }
        }
    }
    return 0;
}