/*
** Twi-Fight
** 
** File description:
** handle_ingame_events
*/

#include "game.h"

void handle_ingame_events(extra_events_t event, playing_t *game_info)
{
    if (event.space_bar_press && game_info->spawn_var < 0
        && !game_info->enemy) {
        game_info->spawn_var = game_info->spawn_var * -1;
        if (game_info->dialog[1]) {
            free_sprite(game_info->dialog[1]);
            game_info->dialog[1] = NULL;
        }
        if (game_info->dialog[2]) {
            free_sprite(game_info->dialog[2]);
            game_info->dialog[2] = NULL;
        }
    }
}