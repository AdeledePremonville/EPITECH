/*
** EPITECH PROJECT, 2021
** decrypt_encrypt_str.c
** File description:
** decrypt or encrypt str with key
*/

#include "../include/my.h"

char *switch_my_char_int_str(char c, char replace, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (c == str[i])
            str[i] = replace;
    }
    return (str);
}

char *decrypt_str_with_key(char *str, char *key)
{
    int i = 0;
    int count = 0;

    while (key[i] != '\0') {
        str = switch_my_char_int_str(key[i], '0' + count, str);
        count++;
        i++;
    }
    return (str);
}

char *encrypt_str_with_key(char *str, char *key)
{
    int i = 0;
    int count = 0;

    while (key[i] != '\0') {
        str = switch_my_char_int_str('0' + count, key[i], str);
        count++;
        i++;
    }
    return (str);
}
