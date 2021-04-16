//
// Created by amnesiye on 13/04/2021.
//

#ifndef MY_H_OBJECTS
#define MY_H_OBJECTS

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>

enum _characterType {
    MY_CHARACTER,
    ENEMY_CHARACTER,
    BLANK_CHARACTER
};

struct client {
    int clientID;
};

struct characterStats {
    int lifePoints;
};

struct characterColors {
    int red;
    int green;
    int blue;
};

struct character {
    SDL_Rect hitbox;
    struct client client;
    struct characterColors colors;
    struct characterStats stats;
    char* skin;
    char* name;
};

struct wall {
    int breakable;
    SDL_Rect hitbox;
    char* skin;
    int broken;
};

struct character my_initCharacter(enum _characterType characterType);
int my_checkCollision(struct character character, struct wall walls[], char input);
void my_initializeCharactersPosition(struct character charTable[]);
void my_initWalls(struct wall walls[]);

#endif
