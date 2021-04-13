//
// Created by amnesiye on 13/04/2021.
//

#ifndef BOMBERMAN_OBJECTS_H
#define BOMBERMAN_OBJECTS_H

#include <stdlib.h>
#include <stdio.h>

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

struct character {
    struct characterHitbox hitbox;
    struct characterColors colors;
    struct characterStats stats;
};


#endif //BOMBERMAN_OBJECTS_H
