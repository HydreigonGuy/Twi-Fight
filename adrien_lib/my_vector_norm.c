/*
** EPITECH PROJECT, 2021
** Adrien Lib
** File description:
** my_vector_norm
*/

#include "ad_lib.h"

int my_vector_norm(int x1, int y1, int x2, int y2)
{
    int result = (x1 - x2) * (x1 - x2);

    result = result + (y1 - y2) * (y1 - y2);
    return (my_square_root(result));
}