/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-louis.lions
** File description:
** cus_mal
*/

#include "../../include/asm.h"

void *cus_mal(asms_t *asms, unsigned long long size)
{
    void *ptr = my_malloc(size);
    if (ptr == 0)
        my_exit(asms, ERROR);
    return ptr;
}

void my_exit(__attribute__((unused))asms_t *asms, unsigned char value)
{
    free_malloc();
    exit(value);
}
