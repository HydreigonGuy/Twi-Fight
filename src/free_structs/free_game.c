/*
** Twi-Fight
** 
** File description:
** free_game
*/

#include "game.h"
#include <stdlib.h>

void free_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    free_game_time(game->clock);
    free(game->mouse);
    free(game);
}