/*
** EPITECH PROJECT, 2022
** my_strxdup
** File description:
** libpool
*/

#include "libpool.h"

char *my_strxdupb(char *input, char cinput)
{
    int goal = 0;
    char *output;

    for (int i = 0; input[i] != cinput; ++i)
        goal++;
    output = my_malloc((sizeof(char) * (goal + 1)));
    output[goal] = '\0';
    for (int i = 0; i < goal; ++i)
        output[i] = input[i];
    return output;
}

char *my_strxdupe(char *input, char cinput)
{
    int goal = 0;
    int copy = 0;
    char *output;

    for (int i = 0; input[i] != cinput; ++i)
        goal++;
    output = my_malloc((sizeof(char) * ((my_strlen(input) - goal))));
    output[(my_strlen(input) - goal) - 1] = '\0';
    for (int i = goal + 1; input[i] ; ++i) {
        output[copy] = input[i];
        copy++;
    }
    return output;
}

char *my_strdupn(char *input, int length)
{
    int i = length;
    char *output = my_malloc((sizeof(char) *
        (my_strlen(input) - length + 1)));
    for (; input[i]; ++i)
        output[i - length] = input[i];
    output[i - length] = '\0';
    return output;
}

char *my_strdup(char *input)
{
    int len = my_strlen(input);
    char *output = my_malloc(sizeof(char) * ((len + 1)));

    output[len] = '\0';
    for (int i = 0; input[i]; i++)
        output[i] = input[i];
    return output;
}
