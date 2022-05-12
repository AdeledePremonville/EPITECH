/*
** EPITECH PROJECT, 2022
** load_save.c
** File description:
** load_save
*/

#include "p.h"
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void start_load(struct menu *m, sfEvent event, struct music_vol *v, int save)
{
    francois_super_code(m, load_save(save));
    sfRenderWindow_setView(m->window,
    sfRenderWindow_getDefaultView(m->window));
    set_pos_button_s(m->b_settings, vect(1700, 50));
    set_pos_button_s(m->b_leave, vect(1800, 50));
}

struct save *default_save(struct save *save)
{
    save->nb_stage = 1;
    save->nb_lvl = 1;
    save->nb_exp = 0;
    save->nb_max_xp = 1;
    save->nb_attack = ATK_HERO;
    save->nb_curr_life = HP_HERO;
    save->nb_max_life = HP_HERO;
    save->nb_pot = 0;
    save->nb_big_pot = 0;
    save->nb_armor = 0;
    save->nb_sword = 0;
    return save;
}

struct save *load_save(int nb_save)
{
    struct save *s = malloc(sizeof(struct save));
    int fd;

    if (nb_save == 1)
        fd = open("./save/save_one", O_CREAT | O_RDONLY, 0666);
    if (nb_save == 2)
        fd = open("./save/save_two", O_CREAT | O_RDONLY, 0666);
    if (read(fd, s, sizeof(struct save)) < sizeof(struct save)) {
        return default_save(s);
    }
    return s;
}
