/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_square_root
*/

int my_square_root(int number)
{
    int result = 1;

    if (number <= 0)
        return (0);
    for (; result * result < number; result++);
    return (result);
}