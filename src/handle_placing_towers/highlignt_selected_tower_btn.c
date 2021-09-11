/*
** Twi-Fight
** 
** File description:
** highlignt_selected_tower_btn
*/

#include "game.h"

void highlignt_selected_tower_btn(int selected, button_t *btn)
{
    button_t *hold = btn;

    for (int i = 1; i < selected; i++, hold = hold->next);
    hold->spr->r.left = 2 * hold->spr->r.width;
}