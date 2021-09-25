/*
** Twi-Fight
** 
** File description:
** reset_game_time
*/

#include "game.h"

void reset_game_time(game_time_t *clock)
{
    sfClock_restart(clock->clock);
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->time_elapsed = 0;
}