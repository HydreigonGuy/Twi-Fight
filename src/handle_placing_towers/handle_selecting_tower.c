/*
** Twi-Fight
** 
** File description:
** handle_selecting_tower
*/

#include "game.h"

void handle_selecting_tower(int *state, playing_t *game_info)
{
    if (*state - 9 == game_info->tower_selected) {
        game_info->tower_selected = 0;
    } else {
        game_info->tower_selected = *state - 9;
    }
    *state = 0;
}