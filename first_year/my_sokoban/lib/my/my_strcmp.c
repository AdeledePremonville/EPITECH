/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** task06
*/

int my_strlen(char const *str);

int same_len(int size_s1, int size_s2, char const *s2, char const *s1)
{
    int len_s2 = my_strlen(s2);

    for (int i = 0; i < len_s2; i++) {
        size_s1 += s1[i];
        size_s2 += s2[i];
    }
    if (size_s1 > size_s2)
        return 1;
    if (size_s1 < size_s2)
        return -1;
    return 0;
}

int my_strcmp(char const *s1, char const *s2)
{
    int size_s1 = 0;
    int size_s2 = 0;
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);

    if (len_s1 > len_s2)
        return 1;
    if (len_s1 < len_s2)
        return -1;
    if (len_s2 == len_s1) {
        if (same_len(size_s1, size_s2, s2, s1) == 1)
            return 1;
        if (same_len(size_s1, size_s2, s2, s1) == -1)
            return -1;
    }
    return (0);
}