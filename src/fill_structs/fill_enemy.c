/*
** Twi-Fight
** 
** File description:
** fill_enemy
*/

#include "game.h"
#include "ad_lib.h"
#include <stdlib.h>

enemy_t *fill_enemy(int id, int x)
{
    enemy_t *enemy = NULL;

    enemy = malloc(sizeof(enemy_t));
    if (!enemy)
        return (NULL);
    enemy->hp = 100;
    enemy->spd = 4;
    enemy->spr = fill_sprite(my_str_concat(IMAGE_PATH, "evil/vmp_spr.png"), x, ENEMY_Y);
    fill_rect(enemy->spr, 100, 100);
    enemy->next = NULL;
    return (enemy);
}