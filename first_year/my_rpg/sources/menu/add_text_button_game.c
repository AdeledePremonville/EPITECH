/*
** EPITECH PROJECT, 2021
** add_text_button_game.c
** File description:
** fct add text button
*/

#include <stdlib.h>
#include "my.h"
#include "p.h"
#include "game.h"

void add_text_button_settings(struct settings *s)
{
    sfSprite_setScale(s->b_save1->info->info, vect(0.276, 0.186));
    add_text_info(s->b_save1,
    "Save your game in the save 1\n\nWarning :\nIt deletes the previous data",
    20, vect(0, 0));
    sfSprite_setScale(s->b_save2->info->info, vect(0.276, 0.186));
    add_text_info(s->b_save2,
    "Save your game in the save 2\n\nWarning :\nIt deletes the previous data",
    20, vect(0, 0));
    sfSprite_setScale(s->b_exit->info->info, vect(0.276, 0.186));
    add_text_info(s->b_exit,
    "Go back to menu\n\nWarning :\nIt doesn't save your game\n",
    20, vect(0, 0));
    sfSprite_setScale(s->b_return->info->info, vect(0.14, 0.11));
    add_text_info(s->b_return, "Exit settings\n", 20, vect(0, 0));
}

void add_text_button_menu(struct menu *m)
{
    add_text_info(m->b_save1, "Load game from save 1", 20, vect(0, 0));
    add_text_info(m->b_save2, "Load game from save 2", 20, vect(0, 0));
    add_text_info(m->b_reset1, "Reset data from save 1", 20, vect(0, 0));
    add_text_info(m->b_reset2, "Reset data from save 2", 20, vect(0, 0));
    add_text_info(m->b_settings, "Open settings", 20, vect(0, 0));
    sfSprite_setScale(m->b_settings->info->info, vect(0.16, 0.11));
    add_text_info(m->b_leave,
    "Leave the game\n\nWarning :\nIt doesn't save your game\n",
    20, vect(0, 0));
    sfSprite_setScale(m->b_leave->info->info, vect(0.276, 0.186));
    add_text_info(m->b_stat, "Show stat and inventory", 20, vect(0, 0));
}

static void free_all_txt(char *pot, char *b_pot, char *sword, char *armor)
{
    free(pot);
    free(b_pot);
    free(armor);
    free(sword);
}

void add_text_button_status(struct status *s, struct mains *m)
{
    char *nb_pot = int_to_str(m->ih->nb_pot);
    char *nb_b_pot = int_to_str(m->ih->nb_big_pot);
    char *nb_armor = int_to_str(m->ih->nb_armor);
    char *nb_sword = int_to_str(m->ih->nb_sword);
    char *pot = my_strcat_alloc("Nb potion 50 hp :  ", nb_pot);
    char *b_pot = my_strcat_alloc("Nb potion 100 hp :  ", nb_b_pot);
    char *armor = my_strcat_alloc("Nb armor 10 hp :  ", nb_armor);
    char *sword = my_strcat_alloc("Nb sword 10 ad :  ", nb_sword);

    add_text_info(s->b_pot, pot, 20, vect(0, 0));
    add_text_info(s->b_big_pot, b_pot, 20, vect(0, 0));
    add_text_info(s->b_armor, armor, 20, vect(0, 0));
    add_text_info(s->b_sword, sword, 20, vect(0, 0));
    free(nb_pot);
    free(nb_b_pot);
    free(nb_armor);
    free(nb_sword);
    free_all_txt(pot, b_pot, sword, armor);
}
