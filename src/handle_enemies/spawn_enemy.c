/*
** Twi-Fight
** 
** File description:
** spawn_enemy
*/

#include "game.h"

void spawn_enemy(int id, int x, enemy_t **enemy)
{
    enemy_t *hold = *enemy;

    if (!hold) {
        *enemy = fill_enemy(id, x - 100);
    } else {
        for (; hold && hold->next; hold = hold->next);
        hold->next = fill_enemy(id, x - 100);
    }
}