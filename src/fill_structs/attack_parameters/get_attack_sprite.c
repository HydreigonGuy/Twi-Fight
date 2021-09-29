/*
** Twi-Fight
** 
** File description:
** get_attack_sprite
*/

#include "game.h"

char *get_attack_sprite(int id)
{
    if (id == 1)
        return ("good/knife.png");
    if (id == 2)
        return ("good/cloud.png");
    if (id == 3)
        return ("good/donut.png");
    if (id == 4)
        return ("good/bullet.png");
}