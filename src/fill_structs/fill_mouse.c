/*
** Twi-Fight
** 
** File description:
** fill_mouse
*/

#include "game.h"
#include <stdlib.h>

mouse_t *fill_mouse(void)
{
    mouse_t *mouse = NULL;

    mouse = malloc(sizeof(mouse_t));
    if (!mouse)
        return (NULL);
    mouse->x = 0;
    mouse->y = 0;
    mouse->p_x = 0;
    mouse->p_y = 0;
    mouse->r_x = 0;
    mouse->r_y = 0;
    return (mouse);
}