##
## ETNA PROJECT, 05/10/2019 by vignan_q
## Makefile
## File description:
##      Makefile for lib
##

NAME    =   bomberman

SRC     =   src/main.c

CFLAGS= -Wall -Wextra -Werror -std=c11

LFLAGS=  `sdl2-config --cflags --libs` -lSDL2 -lSDL2_ttf -lm

CPPFLAGS    =	-I./include/


all:    $(NAME)

$(NAME):
			make -C library/
			gcc -o $(NAME) $(SRC) $(CFLAGS) $(CPPFLAGS) -L./library -lmy $(LFLAGS)

clean:
			make clean -C library/

fclean:     clean
			make fclean -C library/
			rm -f $(NAME)

debug:
			make -C library/
			gcc -g3 -o $(NAME) $(SRC) $(CFLAGS) $(CPPFLAGS) -L./library -lmy $(LFLAGS)

re:         fclean all

.PHONY:     all debug clean fclean re
