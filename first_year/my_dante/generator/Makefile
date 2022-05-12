##
## EPITECH PROJECT, 2021
## Antman
## File description:
## Makefile of the antman part
##

MAIN 		=	sources/main.c
SRC			=	sources/error_handling.c	\
				sources/generator.c			\
				sources/tools.c				\
				sources/imperfect.c			\
				sources/tools2.c			\
				sources/tools3.c

SRC_OBJ		=	$(SRC:.c=.o) $(MAIN:.c=.o)

TST			=	tests/test.c
TST_OBJ		=	$(TST:.c=.o) $(SRC_OBJ)

NAME		=	generator

CPPFLAGS	+=	-iquote includes -iquote includes
CFLAGS		+=	-Wall -Wextra -Wpedantic -g
LDFLAGS		+=	-L lib/my
LDLIBS		+= 	-lmy

CC			=	gcc
AR			=	ar

all: 		$(NAME)

$(NAME):	$(SRC_OBJ) build_lib
			$(CC) $(SRC_OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)

clean:
			@find . \( -name "#*#" -o -name "*~" -o -name "*.o" \
            -o -name "*.gcda" -o -name "*.gcno" -o -name "vgcore.*" \) -delete

fclean:		clean
			rm -f $(NAME) $(NAME).test lib/my/libmy.a

tests_run:	LDLIBS	+=	-lcriterion
tests_run:	CFLAGS	+=	--coverage
tests_run:	$(TST_OBJ)
			$(CC) $(TST_OBJ) -o $(NAME).test $(LDFLAGS) $(LDLIBS)
			./$(NAME).test
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

re:			fclean all

build_lib:
			make -C lib/my

.PHONY: all	$(NAME)	clean	fclean	tests_run	re	build_lib
