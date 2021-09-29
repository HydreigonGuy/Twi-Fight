/*
** Twi-Fight
** 
** File description:
** fill_attack
*/

#include "game.h"
#include "ad_lib.h"
#include <stdlib.h>

attack_t *fill_attack(tower_t *tower)
{
    attack_t *atk = NULL;
    int size = get_attack_size(tower->id);

    atk = malloc(sizeof(attack_t));
    if (!atk)
        return (NULL);
    atk->spr = fill_sprite(my_str_concat(IMAGE_PATH,
        get_attack_sprite(tower->id)),
        tower->spr->crds.x + 50 - (size / 2),
        tower->spr->crds.y + 50 - (size / 2));
    fill_rect(atk->spr, size, size);
    atk->id = tower->id;
    atk->atk = tower->atk;
    atk->spd = tower->spd;
    atk->next = NULL;
    return (atk);
}