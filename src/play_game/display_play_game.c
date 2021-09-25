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
    int rect_num = calculate_rect_number(sfClock_getElapsedTime(clk->clock));

    sfRenderWindow_clear(wdw, sfBlack);
    for (background_t *bg = scn->bg; bg; bg = bg->next)
        sfRenderWindow_drawSprite(wdw, bg->spr->spr, NULL);
    for (enemy_t *enemy = gi->enemy; enemy; enemy = enemy->next) {
        rerect_sprites(enemy->spr, rect_num);
        sfRenderWindow_drawSprite(wdw, enemy->spr->spr, NULL);
    }
    for (tower_t *towers = gi->tower; towers; towers = towers->next) {
        rerect_sprites(towers->spr, rect_num);
        sfRenderWindow_drawSprite(wdw, towers->spr->spr, NULL);
    }
    for (button_t *btn = scn->btn; btn; btn = btn->next) {
        sfSprite_setTextureRect(btn->spr->spr, btn->spr->r);
        sfRenderWindow_drawSprite(wdw, btn->spr->spr, NULL);
    }
    if (gi->spawn_var < 0 && gi->dialog[1] && gi->dialog[2])
        for (int i = 0; i < 3; i++)
            sfRenderWindow_drawSprite(wdw, gi->dialog[i]->spr, NULL);
    sfRenderWindow_display(wdw);
}