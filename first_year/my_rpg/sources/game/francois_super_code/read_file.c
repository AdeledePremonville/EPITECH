/*
** EPITECH PROJECT, 2021
** read_file.c
** File description:
** read_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "exit.h"

int read_file(int fd, char **buffer, int size)
{
    int ret;

    *buffer = malloc(sizeof(char) * (size + 1));
    if (*buffer == 0)
        return (EXIT_MALLOC);
    ret = read(fd, *buffer, size);
    if (ret == -1) {
        my_putstr(FAILURE_MSG);
        return (EXIT_READ);
    }
    (*buffer)[ret] = '\0';
    return (EXIT_SUCCESS);
}
