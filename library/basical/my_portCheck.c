/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** checkPort
** File description:
**      checkPort
*/

#include "../../include/basical.h"

int my_portCheck(char *portNb) {
    int portNumber = my_atoi(portNb);
    if (portNumber < 0)
        return -1;
    else {
        if (portNumber > 0 && portNumber < 65536)
            return 1;
        else
            return -1;
    }
}

