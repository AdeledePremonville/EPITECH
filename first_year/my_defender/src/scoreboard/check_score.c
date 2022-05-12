/*
** EPITECH PROJECT, 2022
** check_score
** File description:
** check_scoreboard - my_defender
*/

#include "struct.h"
#include "../include/menu.h"
#include "../include/pause.h"
#include "how_to.h"
#include "score.h"
#include "building.h"
#include "end.h"
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int my_getnbr(char const *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        res = res * 10;
        res = res + (str[i] - '0');
    }
    return (res);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

buf_t *init_buf(int nb)
{
    buf_t *res = malloc(sizeof(buf_t));

    res->new_score = int_to_str(nb);
    res->buffer = fs_open_file("score.txt");
    res->scores = str_to_word_array(res->buffer, '\n');
    res->len = my_strlen(res->new_score);
    res->zeros = 5 - res->len;
    res->k = 0;
    res->i = 0;
    res->j = 0;
    return res;
}

void fill_score(buf_t *buf)
{
    if (buf->i != 4) {
        for (int l = 29; l >= 6 * buf->i; l--)
            buf->buffer[l + 6] = buf->buffer[l];
    }
    for (buf->j = 6 * buf->i; buf->buffer[buf->j] != '\n'; buf->j++) {
        if (buf->zeros > 0) {
            buf->buffer[buf->j] = '0';
            buf->zeros--;
        } else {
            buf->buffer[buf->j] = buf->new_score[buf->k];
            buf->k++;
        }
    }
}

int check_score(int nb)
{
    buf_t *buf = init_buf(nb);

    for (; buf->i < 5; buf->i++) {
        if (my_getnbr(buf->scores[buf->i]) < nb) {
            fill_score(buf);
            write(open("score.txt", O_RDWR), buf->buffer, 30);
            return 1;
        }
    }
    return 0;
}