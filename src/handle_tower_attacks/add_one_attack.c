/*
** Twi-Fight
** 
** File description:
** add_one_attack
*/

#include "game.h"

void add_one_attack(attack_t **atk, tower_t *tower)
{
    attack_t *hold_atk = *atk;

    if (!hold_atk) {
        *atk = fill_attack(tower);
    } else {
        for (; hold_atk && hold_atk->next; hold_atk = hold_atk->next);
        hold_atk->next = fill_attack(tower);
    }
}