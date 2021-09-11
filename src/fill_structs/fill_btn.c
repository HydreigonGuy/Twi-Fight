/*
** Twi-Fight
** 
** File description:
** fill_btn
*/

#include "game.h"
#include <stdlib.h>

button_t *get_next_btn(char *file, int x, int y)
{
    button_t *btn = NULL;

    btn = malloc(sizeof(button_t));
    if (!btn)
        return (NULL);
    btn->spr = fill_sprite(file, x, y);
    btn->state = 0;
    btn->next = NULL;
    return (btn);
}

void fill_btn(button_t **btn, char *file, int x, int y)
{
    button_t *hold_btn = *btn;

    if (!hold_btn) {
        *btn = get_next_btn(file, x, y);
    } else {
        for (; hold_btn && hold_btn->next; hold_btn = hold_btn->next);
        hold_btn->next = get_next_btn(file, x, y);
    }
}