/*
** EPITECH PROJECT, 2022
** Dante
** File description:
** Main for Generator.
*/

#include "my.h"
#include "dante.h"

int main(int argc, char **argv)
{
    int x = 0;
    int y = 0;

    if (error_handling(argc, argv) == 84)
        return 84;
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    if (argc == 3)
        maze_generator_imperfect(x, y);
    if (argc == 4 && strcmp(argv[3], "perfect") == 0) {
        maze_generator_perfect(x, y);
    }
    return 0;
}
