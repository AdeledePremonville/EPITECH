/*
** EPITECH PROJECT, 2022
** francois_super_code.c
** File description:
** francois_super_code
*/

#include "exit.h"
#include "p.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

struct save *fill_struct_save(struct mains *m)
{
    struct save *s = malloc(sizeof(struct save));

    s->nb_stage = m->ih->stage;
    s->nb_lvl = m->ih->lvl;
    s->nb_exp = m->ih->curr_xp;
    s->nb_max_xp = m->ih->max_xp;
    s->nb_attack = m->ih->attack;
    s->nb_curr_life = m->ih->life_hero;
    s->nb_max_life = m->ih->max_life;
    s->nb_pot = m->ih->nb_pot;
    s->nb_big_pot = m->ih->nb_big_pot;
    s->nb_armor = m->ih->nb_armor;
    s->nb_sword = m->ih->nb_sword;
    return s;
}

int save_data(int nb_save, struct save *save)
{
    int fd = 0;

    if (nb_save == 1)
        fd = open("./save/save_one", O_CREAT | O_WRONLY, 0666);
    if (nb_save == 2)
        fd = open("./save/save_two", O_CREAT | O_WRONLY, 0666);
    if (fd == -1) {
        my_putstr("error\n");
        return -1;
    }
    write(fd, save, sizeof(struct save));
    return 0;
}
