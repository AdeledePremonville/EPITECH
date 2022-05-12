/*
** EPITECH PROJECT, 2022
** Dante
** File description:
** Error handling for Solver.
*/

#include "my.h"
#include "solver.h"

int handle_errors(int argc)
{
    if (argc != 2) {
        printf("Wrong number of arguments.\n");
        return 84;
    }
    return 0;
}
