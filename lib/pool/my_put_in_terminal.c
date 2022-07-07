/*
** EPITECH PROJECT, 2021
** put_in_terminal
** File description:
** my_ls
*/

#include "libpool.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    if (!str) {
        my_putchar('\n');
        return;
    } else if (str[0] == '\0') {
        my_putchar('\n');
        return;
    }
    write(1, str, my_strlen(str));
}

void my_putstr_n(char const *str)
{
    if (!str) {
        my_putchar('\n');
        return;
    } else if (str[0] == '\0') {
        my_putchar('\n');
        return;
    }
    write(1, str, my_strlen(str));
    my_putchar('\n');
}
