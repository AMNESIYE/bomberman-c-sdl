/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_initObjects.c
** File description:
**
*/

#include "../../include/objects.h"

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void my_initializeCharactersPosition(struct character charTable[]) {
    charTable[0].hitbox.x = 40;
    charTable[0].hitbox.y = 140;
    charTable[0].name = "player1";

    charTable[1].hitbox.x = 520;
    charTable[1].hitbox.y = 140;
    charTable[0].name = "player2";

    if (charTable[2].hitbox.w == 40 && charTable[2].hitbox.h == 40) {
        charTable[2].hitbox.x = 40;
        charTable[2].hitbox.y = 620;
        charTable[0].name = "player3";
    }

    if (charTable[3].hitbox.w == 40 && charTable[3].hitbox.h == 40) {
        charTable[3].hitbox.x = 520;
        charTable[3].hitbox.y = 620;
        charTable[0].name = "player4";
    }
}

struct character my_initBaseCharacter(struct character character) {
    character.hitbox.w = 40;
    character.hitbox.h = 40;
    character.stats.lifePoints = 10;
    character.hitbox.x = 0;
    character.hitbox.y = 0;
    character.skin = "./library/assets/bomberman_40.bmp";
    return character;
}

struct character my_initMyCharacter() {
    struct character character;
    character = my_initBaseCharacter(character);
    character.colors.red = 147;
    character.colors.green = 112;
    character.colors.blue = 219;
    return character;
}

struct character my_initEnemyCharacter() {
    struct character character;
    character = my_initBaseCharacter(character);
    character.colors.red = 220;
    character.colors.green = 20;
    character.colors.blue = 60;
    return character;
}

struct character my_initBlankCharacter() {
    struct character character;
    character = my_initBaseCharacter(character);
    character.colors.red = 255;
    character.colors.green = 255;
    character.colors.blue = 255;
    return character;
}

struct character my_initCharacter(enum _characterType characterType) {
    switch (characterType) {
        case 0:
            SDL_Log("InitObjects -> My Character initialized with base stats.");
            return my_initMyCharacter();
        case 1:
            SDL_Log("InitObjects -> Enemy Character initialized with base stats.");
            return my_initEnemyCharacter();
        case 2:
            SDL_Log("InitObjects -> Blank Character initialized with base stats.");
            return my_initBlankCharacter();
    }
}

void my_initWalls(struct wall walls[]) {
    int j = 0;
    for (int i = 0; i < 15; i++, j++) {
        walls[j].hitbox.x = i * 40;
        walls[j].hitbox.y = 100;
        walls[j].hitbox.w = 40;
        walls[j].hitbox.h = 40;
        walls[j].skin = "./library/assets/block/block (74).bmp";
        walls[j].breakable = 1;
    }
    for (int i = 0; i < 15; i++, j++) {
        if (j == 15 || j == 29) {
            walls[j].hitbox.x = i * 40;
            walls[j].hitbox.y = 140;
            walls[j].hitbox.w = 40;
            walls[j].hitbox.h = 40;
            walls[j].skin = "./library/assets/block/block (74).bmp";
            walls[j].breakable = 0;
        }

    }
    for (int i = 0; i < 15; i++, j++) {
        if (j % 2 == 0) {
            walls[j].hitbox.x = i * 40;
            walls[j].hitbox.y = 180;
            walls[j].hitbox.w = 40;
            walls[j].hitbox.h = 40;
            walls[j].skin = "./library/assets/block/block (74).bmp";
            walls[j].breakable = 0;
        }

    }
    for (int i = 0; i < 15; i++, j++) {
        if (j == 45 || j == 59) {
            walls[j].hitbox.x = i * 40;
            walls[j].hitbox.y = 220;
            walls[j].hitbox.w = 40;
            walls[j].hitbox.h = 40;
            walls[j].skin = "./library/assets/block/block (74).bmp";
            walls[j].breakable = 0;
        }

    }
    for (int i = 0; i < 15; i++, j++) {
        if (j % 2 == 0) {
            walls[j].hitbox.x = i * 40;
            walls[j].hitbox.y = 260;
            walls[j].hitbox.w = 40;
            walls[j].hitbox.h = 40;
            walls[j].skin = "./library/assets/block/block (74).bmp";
            walls[j].breakable = 0;
        }

    }
    for (int i = 0; i < 15; i++, j++) {
        if (j == 75 || j == 89) {
            walls[j].hitbox.x = i * 40;
            walls[j].hitbox.y = 300;
            walls[j].hitbox.w = 40;
            walls[j].hitbox.h = 40;
            walls[j].skin = "./library/assets/block/block (74).bmp";
            walls[j].breakable = 0;
        }

    }
    for (int i = 0; i < 15; i++, j++) {
        if (j % 2 == 0) {
            walls[j].hitbox.x = i * 40;
            walls[j].hitbox.y = 340;
            walls[j].hitbox.w = 40;
            walls[j].hitbox.h = 40;
            walls[j].skin = "./library/assets/block/block (74).bmp";
            walls[j].breakable = 0;
        }

    }
    for (int i = 0; i < 15; i++, j++) {
        if (j == 105 || j == 119) {
            walls[j].hitbox.x = i * 40;
            walls[j].hitbox.y = 380;
            walls[j].hitbox.w = 40;
            walls[j].hitbox.h = 40;
            walls[j].skin = "./library/assets/block/block (74).bmp";
            walls[j].breakable = 0;
        }

    }
    for (int i = 0; i < 15; i++, j++) {
        if (j % 2 == 0) {
            walls[j].hitbox.x = i * 40;
            walls[j].hitbox.y = 420;
            walls[j].hitbox.w = 40;
            walls[j].hitbox.h = 40;
            walls[j].skin = "./library/assets/block/block (74).bmp";
            walls[j].breakable = 0;
        }

    }
    for (int i = 0; i < 15; i++, j++) {
        if (j == 135 || j == 149) {
            walls[j].hitbox.x = i * 40;
            walls[j].hitbox.y = 460;
            walls[j].hitbox.w = 40;
            walls[j].hitbox.h = 40;
            walls[j].skin = "./library/assets/block/block (74).bmp";
            walls[j].breakable = 0;
        }

    }
    for (int i = 0; i < 15; i++, j++) {
        if (j % 2 == 0) {
            walls[j].hitbox.x = i * 40;
            walls[j].hitbox.y = 500;
            walls[j].hitbox.w = 40;
            walls[j].hitbox.h = 40;
            walls[j].skin = "./library/assets/block/block (74).bmp";
            walls[j].breakable = 0;
        }

    }
    for (int i = 0; i < 15; i++, j++) {
        if (j == 165 || j == 179) {
            walls[j].hitbox.x = i * 40;
            walls[j].hitbox.y = 540;
            walls[j].hitbox.w = 40;
            walls[j].hitbox.h = 40;
            walls[j].skin = "./library/assets/block/block (74).bmp";
            walls[j].breakable = 0;
        }

    }
    for (int i = 0; i < 15; i++, j++) {
        if (j % 2 == 0) {
            walls[j].hitbox.x = i * 40;
            walls[j].hitbox.y = 580;
            walls[j].hitbox.w = 40;
            walls[j].hitbox.h = 40;
            walls[j].skin = "./library/assets/block/block (74).bmp";
            walls[j].breakable = 0;
        }

    }
    for (int i = 0; i < 15; i++, j++) {
        if (j == 195 || j == 209) {
            walls[j].hitbox.x = i * 40;
            walls[j].hitbox.y = 620;
            walls[j].hitbox.w = 40;
            walls[j].hitbox.h = 40;
            walls[j].skin = "./library/assets/block/block (74).bmp";
            walls[j].breakable = 0;
        }

    }
    for (int i = 0; i < 15; i++, j++) {
        walls[j].hitbox.x = i * 40;
        walls[j].hitbox.y = 660;
        walls[j].hitbox.w = 40;
        walls[j].hitbox.h = 40;
        walls[j].skin = "./library/assets/block/block (74).bmp";
        walls[j].breakable = 0;
    }

}