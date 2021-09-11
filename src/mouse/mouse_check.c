/*
** Twi-Fight
** 
** File description:
** mouse_check
*/

#include "game.h"

void mouse_check(button_t *btn, game_t *game)
{
    button_t *hold = btn;

    for (int i = 0; hold; hold = hold->next, i++) {
        hold->state = 0;
        if (mouse_on_button(game->mouse, hold))
            hold->state = 1;
        if (mouse_pressed_button(game->mouse, hold))
            hold->state = 2;
        if (mouse_released_on_button(game->mouse, hold))
            game->state = 10 + i;
        hold->spr->r.left = hold->state * hold->spr->r.width;
    }
}