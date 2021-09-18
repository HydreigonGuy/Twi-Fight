/*
** Twi-Fight
** 
** File description:
** calculate_rect_number
*/

#include "game.h"

int calculate_rect_number(sfTime time)
{
    int rect_number = time.microseconds / 50000;

    if (rect_number % 40 > 10 && rect_number % 40 < 20)
        return (0);
    if (rect_number % 40 > 30)
        return (2);
    return (1);
}