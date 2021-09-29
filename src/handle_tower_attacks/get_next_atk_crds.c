/*
** Twi-Fight
** 
** File description:
** get_next_atk_crds
*/

#include "game.h"

void get_next_atk_crds(attack_t *atk, int elapsed_time)
{
    atk->spr->crds.y -= (elapsed_time * atk->spd) / ATTACK_SPD_LIMITTER;
}