/*
** EPITECH PROJECT, 2020
** Adrien Lib
** File description:
** my_getnbr
*/

int my_getnbr(char *str)
{
    int negativ_index = 0;
    int num_strt = 0;
    int ret_num = 0;

    for (int i = 0; str[i] == '-' || str[i] == '+'; i++) {
        num_strt++;
        if (str[i] == '-')
            negativ_index++;
    }
    for (int i = 0; '0' <= str[num_strt + i] && str[num_strt + i] <= '9'; i++)
        ret_num = (ret_num * 10) + str[num_strt + i] - 48;
    if (negativ_index % 2 == 1)
        ret_num = -ret_num;
    return (ret_num);
}
