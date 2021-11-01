/*
** Twi-Fight
** 
** File description:
** fill_game_lives
*/

#include "game.h"

life_t *fill_game_lives(void)
{
    life_t *life = NULL;
    life_t *temp = NULL;

    life = fill_life(720);
    if (!life)
        return (NULL);
    temp = life;
    for (int i = 1; i < GAME_LIVES; i++, temp = temp->next) {
        temp->next = fill_life(720 + i * 50);
        if (!temp->next)
            return (life);
    }
    return (life);
}