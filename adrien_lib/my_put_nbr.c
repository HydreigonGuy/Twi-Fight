/*
** EPITECH PROJECT, 2020
** Adrien Lib
** File description:
** my_put_nbr
*/

#include <unistd.h>

int my_put_nbr(int nbr)
{
    int comparater = 1;
    int start_printing = 0;
    char character = 0;

    if (nbr < 0) {
        write(1, "-", 1);
        nbr = -nbr;
    }
    if (nbr == 0)
        write(1, "0", 1);
    for (int i = 10; i >= 0; i--) {
        for (int j = 0; j < i; j++, comparater = comparater * 10);
        if (nbr / comparater != 0 || start_printing == 1) {
            character = (nbr / comparater) + '0';
            write(1, &character, 1);
            nbr = nbr - ((nbr/comparater) * comparater);
            start_printing = 1;
        }
        comparater = 1;
    }
}