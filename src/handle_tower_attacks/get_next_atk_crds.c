/*
** Twi-Fight
** 
** File description:
** get_next_atk_crds
*/

#include "game.h"

void get_next_atk_crds(attack_t *atk, int e_time, int enemy_x)
{
    if (atk->id == 1) {
        if (atk->direction)
            atk->spr->crds.y += (e_time * atk->spd) / ATTACK_SPD_LIMITTER;
        else
            atk->spr->crds.y -= (e_time * atk->spd) / ATTACK_SPD_LIMITTER;
    }
    if (atk->id == 2)
        atk->spr->crds.y -= (e_time * atk->spd) / ATTACK_SPD_LIMITTER;
    if (atk->id == 3 || atk->id == 4) {
        if (enemy_x - atk->spr->crds.x < 0)
            atk->spr->crds.x -= (atk->spd * e_time) / (ATTACK_SPD_LIMITTER);
        else
            atk->spr->crds.x += (atk->spd * e_time) / (ATTACK_SPD_LIMITTER);
        if (ENEMY_Y - atk->spr->crds.y < 0)
            atk->spr->crds.y -= (e_time * atk->spd) / (ATTACK_SPD_LIMITTER);
        else
            atk->spr->crds.y += (e_time * atk->spd) / (ATTACK_SPD_LIMITTER);
    }
}