/*
** Twi-Fight
** 
** File description:
** fill_tower
*/

#include "game.h"
#include "ad_lib.h"
#include <stdlib.h>

tower_t *fill_tower(int selected, int x, int y)
{
    tower_t *tower = NULL;

    tower = malloc(sizeof(tower_t));
    if (!tower)
        return (NULL);
    tower->spr = fill_sprite(my_str_concat(IMAGE_PATH,
        get_tower_path(selected)), x - 50, y - 50);
    fill_rect(tower->spr, 100, 100);
    tower->id = selected;
    tower->atk = get_tower_atk(selected);
    tower->spd = get_tower_spd(selected);
    tower->cooldown = 0;
    tower->max_cooldown = get_tower_max_cd(selected);
    tower->next = NULL;
    return (tower);
}