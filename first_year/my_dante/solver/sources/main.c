/*
** EPITECH PROJECT, 2022
** Dante
** File description:
** Main for solver.
*/

#include "my.h"
#include "solver.h"

int main(int argc, char **argv)
{
    map_t map;

    map.buffer = extract_file(&map, argv[1]);
    map.tab =  malloc(sizeof(int *) * (count_columns(map.buffer) + 1));
    if (handle_errors(argc) == 84)
        return 84;
    if (argc == 2) {
        fill_tab(&map);
        display_map(&map);
    }
    return 0;
}
