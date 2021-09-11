/*
** Twi-Fight
** 
** File description:
** free_game_time
*/

#include "game.h"
#include <stdlib.h>

void free_game_time(game_time_t *clock)
{
    if (!clock)
        return;
    if (clock->clock) {
        sfClock_destroy(clock->clock);
    }
    free(clock);
}