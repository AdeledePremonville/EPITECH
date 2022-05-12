##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## task01
##

SRC =	my_find_prime_sup.c	\
	my_putchar.c		\
	my_showmem.c		\
	my_strcapitalize.c	\
	my_str_isalpha.c	\
	my_str_isupper.c	\
	my_strncmp.c		\
	my_swap.c		\
	my_put_nbr.c		\
	my_showstr.c		\
	my_strcat.c		\
	my_str_islower.c	\
	my_strlen.c		\
	my_strncpy.c		\
	my_compute_power_rec.c	\
	my_isneg.c		\
	my_putstr.c		\
	my_show_word_array.c	\
	my_strcmp.c		\
	my_str_isnum.c		\
	my_strlowcase.c		\
	my_strstr.c		\
	my_compute_square_root.c\
	my_is_prime.c		\
	my_revstr.c		\
	my_sort_int_array.c	\
	my_strcpy.c		\
	my_str_isprintable.c	\
	my_strncat.c		\
	my_strupcase.c		\
	printf.c		\
	change_base.c		\
	my_getnbr.c			\
	str_to_word_array.c \
	my_arraylen.c \
	my_intlen.c \
	fs_open_file.c

SRCD	=	my.h

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

NAMED	=	include

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -c $(OBJ)
	ar rc $(NAME) *.o
	cp $(NAME) ../
	cp $(SRCD) ../../$(NAMED)/

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f *~
	rm -f *#

re:	fclean all
