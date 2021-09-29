/*
** Twi-Fight
** 
** File description:
** free_all_towers
*/

#include "game.h"
#include <stdlib.h>

void free_all_towers(tower_t *tower)
{
    tower_t *hold = NULL;

    while (tower) {
        hold = tower;
        tower = tower->next;
        free_sprite(hold->spr);
        free(hold);
    }
}