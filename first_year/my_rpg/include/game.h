/*
** EPITECH PROJECT, 2021
** game.h
** File description:
** game .h
*/

#ifndef _GAME_H
    #define _GAME_H

struct save {
    int nb_stage;
    int nb_lvl;
    int nb_exp;
    int nb_max_xp;
    int nb_attack;
    int nb_curr_life;
    int nb_max_life;
    int nb_pot;
    int nb_big_pot;
    int nb_armor;
    int nb_sword;
};

struct assets {
    sfTexture *texture;
    sfSprite *sprite;
};

struct gettimes {
    sfClock *clock;
    sfTime time;
    float seconds;
};

struct arrows {
    bool left;
    bool up;
    bool right;
    bool down;
};

struct text_nb {
    sfText *text;
    sfText *nb;
    int nb_max;
};

struct text_nb_max {
    sfText *text;
    sfText *curr;
    sfText *max;
    sfText *slash;
    int nb_curr;
    int nb_max;
};

struct status {
    struct button_s *b_return;
    struct button_s *b_pot;
    struct button_s *b_big_pot;
    struct button_s *b_armor;
    struct button_s *b_sword;
    sfFont *font;
    sfText *title;
    sfText *inventory;
    struct text_nb *stage;
    struct text_nb *lvl;
    struct text_nb *ad;
    struct text_nb_max *hp;
    struct text_nb_max *xp;
    sfSprite *chara;
    sfTexture *text_chara;
    sfIntRect *rect;
};

struct info_hero {
    int life_hero;
    int max_life;
    int attack;
    int lvl;
    int stage;
    int curr_xp;
    int max_xp;
    int nb_pot;
    int nb_big_pot;
    int nb_armor;
    int nb_sword;
    bool can_go_next;
    bool quest;
    bool with_pnj;
    bool load_new_lvl;
    bool end;
    bool start_lvl_up;
    bool lvl_up;
};

struct mains {
    sfRenderWindow *window;
    sfView *view;
    sfVector2f move;
    sfVector2f window_size;
    sfVector2f sprites_nb;
    sfFloatRect map_size;
    sfIntRect rect1;
    sfIntRect rect2;
    sfIntRect rect3;
    sfEvent event;
    float zoom;
    sfVector2f player_pos;
    struct gettimes gettime;
    struct gettimes gettime_move;
    struct assets background;
    struct assets player;
    struct arrows arrow;
    struct info_hero *ih;
};

struct pnj_monster {
    struct pnj **pnj;
    struct enemy_map **m_e;
};

struct pnj {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect *rect;
    sfClock *clock;
    sfTime time;
    int direction;
    int nb_step;
    int max_step;
    int size_step;
    int speed;
    int nb_dir;
    bool alive;
    sfSprite *chara;
    sfTexture *text_chara;
    sfIntRect *rect_chara;
};

struct enemy_map {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect *rect;
    sfClock *clock;
    sfTime time;
    int direction;
    int nb_step;
    int max_step;
    int size_step;
    int speed;
    int nb_dir;
    bool alive;
};

struct health_bar {
    double life;
    double dmg;
    sfText *text;
    sfRectangleShape *health;
    sfRectangleShape *damage;
};

struct enemy {
    int type;
    sfSprite *sprite;
    sfIntRect rect;
    sfTexture *texture;
    sfClock *clock;
    sfTime time;
    int seconds;
    struct health_bar *health;
    struct attacks *attacks;
    int dir;
};

struct all_enemies {
    struct enemy *enemy1;
    struct enemy *enemy2;
    struct enemy *enemy3;
    struct enemy *enemy4;
    struct enemy *enemy5;
    struct enemy *boss;
};

struct game {
    struct fight *fight;
    struct all_enemies *enemies;
    struct map *map;
    struct character *character;
    struct menu *menu;
    struct music *music;
};

struct item {
    sfVector2f size;
    sfVector2f pos;
    struct button *button;
    sfText *nb;
    int potion;
    double dgt;
};

struct items {
    bool has_shoes;
    int level_shoes;
    bool has_sword;
    int level_sword;
    bool has_scepter;
    int level_scepter;
    struct item *potion_100hp;
    struct item *potion_200hp;
};

struct attack {
    bool spell;
    bool has_attack;
    bool state;
    int damage;
    struct button *text;
    sfVector2f text_size;
    sfVector2f text_pos;
    sfSprite *sprite;
    sfIntRect rect;
    sfTexture *texture;
    sfClock *clock;
    sfTime time;
    int seconds;
};

struct attacks {
    struct attack *basic_physic;
    struct attack *basic_spell;
    struct attack *kick;
    struct attack *spell2;
};

struct character {
    sfSprite *sprite_character;
    sfIntRect rect;
    sfTexture *text_character;
    sfClock *clock;
    sfTime time;
    int seconds;
    struct health_bar *health;
    struct items *items;
    struct attacks *attacks;
};

#endif
