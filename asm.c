/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** asm
*/

#include "include/asm.h"

void analyze_args(int argc, char **argv, asms_t *asms)
{
    if (argc != 2) {
        print_help();
        my_exit(asms, ERROR);
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        print_help();
        my_exit(asms, SUCCESS);
    }
    getcommand(argv[1], asms);
}

int main(int argc, char **argv)
{
    asms_t *asms = my_malloc(sizeof(asms_t));
    if (asms == NULL)
        return ERROR;
    asms->fd = -1;
    analyze_args(argc, argv, asms);
    starting_the_fun(asms);
    file_init(argv[1], asms);
    time_to_write(asms);
    my_exit(asms, SUCCESS);
    return SUCCESS;
}
