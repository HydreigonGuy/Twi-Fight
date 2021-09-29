/*
** Twi-Fight
** 
** File description:
** get_tower_path
*/

#include "game.h"

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