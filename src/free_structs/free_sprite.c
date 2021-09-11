/*
** Twi-Fight
** 
** File description:
** free_sprite
*/

#include "game.h"
#include <stdlib.h>

void free_sprite(sprite_t *spr)
{
    sfSprite_destroy(spr->spr);
    sfTexture_destroy(spr->txtr);
    free(spr);
}