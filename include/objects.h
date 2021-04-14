//
// Created by amnesiye on 13/04/2021.
//

#ifndef MY_H_OBJECTS
#define MY_H_OBJECTS

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

enum _characterType {
    MY_CHARACTER,
    ENEMY_CHARACTER,
    BLANK_CHARACTER
};

struct character {

    struct characterStats {
        int lifePoints;
    };

    struct characterColors {
        int red;
        int green;
        int blue;
    };

    SDL_Rect hitbox;
    struct characterColors colors;
    struct characterStats stats;
    SDL_Surface *skin;
};

struct character my_initCharacter(enum _characterType characterType);

#endif
