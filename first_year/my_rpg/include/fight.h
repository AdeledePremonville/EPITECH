/*
** EPITECH PROJECT, 2021
** fight.h
** File description:
** fight .h
*/

#ifndef _FIGHT_H
    #define _FIGHT_H

    #include "p.h"
    #define ESCAPE 1
    #define WIN 2
    #define LOSE 3

    #define BAT 0
    #define SLIME 1
    #define GOBELIN 2

    #define HP_BAT 23
    #define ATK_BAT 3
    #define HP_LVL_BAT 5
    #define ATK_LVL_BAT 7

    #define HP_SLIME 17
    #define ATK_SLIME 7
    #define HP_LVL_SLIME 7
    #define ATK_LVL_SLIME 5

    #define HP_GOB 20
    #define ATK_GOB 5
    #define HP_LVL_GOB 5
    #define ATK_LVL_GOB 5

    #define HP_HERO 20
    #define ATK_HERO 5
    #define HP_LVL_HERO 5
    #define ATK_LVL_HERO 5

    #define NB_ATK_SWORD 5
    #define NB_HP_ARMOR 5

    #define HEAL_POT 30
    #define HEAL_BIG_POT 50

struct buttons_fight {
    struct button *button_attack;
    sfVector2f attack_size;
    sfVector2f attack_pos;
    struct button *button_spell;
    sfVector2f spell_size;
    sfVector2f spell_pos;
    struct button *button_item;
    sfVector2f item_size;
    sfVector2f item_pos;
    struct button *back;
    sfVector2f back_size;
    sfVector2f back_pos;
    struct button *escape;
    sfVector2f escape_size;
    sfVector2f escape_pos;
};

struct param_fight {
    int nb_pot_100hp;
    int nb_pot_200hp;
    int chara_max_hp;
    int chara_attack;
    int enemy_max_hp;
    int enemy_attack;
    int enemy;
    int max_hp;
};

struct fight {
    sfSprite *sprite_bg;
    sfTexture *text_bg;
    struct buttons_fight *buttons_fight;
    sfMusic *music_fight;
    int state;
    bool turn;
    sfRenderWindow *window;
    bool spam;
    sfSound *sound;
    sfSoundBuffer *buffer;
};

// fight.c
int start_fight(sfRenderWindow *window, struct param_fight *p, int *life_hero);
struct fight *create_fight(sfRenderWindow *window);
sfSprite *create_sprite(char const *filepath);
void move_rect_fight(sfIntRect *rect, int max, int add);

//buttons.c
struct buttons_fight *create_buttons_fight(void);
void destroy_fight(struct fight *fight, struct character *chara,
struct enemy *enemy);

//character.c
struct character *create_character_fight(struct param_fight *p);
struct attack *create_attack(bool has, char *filepath, sfIntRect rect,
int dmg);
void set_fight_struct(struct fight *fight);

//health.c
struct health_bar *create_health(double life, sfVector2f pos,
sfVector2f size);
sfVector2f calc_damage(struct health_bar *health);
sfVector2f calc_pos_damage(struct health_bar *health);

//attack.c
void move_attack(bool *state, sfIntRect *rect, bool *turn, int max);
void move_enemy_attack(bool *state, sfIntRect *rect, struct fight *fight,
struct character *chara);
int get_crit(int dmg, struct enemy *);
void move_basic_spell(sfIntRect *rect, bool *turn, int max_left, bool *state);
void move_spell2(sfIntRect *rect, bool *turn, int max_left, bool *state);

//enemy.c
struct enemy *create_enemy(struct param_fight *p);
void move_enemy(sfIntRect *rect, int max, int add, int *dir);
void destroy_enemy_fight(struct enemy *enemy);

// create_item.c
struct item *create_item(sfVector2f size, sfVector2f pos, char *str, int nb);
struct items *create_items(struct param_fight *p);

// create_attack.c
struct attacks *create_attacks_fight(int);
struct attack *create_attack(bool has, char *filepath, sfIntRect rect,
int dmg);

// display_fight
int display_fight(struct fight *fight, sfEvent event,
struct character *chara, struct enemy *enemy);
void display_enemy_attack(struct fight *fight, sfEvent event,
struct character *chara, struct enemy *enemy);

// manage_clock_fight.c
void manage_clock_fight(struct fight *fight, sfEvent event,
struct character *chara, struct enemy *enemy);
void manage_enemy_attack(struct fight *fight, sfEvent event,
struct character *chara, struct enemy *enemy);
int is_end(sfEvent event, struct fight *fight,
struct character *chara, struct enemy *enemy);

// event_fight.c
int event_fight(sfEvent event, struct fight *fight,
struct character *chara, struct enemy *enemy);
int help_event_fight(sfEvent event, struct fight *fight,
struct character *chara, struct enemy *enemy);
int help_help_event_fight(sfEvent event, struct fight *fight,
struct character *chara, struct enemy *enemy);

//attack_event.c
int event_attack(sfEvent event, struct fight *fight,
struct character *chara, struct enemy *enemy);
void manage_anim_spell2(sfEvent event, struct fight *fight,
struct character *chara, struct enemy *enemy);

#endif
