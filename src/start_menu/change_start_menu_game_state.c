/*
** Twi-Fight
** 
** File description:
** change_start_menu_game_state
*/

#include "game.h"

void change_start_menu_game_state(game_t *game)
{
    if (game->state == 10)
        game->state = GAME_STATE_PLAY_GAME;
    if (game->state == 11)
        game->state = GAME_STATE_EXIT;
}