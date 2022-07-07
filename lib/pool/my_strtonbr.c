/*
** EPITECH PROJECT, 2021
** my_strtonbr
** File description:
** cpool
*/

#include "libpool.h"

int my_strtonbr(char *input)
{
    int nb = 0;
    int i = 0;
    for (int j = 0; j < my_strlen(input); j++) {
        if (input[j] < '0' || input[j] > '9') {
            return (nb);
        }
    }
    for (; input[i] != '\0'; i++) {
        nb = nb * 10 + (input[i] - '0');
    }
    return (nb);
}

short my_atos(char *input)
{
    short nb = 0;
    int i = 0;
    for (int j = 0; j < my_strlen(input); j++) {
        if (input[j] < '0' || input[j] > '9') {
            return (nb);
        }
    }
    for (; input[i] != '\0'; i++) {
        nb = nb * 10 + (input[i] - '0');
    }
    return (nb);
}
