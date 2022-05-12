/*
** EPITECH PROJECT, 2022
** free.c
** File description:
** free main - my_defender
*/

#include "../include/struct.h"
#include "../include/menu.h"

void free_main(struct defender *def, struct characters *c, \
struct attack *a, struct buildings *b, struct square *s)
{
    //free_def(def);
    free(a);
    free(b);
    free(c);
    free(s);
}