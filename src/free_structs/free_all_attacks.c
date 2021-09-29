/*
** Twi-Fight
** 
** File description:
** free_all_attacks
*/

#include "game.h"
#include <stdlib.h>

void free_all_attacks(attack_t *atk)
{
    attack_t *hold = NULL;

    while (atk) {
        hold = atk;
        atk = atk->next;
        free_sprite(hold->spr);
        free(hold);
    }
}