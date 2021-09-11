/*
** Twi-Fight
** 
** File description:
** fill_game_time
*/

#include "game.h"
#include <stdlib.h>

game_time_t *fill_game_time(void)
{
    game_time_t *clock = NULL;

    //clock = malloc(sizeof(game_time_t));
    //if (!clock)
        return (NULL);
    clock->clock = sfClock_create();
    return (clock);
}