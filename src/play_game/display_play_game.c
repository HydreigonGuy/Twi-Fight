/*
** Twi-Fight
** 
** File description:
** display_play_game
*/

#include "game.h"

typedef sfRenderWindow window_t;
typedef game_time_t clk_t;

void display_play_game(window_t *wdw, clk_t *clk, scene_t *scn, playing_t *gi)
{
    button_t *btn = scn->btn;
    background_t *bg = scn->bg;
    tower_t *towers = gi->tower;
    int rect_num = calculate_rect_number(sfClock_getElapsedTime(clk->clock));

    sfRenderWindow_clear(wdw, sfBlack);
    for (; bg; bg = bg->next)
        sfRenderWindow_drawSprite(wdw, bg->spr->spr, NULL);
    for (; towers; towers = towers->next) {
        rerect_sprites(towers->spr, rect_num);
        sfRenderWindow_drawSprite(wdw, towers->spr->spr, NULL);
    }
    for (; btn; btn = btn->next) {
        sfSprite_setTextureRect(btn->spr->spr, btn->spr->r);
        sfRenderWindow_drawSprite(wdw, btn->spr->spr, NULL);
    }
    sfRenderWindow_display(wdw);
}