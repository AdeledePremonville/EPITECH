/*
** EPITECH PROJECT, 2022
** My Atoi.
** File description:
** Converts array into int.
*/

#include "../../includes/my.h"
#include <stdlib.h>

int my_atoi(char const *str)
{
    int res;

    if (str == NULL)
        return 0;
    if (str[0] == '-')
        return (-my_atoi(str + 1));
    res = 0;
    for (int i = 0; str[i] >= '0' && str[i] <= '9' && str[i]; i++)
        res = res * 10 + str[i] - '0';
    return (res);
}
