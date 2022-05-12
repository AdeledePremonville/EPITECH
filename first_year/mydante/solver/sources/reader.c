/*
** EPITECH PROJECT, 2022
** Dante
** File description:
** Read the map for Solver.
*/

#include "my.h"
#include "solver.h"

char *extract_file(map_t *map, char const *path)
{
    struct stat sb;

    map->fd = open(path, O_RDONLY);
    if (map->fd == -1) {
        my_putstr("Error, invalid read\n");
        return NULL;
    }
    stat(path, &sb);
    map->buffer = malloc(sizeof(char) * (sb.st_size + 1));
    if (map->buffer == NULL)
        return NULL;
    map->buffer[sb.st_size] = '\0';
    read(map->fd, map->buffer, sb.st_size);
    close(map->fd);
    return map->buffer;
}
