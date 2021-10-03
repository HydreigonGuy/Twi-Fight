/*
** Twi-Fight
** 
** File description:
** check_for_atk_colision
*/

#include "game.h"

int check_for_atk_colision(playing_t *gi, attack_t *at, enemy_t *en)
{
    if (at->spr->crds.x + at->spr->r.height >= en->spr->crds.x +
    ENEMY_COLLISION_TOLERENCE && at->spr->crds.y + at->spr->r.width >=
    en->spr->crds.y + ENEMY_COLLISION_TOLERENCE && at->spr->crds.x -
    at->spr->r.height <= en->spr->crds.x - ENEMY_COLLISION_TOLERENCE
    + en->spr->r.height && at->spr->crds.y - at->spr->r.width <=
    en->spr->crds.y + en->spr->r.width - ENEMY_COLLISION_TOLERENCE) {
        en->hp -= at->atk;
        if (en->hp < 0)
            free_one_enemy(gi, en);
        free_one_attack(gi, at);
        return (1);
    }
    return (0);
}