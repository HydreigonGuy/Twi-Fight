/*
** Twi-Fight
** 
** File description:
** free_one_life
*/

#include "game.h"
#include <stdlib.h>

void free_one_life(life_t **life)
{
    life_t *hold = *life;

    if (!hold)
        return;
    if (!hold->next) {
        free_sprite(hold->spr);
        free(hold);
        *life = NULL;
        return;
    }
    for (; hold->next && hold->next->next; hold = hold->next);
    free_sprite(hold->next->spr);
    free(hold->next);
    hold->next = NULL;
}