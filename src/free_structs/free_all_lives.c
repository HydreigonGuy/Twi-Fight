/*
** Twi-Fight
** 
** File description:
** free_all_lives
*/

#include "game.h"
#include <stdlib.h>

void free_all_lives(life_t *life)
{
    life_t *hold = NULL;

    while (life) {
        hold = life;
        life = life->next;
        free_sprite(hold->spr);
        free(hold);
    }
}