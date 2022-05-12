/*
** EPITECH PROJECT, 2021
** get_file_data_using_stat.c
** File description:
** get_file_data_using_stat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "exit.h"
#include "p.h"
#include "my.h"

int get_file_size(char const *filepath, int fd, struct stat *sb)
{
    if (fd == -1) {
        my_putstr(FAILURE_MSG);
        return EXIT_OPEN;
    }
    if (stat(filepath, sb) == -1)
        return EXIT_ERROR;
    if (sb->st_size == 0)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int get_file_data(char const *filepath, char **buffer)
{
    int fd = open(filepath, O_RDONLY);
    struct stat sb;

    if (get_file_size(filepath, fd, &sb) == EXIT_ERROR) {
        close(fd);
        return EXIT_ERROR;
    }
    if (read_file(fd, buffer, sb.st_size) == EXIT_READ) {
        free(*buffer);
        close(fd);
        return EXIT_READ;
    }
    (*buffer)[sb.st_size - 1] = '\0';
    close(fd);
    return EXIT_SUCCESS;
}
