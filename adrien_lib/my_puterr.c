/*
** EPITECH PROJECT, 2020
** Adrien Lib
** File description:
** my_puterr
*/

#include "ad_lib.h"
#include <unistd.h>

int my_puterr(char *str)
{
    write(2, str, my_strlen(str));
}
