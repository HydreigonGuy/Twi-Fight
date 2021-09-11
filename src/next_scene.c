/*
** Twi-Fight
** 
** File description:
** next_scene
*/

#include "game.h"

void next_scene(game_t *game)
{
    int current_state = game->state;
    game->state = 0;

    if (current_state == 0)
        game->state = GAME_STATE_EXIT;
    if (current_state == GAME_STATE_START_MENU)
        start_menu(game);
    if (current_state == GAME_STATE_PLAY_GAME)
        play_game(game);
}