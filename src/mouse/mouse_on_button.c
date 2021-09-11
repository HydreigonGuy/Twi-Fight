/*
** Twi-Fight
** 
** File description:
** mouse_on_button
*/

#include "game.h"

int mouse_on_button(mouse_t *m, button_t *btn)
{
    if (btn->spr->crds.x > m->x)
        return (0);
    if (btn->spr->crds.x + btn->spr->r.width < m->x)
        return (0);
    if (btn->spr->crds.y > m->y)
        return (0);
    if (btn->spr->crds.y + btn->spr->r.height < m->y)
        return (0);
    return (1);
}