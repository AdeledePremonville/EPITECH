/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** struct
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Export.h>

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct defender {
    sfSprite *sprite_map;
    sfTexture *text_map;
    sfSprite *sprite_counter[5];
    sfTexture *text_counter;
    sfIntRect rect_counter[5];
    sfVector2f position_counter[5];
    sfSprite *sprite_coin;
    sfTexture *text_coin;
    sfVector2f position_coin;
    sfClock *clock_counter;
    sfClock *clock_counter2;
    sfSprite *sprite_square;
    sfTexture *text_square;
    sfVector2f position_square;
}defender;

typedef struct characters {
    sfSprite *sprite_dragon_walk[10];
    sfSprite *sprite_demon_walk[10];
    sfSprite *sprite_lizard_walk[10];
    sfTexture *text_dragon_walk;
    sfTexture *text_demon_walk;
    sfTexture *text_lizard_walk;
    sfIntRect rect_dragon_walk[10];
    sfIntRect rect_demon_walk[10];
    sfIntRect rect_lizard_walk[10];
    sfVector2f position_dragon_walk[10];
    sfVector2f position_demon_walk[10];
    sfVector2f position_lizard_walk[10];
    sfClock *clock_dragon_walk;
    sfClock *clock_demon_walk;
    sfClock *clock_lizard_walk;
    sfClock *clock_spawn;
    int *step_dragon[10];
    int *step_demon[10];
    int *step_lizard[10];
    int dragon;
    int demon;
    int lizard;
    int **spawn;
    int life_dragon[10];
    int life_demon[10];
    int life_lizard[10];
}characters;

typedef struct attack {
    sfSprite *sprite_dragon_attack[10];
    sfSprite *sprite_fire[10];
    sfSprite *sprite_demon_attack[10];
    sfSprite *sprite_lizard_attack[10];
    sfTexture *text_dragon_attack;
    sfTexture *text_fire;
    sfTexture *text_demon_attack;
    sfTexture *text_lizard_attack;
    sfIntRect rect_dragon_attack[10];
    sfIntRect rect_fire[10];
    sfIntRect rect_demon_attack[10];
    sfIntRect rect_lizard_attack[10];
    sfVector2f position_dragon_attack[10];
    sfVector2f position_fire[10];
    sfVector2f position_demon_attack[10];
    sfVector2f position_lizard_attack[10];
    sfClock *clock_dragon_attack;
    sfClock *clock_demon_attack;
    sfClock *clock_demon_attack2;
    sfClock *clock_lizard_attack;
    int dragon_attack;
    int demon_attack;
    int lizard_attack;
}attack;

typedef struct buildings {
    sfSprite *sprite_wall[3];
    sfTexture *text_wall[3];
    sfVector2f position_wall[3];
    sfSprite *sprite_sniper[3];
    sfTexture *text_sniper[3];
    sfVector2f position_sniper[3];
    sfSprite *sprite_roblox[3];
    sfTexture *text_roblox[3];
    sfVector2f position_roblox[3];
    sfSprite *sprite_tesla[3];
    sfTexture *text_tesla[3];
    sfVector2f position_tesla[3];
    sfSprite *sprite_shadow[2];
    sfTexture *text_shadow;
    sfVector2f position_shadow[2];
    sfClock *clock_end;
    sfClock *clock_tesla;
    sfClock *clock_sniper;
    sfClock *clock_roblox;
    sfClock *clock_timer;
    sfClock *clock_timer2;
    int **step;
    int *walk_dragon[10];
    int *walk_demon[10];
    int *walk_lizard[10];
    int life_base;
    int end;
    int money;
}buildings;

typedef struct square {
    sfSprite *sprite_square[4];
    sfTexture *text_square[4];
    sfVector2f position_square[4];
}square;

int money_counter(struct defender *def, sfRenderWindow *window, struct \
characters *c, struct attack *a, struct buildings *b, struct square *s);
void draw_init(sfRenderWindow *window, struct defender *def, \
struct square *s, struct buildings *b);
void sprite_init(struct defender *def);
void money_counter_rect(struct defender *def);
void analyse_events(sfRenderWindow *window, sfEvent event, struct defender \
*def, struct characters *c, struct buildings *b, struct attack *a, \
struct square *s);
sfRenderWindow *createWindow(int width, int heigth);
void dragon_walk_rect(struct characters *c);
void demon_walk_rect(struct characters *c);
void lizard_walk_rect(struct characters *c);
void sprite_characters_walk_init(struct characters *c);
void walk_on_map_dragon(struct characters *c, struct buildings *b, int i);
void walk_on_map_demon(struct characters *c, struct buildings *b, int i);
void walk_on_map_lizard(struct characters *c, struct buildings *b, int i);
void free_main(struct defender *def, struct characters *c, \
struct attack *a, struct buildings *b, struct square *s);
void walk_on_map2_dragon(struct characters *c, struct buildings *b, int i);
void walk_on_map2_demon(struct characters *c, struct buildings *b, int i);
void walk_on_map2_lizard(struct characters *c, struct buildings *b, int i);
int draw_dragon_init(sfRenderWindow *window, struct characters *c, \
struct attack *a, struct buildings *b, int i);
int draw_demon_init(sfRenderWindow *window, struct characters *c, \
struct attack *a, struct buildings *b, int i);
int draw_lizard_init(sfRenderWindow *window, struct characters *c, \
struct attack *a, struct buildings *b, int i);
void set_init(struct characters *c);
void dragon_attack(struct characters *c, struct attack *a, struct buildings *b, int i);
void demon_attack(struct characters *c, struct attack *a, struct buildings *b, int i);
void lizard_attack(struct characters *c, struct attack *a, struct buildings *b, int i);
void dragon_attack_rect(struct attack *a, struct characters *c);
void demon_attack_rect(struct attack *a);
void lizard_attack_rect(struct attack *a);
void fire_rect(struct attack *a);
void all_init(struct defender *def, struct characters *c, \
struct attack *a, struct buildings *b, struct square *s);
void click_drop(sfMouseButtonEvent event, struct buildings *b, \
struct defender *def);
void buildings_sprite_init(struct buildings *b);
void wall_drop(sfMouseButtonEvent event, struct buildings *b, \
struct defender *def);
void attack_pos(struct attack *a, struct buildings *b, struct characters *c, int i);
void square_init(struct square *s);
void square_pos(struct square *s);
void buildings_square_init(struct buildings *b);
void buildings_square_pos(struct buildings *b);
void clock_init(struct defender *def, struct characters *c, \
struct attack *a, struct buildings *b);
void ennemies_spawn(struct attack *a, struct buildings *b, struct characters *c);
void attack_pos_dragon(struct attack *a, struct buildings *b, \
struct characters *c, int i);
void attack_pos_demon(struct attack *a, struct buildings *b, \
struct characters *c, int i);
void attack_pos_lizard(struct attack *a, struct buildings *b, \
struct characters *c, int i);
int dragon_spawn(sfRenderWindow *window, struct characters *c, \
struct attack *a, struct buildings *b);
int demon_spawn(struct characters *c, struct attack *a, struct buildings *b);
int lizard_spawn(struct characters *c, struct attack *a, struct buildings *b);
void sprite_characters_attack_init(struct attack *a);
void set_attack_init(struct attack *a);
int spawn_random(void);
void end_game(struct buildings *b, struct defender *def, sfRenderWindow *w);
int roblox_shoot(struct characters *c, struct buildings *b);
int tesla_shoot(struct characters *c, struct buildings *b);
int sniper_shoot(struct characters *c, struct buildings *b);
void roblox_damage(struct buildings *b, struct characters *c, int i);
void sniper_damage(struct buildings *b, struct characters *c, int i);
void tesla_damage(struct buildings *b, struct characters *c, int i);
void timer(struct defender *def);
void set_shadow(sfRenderWindow *window, struct buildings *b);
void shadow(sfRenderWindow *window, struct buildings *b);

#endif /* !STRUCT_H_ */