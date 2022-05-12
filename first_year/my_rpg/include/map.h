/*
** EPITECH PROJECT, 2021
** map.h
** File description:
** map .h
*/

#ifndef _MAP_H
    #define _MAP_H

    #include "p.h"

    #define FLOOR 1
    #define WALL 2
    #define DOOR 3
    #define CUSTOM 4

typedef struct enemy_t {
    unsigned int hp;
    unsigned int speed;
    sfSprite *sprite;
} enemy_s;

struct enemies {
    unsigned int size;
    enemy_s **enemies;
};

struct sprite_ground_wall {
    sfSprite *sprite_ground;
    sfTexture *texture_ground;
    sfSprite *sprite_wall;
    sfTexture *texture_wall;
};

struct sprite_interactions {
    sfSprite *sprite_chest;
    sfTexture *texture_chest;
    sfSprite *sprite_pnj1;
    sfTexture *texture_pnj1;
};

struct map_info {
    unsigned int size_x;
    unsigned int size_y;
    unsigned short int level;
    int x_offset;
    int y_offset;
    int **rect_map;
    sfRectangleShape *diag_rec;
    sfText *diag_text;
    sfVector2f scale;
    sfSprite ***map;
    sfSprite ***walls;
    sfSprite ***items;
};

// map;
struct map_info *fill_map(void);
struct map_info *fill_map_sp(unsigned int x, unsigned int y, int lvl);
void create_map(struct map_info *mi);
int **create_rect_map(unsigned int x, unsigned int y);
void set_map_rects(struct map_info *mi);
int get_col(char **arr);
int get_line(char **arr);
void clean_struct(struct map_info *mi);
// Display
void display_map(struct map_info *mi, sfRenderWindow *win);
sfIntRect get_floor_rect(int index, struct map_info *mi);
void set_wall_top_rects(struct map_info *mi);
void display_walls(struct map_info *mi, sfRenderWindow *win);
void create_walls(struct map_info *mi);
void set_wall_top_rects(struct map_info *mi);
void set_wall_walls_rects(struct map_info *mi);
//Dialog
void create_dial_text(struct map_info *mi, sfRenderWindow *win, char *str,
struct mains *m);
void create_dial_bub(struct map_info *mi, sfRenderWindow *win,
struct mains *m);

#endif
