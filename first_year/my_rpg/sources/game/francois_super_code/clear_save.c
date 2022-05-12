/*
** EPITECH PROJECT, 2022
** clear_save.c
** File description:
** clear_save
*/

#include "p.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int clear_save(int nb_save)
{
    int fd;
    const char buff = 'o';
    char *buffer = NULL;

    if (nb_save == 1)
        fclose(fopen("./save/save_one", "w"));
    if (nb_save == 2)
        fclose(fopen("./save/save_two", "w"));
    if (fd == -1)
        return -1;
    return 0;
}
