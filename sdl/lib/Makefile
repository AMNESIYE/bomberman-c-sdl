##
## ETNA PROJECT, 05/10/2019 by vignan_q
## Makefile
## File description:
##      Makefile for lib
##

NAME	=		libmy.a

SRC		=		fonctions/initWindow.c \
				fonctions/draw.c \
				fonctions/keyboard.c \

				


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
