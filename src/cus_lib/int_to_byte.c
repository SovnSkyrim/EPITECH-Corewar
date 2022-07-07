/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-louis.lions
** File description:
** int_to_byte
*/

#include "../../include/asm.h"

int letbe(int input)
{
    int output = 0;
    int i = 0;

    while (i < 4) {
        output = output << 8;
        output = output | (input & 0xFF);
        input = input >> 8;
        i++;
    }
    return (output);
}

short letbe_s(short input)
{
    short output = 0;
    int i = 0;

    while (i < 2) {
        output = output << 8;
        output = output | (input & 0xFF);
        input = input >> 8;
        i++;
    }
    return (output);
}
