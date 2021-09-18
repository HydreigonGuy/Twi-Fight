/*
** Twi-Fight
** 
** File description:
** rerect_sprites
*/

#include "game.h"

void rerect_sprites(sprite_t *spr, int rect_number)
{
    spr->r.left = spr->r.width * rect_number;
    sfSprite_setTextureRect(spr->spr, spr->r);
}