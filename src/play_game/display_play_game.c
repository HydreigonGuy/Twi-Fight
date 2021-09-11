/*
** Twi-Fight
** 
** File description:
** display_play_game
*/

#include "game.h"

void display_play_game(sfRenderWindow *window, scene_t *scene, playing_t *gi)
{
    button_t *btn = scene->btn;
    background_t *bg = scene->bg;
    tower_t *towers = gi->tower;

    sfRenderWindow_clear(window, sfBlack);
    for (; bg; bg = bg->next)
        sfRenderWindow_drawSprite(window, bg->spr->spr, NULL);
    for (; towers; towers = towers->next) {
        sfSprite_setTextureRect(towers->spr->spr, towers->spr->r);
        sfRenderWindow_drawSprite(window, towers->spr->spr, NULL);
    }
    for (; btn; btn = btn->next) {
        sfSprite_setTextureRect(btn->spr->spr, btn->spr->r);
        sfRenderWindow_drawSprite(window, btn->spr->spr, NULL);
    }
    sfRenderWindow_display(window);
}