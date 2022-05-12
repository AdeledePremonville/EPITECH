##
## EPITECH PROJECT, 2022
## delivery
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/functions.c	\
		src/characters.c	\
		src/menu/menu.c	\
		src/free.c	\
		src/menu/free.c	\
		src/menu/menu_struct.c	\
		src/menu/draw.c	\
		src/pause/pause.c	\
		src/pause/free.c	\
		src/pause/pause_struct.c  \
		src/how_to/how_to.c				\
		src/how_to/init.c				\
    	src/dragon_init.c	\
		src/ennemies_rect.c	\
		src/buildings_placement.c	\
		src/buildings_price.c	\
		src/building/building.c	\
		src/building/draw.c     \
		src/demon_init.c	\
		src/lizard_init.c	\
		src/spawn.c			\
		src/scoreboard/score.c		\
		src/scoreboard/check_score.c		\
		src/scoreboard/str_to_word_array.c	\
		src/scoreboard/init.c				\
		src/end/end.c						\
		src/end/int_to_str.c    \
		src/building_shoot.c

EXEC	=	my_defender

OBJ		= $(SRC:.c =.o)

CFLAGS =	-Wall -Wextra

CPPFLAGS =	-I include/ -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

all:	$(OBJ)
	gcc $(SRC) -g -o $(EXEC) $(FLAGS) $(CFLAGS) $(CPPFLAGS)

clean:
	rm -f *#
	rm -f *gcno
	rm -f *gcda

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all re fclean clean