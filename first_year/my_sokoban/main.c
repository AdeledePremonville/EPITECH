/*
** EPITECH PROJECT, 2021
** myrunner main
** File description:
** myrunner
*/

#include "sokoban.h"
#include "include/my.h"

bool is_map_valid(char *argv)
{
    int fd = open(argv, O_RDONLY);
    char *buffer;
    int size;
    struct stat buf;

    stat(argv, &buf);
    size = buf.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    read(fd, buffer, size);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != 32 && buffer[i] != '\n' && buffer[i] != '#' &&
            buffer[i] != 'X' && buffer[i] != 'O' && buffer[i] != 'P')
            return false;
    }
    return true;
}

int error_handling(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h')
        return 0;
    if (open(argv[1], O_RDONLY) == -1)
        return 84;
    if (is_map_valid(argv[1]) == false)
        return 84;
    return 0;
}

void usageh(void)
{
    my_printf("USAGE\n\t./my_sokoban map\nDESCRIPTION\n");
    my_printf("\tmap\tfile representing the warehouse map, containing");
    my_printf(" '#' for walls, 'P' for the player, 'X' for boxes ");
    my_printf("and 'O' for storage locations.\n");
}

int main(int argc, char **argv)
{
    char *buffer;

    if (error_handling(argc, argv) == 84)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        usageh();
        return 0;
    }
    buffer = fs_open_file(argv[1]);
    if (sokoban(buffer) == 1)
        return 1;
    return 0;
}
