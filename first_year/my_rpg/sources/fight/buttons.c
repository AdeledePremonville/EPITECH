/*
** EPITECH PROJECT, 2022
** buttons.c
** File description:
** buttons - fight my_rpg
*/

#include "my.h"
#include "p.h"
#include <stdlib.h>

void help_create_button_fight(struct buttons_fight *f_button)
{
    f_button->back = create_button(f_button->back_size,
    f_button->back_pos, "back", RED);
    f_button->escape_pos = (sfVector2f){100, 800};
    f_button->escape_size = (sfVector2f){280, 80};
    f_button->escape = create_button(f_button->escape_size,
    f_button->escape_pos, "escape", CYAN);
}

struct buttons_fight *create_buttons_fight(void)
{
    struct buttons_fight *f_button = malloc(sizeof(struct buttons_fight) * 1);

    f_button->attack_size = (sfVector2f){305, 80};
    f_button->attack_pos = (sfVector2f){580, 800};
    f_button->button_attack = create_button(f_button->attack_size,
    f_button->attack_pos, "attack", RED);
    f_button->spell_pos = (sfVector2f){1100, 800};
    f_button->spell_size = (sfVector2f){225, 80};
    f_button->button_spell = create_button(f_button->spell_size,
    f_button->spell_pos, "spell", BLUE);
    f_button->item_size = (sfVector2f){180, 80};
    f_button->item_pos = (sfVector2f){1550, 800};
    f_button->button_item = create_button(f_button->item_size,
    f_button->item_pos, "item", GREEN);
    f_button->back_size = (sfVector2f){200, 80};
    f_button->back_pos = (sfVector2f){100, 700};
    help_create_button_fight(f_button);
    return f_button;
}

void destroy_chara_help(struct character *chara)
{
    sfSprite_destroy(chara->attacks->basic_physic->sprite);
    sfTexture_destroy(chara->attacks->basic_physic->texture);
    sfClock_destroy(chara->attacks->basic_physic->clock);
    free(chara->attacks->basic_physic);
    destroy_button(chara->attacks->basic_spell->text);
    sfSprite_destroy(chara->attacks->basic_spell->sprite);
    sfTexture_destroy(chara->attacks->basic_spell->texture);
    sfClock_destroy(chara->attacks->basic_spell->clock);
    free(chara->attacks->basic_spell);
    destroy_button(chara->attacks->kick->text);
    sfSprite_destroy(chara->attacks->kick->sprite);
    sfTexture_destroy(chara->attacks->kick->texture);
    sfClock_destroy(chara->attacks->kick->clock);
    free(chara->attacks->kick);
    destroy_button(chara->attacks->spell2->text);
    sfSprite_destroy(chara->attacks->spell2->sprite);
    sfTexture_destroy(chara->attacks->spell2->texture);
    sfClock_destroy(chara->attacks->spell2->clock);
    free(chara->attacks->spell2);
    free(chara->attacks);
}

void destroy_chara_struct(struct character *chara)
{
    sfSprite_destroy(chara->sprite_character);
    sfTexture_destroy(chara->text_character);
    sfClock_destroy(chara->clock);
    sfRectangleShape_destroy(chara->health->health);
    sfRectangleShape_destroy(chara->health->damage);
    free(chara->health);
    destroy_button(chara->items->potion_100hp->button);
    sfText_destroy(chara->items->potion_100hp->nb);
    sfText_destroy(chara->items->potion_200hp->nb);
    destroy_button(chara->items->potion_200hp->button);
    free(chara->items->potion_100hp);
    free(chara->items->potion_200hp);
    free(chara->items);
    destroy_button(chara->attacks->basic_physic->text);
    destroy_chara_help(chara);
}

void destroy_fight(struct fight *fight, struct character *chara,
struct enemy *enemy)
{
    sfSoundBuffer_destroy(fight->buffer);
    sfSound_destroy(fight->sound);
    sfMusic_stop(fight->music_fight);
    sfSprite_destroy(fight->sprite_bg);
    sfTexture_destroy(fight->text_bg);
    destroy_button(fight->buttons_fight->button_attack);
    destroy_button(fight->buttons_fight->button_spell);
    destroy_button(fight->buttons_fight->button_item);
    free(fight->buttons_fight);
    sfMusic_destroy(fight->music_fight);
    free(fight);
    destroy_chara_struct(chara);
    destroy_enemy_fight(enemy);
}
