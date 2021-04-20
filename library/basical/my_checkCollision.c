/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_checkCollision.c
** File description:
**
*/

#include "../../include/objects.h"

int my_checkCollision(struct character character, struct wall walls[], char input) {
    for (int i = 0; i < 255; i++) {
        switch (input) {
            case 'u':
                if (walls[i].hitbox.x == character.hitbox.x && walls[i].hitbox.y == (character.hitbox.y - 40)) {
                    if (walls[i].breakable == 1) {
                        walls[i].breakable = 2;
                        return 0;
                    } else if (walls[i].breakable == 2) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
                break;
            case 'r':
                if (walls[i].hitbox.y == character.hitbox.y && walls[i].hitbox.x == (character.hitbox.x + 40)) {
                    if (walls[i].breakable == 1) {
                        walls[i].breakable = 2;
                        return 0;
                    } else if (walls[i].breakable == 2) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
                break;
            case 'd':
                if (walls[i].hitbox.x == character.hitbox.x && walls[i].hitbox.y == (character.hitbox.y + 40)) {
                    if (walls[i].breakable == 1) {
                        walls[i].breakable = 2;
                        return 0;
                    } else if (walls[i].breakable == 2) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
                break;
            case 'l':
                if (walls[i].hitbox.y == character.hitbox.y && walls[i].hitbox.x == (character.hitbox.x - 40)) {
                    if (walls[i].breakable == 1) {
                        walls[i].breakable = 2;
                        return 0;
                    } else if (walls[i].breakable == 2) {
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