/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_checkColor.c
** File description:
**      
*/

#include "../../include/basical.h"

int my_checkColor(int colorNb) {
    if (colorNb >= 255) {
        return 255;
    }
    else if (colorNb <= 0) {
        return 0;
    }
    else {
        return colorNb;
    }
}