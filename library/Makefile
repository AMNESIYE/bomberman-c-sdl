##
## ETNA PROJECT, 05/10/2019 by vignan_q
## Makefile
## File description:
##      Makefile for lib
##

NAME	=		libmy.a

SRC		=	basical/my_portCheck.c	\
			basical/my_atoi.c \
			basical/my_checkColor.c \
			sdl/my_createWindows.c \
			sdl/my_exitWindows.c \
			sdl/draws/my_drawRectangle.c \
			sdl/draws/my_drawSquare.c \
			sdl/draws/my_drawImage.c \
			sdl/draws/my_drawText.c \
			sdl/my_clearWindows.c \
			sdl/scenes/my_mainMenu.c \
			sdl/scenes/my_joinGame.c \
			sdl/scenes/my_createGame.c \
			sdl/scenes/my_playGame.c \

				


OBJ		=		$(SRC:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJ)
			ar -rc $(NAME) $(OBJ)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
