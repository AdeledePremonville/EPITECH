/*
** EPITECH PROJECT, 2022
** fsopenfile
** File description:
** fs_open_file
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char *fs_open_file(char *filepath)
{
    struct stat size;
    int fd = open(filepath, O_RDONLY);
    stat(filepath, &size);
    char *buffer = malloc(sizeof(char) * (size.st_size + 1));

    if (fd == -1)
        return NULL;
    if (buffer == NULL)
        return NULL;
    read(fd, buffer, size.st_size);
    close(fd);
    return buffer;
}
