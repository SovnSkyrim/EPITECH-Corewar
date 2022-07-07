/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-louis.lions
** File description:
** print_help
*/

#include "../../include/asm.h"

void print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./asm file_name[.s]\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfile_name file in assembly language ");
    my_putstr("to be converted into file_name.cor, an ");
    my_putstr("executable in the Virtual Machine.\n");
}
