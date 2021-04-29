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

static struct character my_initBaseCharacter(struct character character) {
    character.hitbox.w = 40;
    character.hitbox.h = 40;
    character.stats.lifePoints = 3;
    character.client.terminated = 0;
    character.hitbox.x = 0;
    character.hitbox.y = 0;
    character.skin = "./library/assets/bomberman_40.bmp";
    for (int i = 0; i < 2; i++) {
        character.bombs[i].skin = "./library/assets/bomb40.bmp";
        character.bombs[i].timer = clock();
        character.bombs[i].exploded = 1;
        character.bombs[i].hitbox.x = 0;
        character.bombs[i].hitbox.y = 0;
        character.bombs[i].hitbox.w = 40;
        character.bombs[i].hitbox.h = 40;
    }

    return character;
}

static struct character my_initMyCharacter() {
    struct character character;
    character = my_initBaseCharacter(character);
    character.colors.red = 147;
    character.colors.green = 112;
    character.colors.blue = 219;
    return character;
}

static struct character my_initEnemyCharacter() {
    struct character character;
    character = my_initBaseCharacter(character);
    character.colors.red = 220;
    character.colors.green = 20;
    character.colors.blue = 60;
    return character;
}

static struct character my_initBlankCharacter() {
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