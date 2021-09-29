/*
** Twi-Fight
** 
** File description:
** free_all_enemies
*/

#include "game.h"
#include <stdlib.h>

void free_all_enemies(enemy_t *enemy)
{
    enemy_t *hold = NULL;

    while (enemy) {
        hold = enemy;
        enemy = enemy->next;
        free_sprite(hold->spr);
        free(hold);
    }
}