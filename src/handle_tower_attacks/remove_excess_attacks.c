/*
** Twi-Fight
** 
** File description:
** remove_excess_attacks
*/

#include "game.h"
#include <stdlib.h>

void remove_excess_attacks(attack_t **atk)
{
    attack_t *hold = *atk;
    attack_t *to_delete = NULL;

    while (hold && out_of_bounds(hold->spr, hold->id)) {
        *atk = hold->next;
        free_sprite(hold->spr);
        free(hold);
        hold = *atk;
    }
    for (; hold && hold->next; hold = hold->next)
        if (out_of_bounds(hold->next->spr, hold->next->id)) {
            to_delete = hold->next;
            hold->next = hold->next->next;
            free_sprite(to_delete->spr);
            free(to_delete);
        }
}