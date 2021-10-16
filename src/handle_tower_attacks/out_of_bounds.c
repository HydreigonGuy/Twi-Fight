/*
** Twi-Fight
** 
** File description:
** out_of_bounds
*/

#include "game.h"

int out_of_bounds(sprite_t *spr, int id)
{
    if (id == -1 && spr->crds.y > 0)
        return (0);
    if (spr->crds.x < 0 || spr->crds.y < 0)
        return (1);
    if (spr->crds.x + spr->r.width > 1000 ||
        spr->crds.y + spr->r.height > 600)
        return (1);
    return (0);
}