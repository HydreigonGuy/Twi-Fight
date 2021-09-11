/*
** Twi-Fight
** 
** File description:
** mouse_pressed_button
*/

#include "game.h"

int mouse_pressed_button(mouse_t *m, button_t *btn)
{
    if (btn->spr->crds.x > m->p_x)
        return (0);
    if (btn->spr->crds.x + btn->spr->r.width < m->p_x)
        return (0);
    if (btn->spr->crds.y > m->p_y)
        return (0);
    if (btn->spr->crds.y + btn->spr->r.height < m->p_y)
        return (0);
    return (1);
}