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

struct character my_initBaseCharacter(struct character character) {
    character.hitbox.w = 40;
    character.hitbox.h = 40;
    character.stats.lifePoints = 10;
    character.hitbox.x = 0;
    character.hitbox.y = 0;
    character.skin = "./library/assets/bomberman_40.bmp";
    return character;
}

struct character my_initMyCharacter()
{
    struct character character;
    character = my_initBaseCharacter(character);
    character.colors.red = 147;
    character.colors.green = 112;
    character.colors.blue = 219;
    return character;
}

struct character my_initEnemyCharacter()
{
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
            SDL_Log("InitObjectis -> My Character initialized with base stats.");
            return my_initMyCharacter();
        case 1:
            SDL_Log("InitObjectis -> Enemy Character initialized with base stats.");
            return my_initEnemyCharacter();
        case 2:
            SDL_Log("InitObjectis -> Blank Character initialized with base stats.");
            return my_initBlankCharacter();
    }
}