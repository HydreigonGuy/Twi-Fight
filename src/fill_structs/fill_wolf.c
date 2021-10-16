/*
** Twi-Fight
** 
** File description:
** fill_wolf
*/

#include "game.h"
#include "ad_lib.h"
#include <stdlib.h>

attack_t *fill_wolf(int count)
{
    attack_t *atk = NULL;

    atk = malloc(sizeof(attack_t));
    if (!atk)
        return (NULL);
    atk->spr = fill_sprite(my_str_concat(IMAGE_PATH,
        "good/wolf_attack.png"), count * 200, 600 + rand() % 100);
    fill_rect(atk->spr, 125, 250);
    atk->spr->r.left = 125 * (rand() % 4);
    sfSprite_setTextureRect(atk->spr->spr, atk->spr->r);
    atk->id = WOLF_ID;
    atk->atk = WOLF_ATTACK;
    atk->spd = WOLF_SPEED;
    atk->direction = 0;
    atk->next = NULL;
    return (atk);
}