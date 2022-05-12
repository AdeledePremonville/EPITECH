##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## this file will compile my progams automatically.
##

SRC	=	main.c \
		src/sokoban.c \
		src/end.c \
		src/move.c \
		src/size.c

OBJ		= $(SRC:.c=.o)

CFLAGS		+= -Wall -Wextra

CPPFLAGS	+= -iquote include

NAME		= my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) -lm -Iinclude -L lib/my -lmy -lncurses

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *#
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	make fclean -C lib/my/
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
