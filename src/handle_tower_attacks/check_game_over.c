/*
** Twi-Fight
** 
** File description:
** check_game_over
*/

#include "game.h"

void check_game_over(game_t *game, life_t *life)
{
    if (!life) {
        game->state = GAME_STATE_GAME_OVER;
    }
}