/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_checkCollision.c
** File description:
**
*/

#include "../../include/objects.h"

int my_checkPlayerCollision(struct character character, struct wall walls[], char input) {
    for (int i = 0; i < 255; i++) {
        switch (input) {
            case 'u':
                if (walls[i].hitbox.x == character.hitbox.x && walls[i].hitbox.y == (character.hitbox.y - 40)) {
                    if (walls[i].breakable == 2) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
                break;
            case 'r':
                if (walls[i].hitbox.y == character.hitbox.y && walls[i].hitbox.x == (character.hitbox.x + 40)) {
                    if (walls[i].breakable == 2) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
                break;
            case 'd':
                if (walls[i].hitbox.x == character.hitbox.x && walls[i].hitbox.y == (character.hitbox.y + 40)) {
                    if (walls[i].breakable == 2) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
                break;
            case 'l':
                if (walls[i].hitbox.y == character.hitbox.y && walls[i].hitbox.x == (character.hitbox.x - 40)) {
                    if (walls[i].breakable == 2) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
                break;
        }
    }
    return 0;
}

void explodeBombCollision(struct character charTable[], struct wall walls[], int charBombIndex, int bombIndex) {
    for (int i = 0; i < 255; i++) {
        if (walls[i].hitbox.x == charTable[charBombIndex].bombs[bombIndex].hitbox.x &&
            walls[i].hitbox.y == (charTable[charBombIndex].bombs[bombIndex].hitbox.y - 40)) {
            if (walls[i].breakable == 1)
                walls[i].breakable = 2;
            else if (walls[i].breakable == 2) {
                for (int k = 0; k < 4; k++) {
                    if (charTable[k].hitbox.x == charTable[charBombIndex].bombs[bombIndex].hitbox.x &&
                            charTable[k].hitbox.y == (charTable[charBombIndex].bombs[bombIndex].hitbox.y - 40)) {
                        charTable[k].hitbox.y = 0;
                    }
                }
                for (int j = 0; j < 255; j++) {
                    if (walls[j].hitbox.x == charTable[charBombIndex].bombs[bombIndex].hitbox.x &&
                        walls[j].hitbox.y == (charTable[charBombIndex].bombs[bombIndex].hitbox.y - 80)) {
                        if (walls[j].breakable == 1)
                            walls[j].breakable = 2;
                    }
                }
            }
        } else if (walls[i].hitbox.x == charTable[charBombIndex].bombs[bombIndex].hitbox.x &&
                   walls[i].hitbox.y == (charTable[charBombIndex].bombs[bombIndex].hitbox.y + 40)) {
            if (walls[i].breakable == 1)
                walls[i].breakable = 2;
            else if (walls[i].breakable == 2) {
                for (int j = 0; j < 255; j++) {
                    if (walls[j].hitbox.x == charTable[charBombIndex].bombs[bombIndex].hitbox.x &&
                        walls[j].hitbox.y == (charTable[charBombIndex].bombs[bombIndex].hitbox.y + 80)) {
                        if (walls[j].breakable == 1)
                            walls[j].breakable = 2;
                    }
                }
            }
        } else if (walls[i].hitbox.y == charTable[charBombIndex].bombs[bombIndex].hitbox.y &&
                   walls[i].hitbox.x == (charTable[charBombIndex].bombs[bombIndex].hitbox.x - 40)) {
            if (walls[i].breakable == 1)
                walls[i].breakable = 2;
            else if (walls[i].breakable == 2) {
                for (int j = 0; j < 255; j++) {
                    if (walls[j].hitbox.y == charTable[charBombIndex].bombs[bombIndex].hitbox.y &&
                        walls[j].hitbox.x == (charTable[charBombIndex].bombs[bombIndex].hitbox.x - 80)) {
                        if (walls[j].breakable == 1)
                            walls[j].breakable = 2;
                    }
                }
            }
        } else if (walls[i].hitbox.y == charTable[charBombIndex].bombs[bombIndex].hitbox.y &&
                   walls[i].hitbox.x == (charTable[charBombIndex].bombs[bombIndex].hitbox.x + 40)) {
            if (walls[i].breakable == 1)
                walls[i].breakable = 2;
            else if (walls[i].breakable == 2) {
                for (int j = 0; j < 255; j++) {
                    if (walls[j].hitbox.y == charTable[charBombIndex].bombs[bombIndex].hitbox.y &&
                        walls[j].hitbox.x == (charTable[charBombIndex].bombs[bombIndex].hitbox.x + 80)) {
                        if (walls[j].breakable == 1)
                            walls[j].breakable = 2;
                    }
                }
            }
        }
    }
}