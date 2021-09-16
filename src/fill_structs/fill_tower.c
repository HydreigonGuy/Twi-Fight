/*
** Twi-Fight
** 
** File description:
** fill_tower
*/

#include "game.h"
#include "ad_lib.h"
#include <stdlib.h>

char *get_tower_path(int i)
{
    if (i == 1)
        return ("good/knife_tower.png");
    if (i == 2)
        return ("good/chemist_tower.png");
    if (i == 3)
        return ("good/adrien_tower.png");
    if (i == 4)
        return ("good/roxane_tower.png");
}

int get_tower_atk(int i)
{
    if (i == 1)
        return (3);
    if (i == 2)
        return (3);
    if (i == 3)
        return (3);
    if (i == 4)
        return (3);
}

int get_tower_max_cd(int i)
{
    if (i == 1)
        return (100);
    if (i == 2)
        return (100);
    if (i == 3)
        return (100);
    if (i == 4)
        return (100);
}

tower_t *fill_tower(int selected, int x, int y)
{
    tower_t *tower = NULL;

    tower = malloc(sizeof(tower_t));
    if (!tower)
        return (NULL);
    tower->spr = fill_sprite(my_str_concat(IMAGE_PATH,
        get_tower_path(selected)), x - 50, y - 50);
    fill_rect(tower->spr, 100, 100);
    tower->atk = get_tower_atk(selected);
    tower->cooldown = 0;
    tower->max_cooldown = get_tower_max_cd(selected);
    tower->next = NULL;
    return (tower);
}