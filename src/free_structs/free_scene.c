/*
** Twi-Fight
** 
** File description:
** free_scene
*/

#include "game.h"
#include <stdlib.h>

void free_scene_btn(button_t *scene_btn)
{
    button_t *btn = scene_btn;

    while (btn && btn->next) {
        for (; btn && btn->next && btn->next->next; btn = btn->next);
        free_sprite(btn->next->spr);
        free(btn->next);
        btn->next = NULL;
        btn = scene_btn;
    }
    if (btn) {
        free_sprite(btn->spr);
        free(btn);
    }
}

void free_scene_bg(background_t *scene_bg)
{
    background_t *bg = scene_bg;

    while (bg && bg->next) {
        for (; bg && bg->next && bg->next->next; bg = bg->next);
        free_sprite(bg->next->spr);
        free(bg->next);
        bg->next = NULL;
        bg = scene_bg;
    }
    if (bg) {
        free_sprite(bg->spr);
        free(bg);
    }
}

void free_scene(scene_t *scene)
{
    free_scene_btn(scene->btn);
    free_scene_bg(scene->bg);
    free(scene);
}