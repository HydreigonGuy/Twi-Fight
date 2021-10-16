/*
** Twi-Fight
** 
** File description:
** spawn_all_wolves
*/

#include "game.h"

attack_t *spawn_all_wolves(void)
{
    attack_t *first_wolf = NULL;
    attack_t *next_wolf = NULL;
    int count = 0;

    first_wolf = fill_wolf(count);
    if (!fill_wolf)
        return (NULL);
    count++;
    for (next_wolf = first_wolf; count < 5; count++,
        next_wolf = next_wolf->next) {
        next_wolf->next = fill_wolf(count);
        if (!next_wolf->next)
            return (NULL);
    }
    return (first_wolf);
}