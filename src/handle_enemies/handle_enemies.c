/*
** Twi-Fight
** 
** File description:
** handle_enemies
*/

#include "game.h"

void handle_enemies(int clock, playing_t *game_info)
{
    if (game_info->spawn_var < 0 && !game_info->dialog[1])
        fill_enemy_dialog(game_info);
    move_enemies(clock, game_info);
    spawn_enemies(game_info);
}