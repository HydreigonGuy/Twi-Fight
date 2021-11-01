/*
** Twi-Fight
** 
** File description:
** display_scene
*/

#include "game.h"

void display_scene(sfRenderWindow *window, scene_t *scene)
{
    button_t *btn = scene->btn;
    background_t *bg = scene->bg;

    sfRenderWindow_clear(window, sfBlack);
    for (; bg; bg = bg->next)
        sfRenderWindow_drawSprite(window, bg->spr->spr, NULL);
    for (; btn; btn = btn->next) {
        sfSprite_setTextureRect(btn->spr->spr, btn->spr->r);
        sfRenderWindow_drawSprite(window, btn->spr->spr, NULL);
    }
    sfRenderWindow_display(window);
}