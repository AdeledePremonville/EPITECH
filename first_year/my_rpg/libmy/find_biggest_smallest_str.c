/*
** EPITECH PROJECT, 2021
** find_bigger_smallest_str.c
** File description:
** find bigger or smallest str and return it
*/

#include "../include/my.h"

char *find_smallest_strm(char *str1, char *str2)
{
    int s1 = my_strlen(str1);
    int s2 = my_strlen(str2);
    int i = 0;

    if (s1 < s2)
        return (str1);
    if (s2 < s1)
        return (str2);
    if (s1 == s2) {
        while (str1[i] == str2[i])
            i++;
    }
    if (str1[i] < str2[i])
        return (str1);
    return (str2);
}

char *find_bigger_str_min(char *str1, char *str2)
{
    int s1 = my_strlen(str1);
    int s2 = my_strlen(str2);
    int i = 0;

    if (s1 > s2)
        return (str1);
    if (s2 > s1)
        return (str2);
    if (s1 == s2) {
        while (str1[i] == str2[i])
            i++;
    }
    if (str1[i] > str2[i])
        return (str1);
    return (str2);
}
