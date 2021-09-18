/*
** Twi-Fight
** 
** File description:
** check_if_can_place_tower
*/

#include "game.h"
#include "ad_lib.h"

int check_if_can_place_tower(mouse_t *mouse)
{
    if (mouse->r_x > 950 || mouse->r_y > 550)
        return (0);
    if (mouse->r_y < 300 && mouse->r_y > 150)
        return (0);
    if (my_vector_norm(mouse->r_x, mouse->r_y, 555, 618) < 190)
        return (0);
    return (1);
}