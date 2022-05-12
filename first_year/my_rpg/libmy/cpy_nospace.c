/*
** EPITECH PROJECT, 2021
** cpy_nospace.c
** File description:
** copy string without space
*/

int it_is_alphanumeric(char c);

int count_space_to_cut(char const *str, int i)
{
    while (str[i] == ' ' && str[i + 1] == ' ')
        i++;
    return (i);
}

int count_len_of_word(char *str)
{
    int i = 0;

    while (str[i] != ' ')
        str++;
    while (str[i] != ' ')
        i++;
    return (i);
}

int count_number_of_word(char *str)
{
    int i = 0;
    int nb_of_word = 1;

    if (str[i] == ' ')
        i++;
    while (str[i] != '\0') {
        if (str[i] == ' ' && it_is_alphanumeric(str[i + 1]) == 0)
            nb_of_word++;
        i++;
    }
    return (nb_of_word);
}

int nb_char_word(char *str)
{
    int j = 0;
    int k = 0;

    if (str[j] == ' ')
        j++;
    while (str[j] != ' ' && str[j] != '\0') {
        k++;
        j++;
    }
    return (k);
}

char *cpy_nospace(char *dest, char *str_alpha)
{
    int i = 0;
    int j = 0;

    if (str_alpha[i] == ' ')
        i++;
    while (str_alpha[i] != ' ' && str_alpha[i] != '\0') {
        dest[j] = str_alpha[i];
        str_alpha++;
        j++;
    }
    dest[j] = '\0';
    return (dest);
}
