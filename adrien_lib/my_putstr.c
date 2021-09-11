/*
** EPITECH PROJECT, 2020
** Adrien Lib
** File description:
** my_putstr
*/

#include "ad_lib.h"
#include <unistd.h>

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
