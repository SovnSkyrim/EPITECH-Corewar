/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-louis.lions
** File description:
** opt_fun
*/

#include "../../include/asm.h"

int get_nbarg(char *mnemonique)
{
    for (int i = 0; i < 17; i++)
        if (my_strcompare(mnemonique, op_tab[i].mnemonique))
            return op_tab[i].nbr_args;
    return -1;
}

op_t get_mnemonique(char *mnemonique)
{
    for (int i = 0; i < 17; i++)
        if (my_strcompare(mnemonique, op_tab[i].mnemonique))
            return op_tab[i];
    return op_tab[17];
}
