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
#include <time.h>

#define BOMB_TIMER_SEC 6

enum _characterType {
    MY_CHARACTER,
    ENEMY_CHARACTER,
    BLANK_CHARACTER
};

struct client {
    int clientID;
    int terminated;
};

struct characterStats {
    int lifePoints;
};

struct characterColors {
    int red;
    int green;
    int blue;
};

struct bomb {
    SDL_Rect hitbox;
    char* skin;
    time_t timer;
    int exploded;
};

struct character {
    SDL_Rect hitbox;
    struct client client;
    struct characterColors colors;
    struct characterStats stats;
    struct bomb bombs[2];
    char* skin;
    char* name;
};

struct wall {
    int breakable;
    SDL_Rect hitbox;
    char* skin;
};

struct character my_initCharacter(enum _characterType characterType);
int my_checkPlayerCollision(struct character character, struct wall walls[], char input);
void explodeBombCollision(struct character charTable[], struct wall walls[], int charBombIndex, int bombIndex);
void my_initializeCharactersPosition(struct character charTable[]);

#endif
