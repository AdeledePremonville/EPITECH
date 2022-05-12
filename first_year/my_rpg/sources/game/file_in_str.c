/*
** EPITECH PROJECT, 2021
** file_in_str.c
** File description:
** put file in str or array
*/

#include "../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *fill_map(char *buff_map, char *pathname, struct stat sb)
{
    int fd = open(pathname, O_RDONLY);

    if (fd < 0) {
        write(2, "open error\n", 11);
        return NULL;
    }
    if (stat(pathname, &sb) == -1) {
        write(2, "stat error\n", 11);
        return NULL;
    }
    buff_map = malloc(sizeof(char) * ((sb.st_size) + 1));
    if (buff_map == NULL)
        return NULL;
    if (read(fd, buff_map, sb.st_size) == -1) {
        write(2, "read error\n", 11);
        return NULL;
    }
    buff_map[sb.st_size] = '\0';
    close(fd);
    return (buff_map);
}

char *file_in_str(char *pathname)
{
    struct stat sb;
    char *buff_map = fill_map(buff_map, pathname, sb);

    if (buff_map == NULL)
        return NULL;
    return buff_map;
}

int fill_line_array(char **array, char *buff, int j, int i)
{
    int nb_char = 0;
    int k = 0;

    for (int l = j; buff[l] != '\n'; l++)
        nb_char++;
    array[i] = malloc(sizeof(char) * (nb_char + 2));
    if (array[i] == NULL)
        return -1;
    for (; buff[j] != '\n'; j++, k++) {
        array[i][k] = buff[j];
    }
    array[i][k] = '\n';
    array[i][k + 1] = '\0';
    return j + 1;
}

char **file_in_array(char *pathname)
{
    struct stat sb;
    char *buff_map = fill_map(buff_map, pathname, sb);
    char **array = NULL;
    int i = 0;
    int j = 0;
    int size = 0;

    if (buff_map == NULL)
        return NULL;
    size = my_strlen(buff_map);
    array = malloc(sizeof(char*) * (count_nb_char(buff_map, '\n') + 1));
    while (j < size) {
        j = fill_line_array(array, buff_map, j, i);
        if (j == -1)
            return NULL;
        i++;
    }
    array[i] = NULL;
    free(buff_map);
    return array;
}
