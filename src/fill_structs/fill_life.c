/*
** Twi-Fight
** 
** File description:
** fill_life
*/

#include "game.h"
#include "ad_lib.h"
#include <stdlib.h>

life_t *fill_life(int x)
{
    life_t *life;

    life = malloc(sizeof(life_t));
    if (!life)
        return (NULL);
    life->spr = fill_sprite(my_str_concat(IMAGE_PATH, "life.png"), x, 610);
    if (!life->spr)
        return (NULL);
    life->next = NULL;
    return (life);
}