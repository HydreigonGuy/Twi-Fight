/*
** EPITECH PROJECT, 2020
** Adrien Lib
** File description:
** my_strlen
*/

int my_strlen(char *str)
{
    int len = 0;

    for (; str[len]; len++);
    return (len);
}
