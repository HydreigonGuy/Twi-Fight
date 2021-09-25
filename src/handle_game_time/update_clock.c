/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** update_clock
*/

#include "game.h"

void update_clock(game_time_t *clock)
{
    sfTime time = sfClock_getElapsedTime(clock->clock);

    clock->time_elapsed = time.microseconds - clock->time.microseconds;
    clock->time = time;
}