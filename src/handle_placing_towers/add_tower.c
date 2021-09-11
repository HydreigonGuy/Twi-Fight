/*
** Twi-Fight
** 
** File description:
** add_tower
*/

#include "game.h"

void add_tower(playing_t *game_info, int x, int y)
{
    tower_t *tower = game_info->tower;

    if (!game_info->tower)
        game_info->tower = fill_tower(game_info->tower_selected, x, y);
    else {
        for (; tower && tower->next; tower = tower->next);
        tower->next = fill_tower(game_info->tower_selected, x, y);
    }
}