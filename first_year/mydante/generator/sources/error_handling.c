/*
** EPITECH PROJECT, 2022
** dante
** File description:
** error_handling - dante
*/

#include "my.h"
#include "dante.h"

int error_handling(int argc, char **argv)
{
    if (argc != 3 && argc != 4) {
        printf("Incorrect number of arguments.\n");
        return 84;
    }
    if (my_str_isnum(argv[1]) != 1) {
        printf("Argument 1 is not a number, try again\n");
        return 84;
    }
    if (my_str_isnum(argv[2]) != 1) {
        printf("Argument 2 is not a number, try again\n");
        return 84;
    }
    return 0;
}
