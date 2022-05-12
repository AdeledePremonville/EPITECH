/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** Exo x.
*/

int my_strcmp(char const *s1, char const *s2)
{
    int val1 = 0;
    int val2 = 0;

    for (int i = 0; s1[i] != '\0'; i++)
        val1 += s1[i];
    for (int i = 0; s2[i] != '\0'; i++)
        val2 += s2[i];
    if (val1 > val2)
        return (1);
    else if (val2 > val1)
        return (-1);
    return (0);
}
