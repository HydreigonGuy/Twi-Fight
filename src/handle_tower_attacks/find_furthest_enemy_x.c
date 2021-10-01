/*
** Twi-Fight
** 
** File description:
** find_furthest_enemy_x
*/

#include "game.h"

int find_furthest_enemy_x(enemy_t *enemy)
{
    int x = 0;

    for (enemy_t *hold = enemy; hold; hold = hold->next)
        if (hold->spr->crds.x > x)
            x = hold->spr->crds.x;
    return (x);
}