//
// Created by amnesiye on 13/04/2021.
//

#ifndef BOMBERMAN_OBJECTS_H
#define BOMBERMAN_OBJECTS_H

#include <stdlib.h>
#include <stdio.h>

enum _characterType {
    MY_CHARACTER,
    ENEMY_CHARACTER,
};

struct character {
    struct characterHitbox {
        int charWidth;
        int charHeight;
    };

    struct characterStats {
        int lifePoints;
    };

    struct characterColors {
        int red;
        int green;
        int blue;
    };
    struct characterHitbox hitbox;
    struct characterColors colors;
    struct characterStats stats;
};

struct character my_initCharacter(enum _characterType characterType);

#endif //BOMBERMAN_OBJECTS_H
