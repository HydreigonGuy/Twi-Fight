/*
** Twi-Fight
** 
** File description:
** mouse_reset
*/

#include "game.h"

void mouse_reset(mouse_t *mouse)
{
    mouse->x = -1;
    mouse->y = -1;
    mouse->p_x = -1;
    mouse->p_y = -1;
    mouse->r_x = -1;
    mouse->r_y = -1;
}