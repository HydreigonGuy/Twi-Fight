/*
** Twi-Fight
** 
** File description:
** fill_background
*/

#include "game.h"
#include <stdlib.h>

background_t *get_next_background(char *file, int x, int y)
{
    background_t *bg = NULL;

    bg = malloc(sizeof(background_t));
    if (!bg)
        return (NULL);
    bg->spr = fill_sprite(file, x, y);
    bg->next = NULL;
    bg->x = x;
    bg->y = y;
    return (bg);
}

void fill_background(background_t **bg, char *file, int x, int y)
{
    background_t *hold_bg = *bg;

    if (!hold_bg) {
        *bg = get_next_background(file, x, y);
    } else {
        for (; hold_bg && hold_bg->next; hold_bg = hold_bg->next);
        hold_bg->next = get_next_background(file, x, y);
    }
}