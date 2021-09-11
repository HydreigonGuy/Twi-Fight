/*
** EPITECH PROJECT, 2020
** Adrien Lib
** File description:
** my_str_cat
*/

#include "ad_lib.h"
#include <stdlib.h>

char *my_str_concat(char *s1, char *s2)
{
    char *str = NULL;
    int count = 0;

    str = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
    for (; s1[count]; count++)
        str[count] = s1[count];
    for (int i = 0; s2[i]; i++, count++)
        str[count] = s2[i];
    str[count] = '\0';
    return (str);
}