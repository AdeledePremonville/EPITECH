/*
** EPITECH PROJECT, 2022
** pause.h
** File description:
** pause_h - my_defender
*/

#ifndef PAUSE_H
    #define PAUSE_H

typedef struct obj_pause_t
{
    sfRenderWindow *window;
    sfEvent event;
    sfSprite *button_start;
    sfSprite *button_exit;
    sfSprite *button_resume;
    sfIntRect button_rect;
    sfIntRect button_click_rect;
    sfIntRect hover_rect;
    int state;
} obj_pause_t;

typedef struct scale_pause_t
{
    sfVector2f scale;
    sfVector2f scale_pause;
    sfVector2f pos_start;
    sfVector2f pos_resume;
    sfVector2f pos_pause;
    sfVector2f pos_exit;
} scale_pause_t;

typedef struct pause_comp_t
{
    text_t *start;
    text_t *exit;
    text_t *resume;
    text_t *pause;
    sfFont *pixel;
} pause_comp_t;


void pause_menu(sfRenderWindow *window);

void events_pause(obj_pause_t *o, struct defender *d, pause_comp_t *c);

obj_pause_t *init_obj_pause(sfRenderWindow *window);

void init_sprite_pause(obj_pause_t *obj);

scale_pause_t *init_scale_pause();

pause_comp_t *init_comp_pause(scale_pause_t *s);

int hover_pause(obj_pause_t *obj);

void click_pause(obj_pause_t *obj);

void free_pause(pause_comp_t *comp, struct defender *def, obj_pause_t *obj);

void free_comp(pause_comp_t *comp);

void free_obj(obj_pause_t *obj);

void draw_pause(obj_pause_t *obj, struct defender *def, pause_comp_t *comp);

void close_pause(obj_pause_t *obj, pause_comp_t *comp, struct defender *def);

int hover_state(obj_pause_t *obj);

#endif /* !PAUSE_H */
