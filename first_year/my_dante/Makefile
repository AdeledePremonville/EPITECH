##
## EPITECH PROJECT, 2021
## Antman
## File description:
## Main Makefile of the project
##

all:
			make -C generator/
			make -C solver/

clean:
			@find . \( -name "#*#" -o -name "*~" -o -name "*.o" \
            -o -name "*.gcda" -o -name "*.gcno" -o -name "vgcore.*" \) -delete

fclean:		clean
			make fclean -C generator/
			make fclean -C solver/

tests_run:
			make tests_run -C generator/
			make tests_run -C solver/

re:			fclean all

.PHONY: all	$(NAME)	clean	fclean	tests_run	re
