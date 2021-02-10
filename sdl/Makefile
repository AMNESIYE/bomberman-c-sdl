##
## ETNA PROJECT, 05/10/2019 by vignan_q
## Makefile
## File description:
##      Makefile for lib
##

NAME    =   sdl

SRC     =   src/main.c

CFLAGS= -Wall -Wextra -Werror -std=c11 -lSDL2

CPPFLAGS    =	-I./include/


all:    $(NAME)

$(NAME):
			make -C lib/
			gcc -o $(NAME) $(SRC) $(CFLAGS) $(CPPFLAGS) -L./lib -lmy

clean:
			make clean -C lib/

fclean:     clean
			make fclean -C lib/
			rm -f $(NAME)

debug:
			make -C lib/
			gcc -g3 -o $(NAME) $(SRC) $(CFLAGS) $(CPPFLAGS) -L./lib -lmy

re:         fclean all

.PHONY:     all debug clean fclean re
