##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile myprintf
##

SRC =	sources/disp_stdarg.c \
	sources/sum_numbers.c \
	sources/sum_strings_length.c \
	sources/my_strlen.c \
	sources/my_putchar.c \
	sources/my_putstr.c \
	sources/my_put_nbr.c \
	sources/printf.c \
	sources/my_revstr.c

SRC_TEST =	tests/tests_disp_stdarg.c \
		tests/tests_sum_numbers.c \
		tests/tests_sum_strings_length.c \
		tests/tests_myprintf.c \
		tests/tests_changebase.c \
		tests/tests_my_revstr.c

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

NAME_TEST =	tests

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -f *.o
	rm -f *~
	rm -f *.gcda
	rm -f *.gcno
	rm -f *#
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ./unit_test

re: fclean all

unit_tests: $(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -o unit_test $(SRC_TEST) -Iincludes -L. -lmy --coverage -lcriterion

run_tests:
	./unit_test
