/*
** EPITECH PROJECT, 2022
** asm
** File description:
** write_types
*/

#include "../../include/asm.h"

int write_lab(char *inst, asms_t* asms, int size, int islabel)
{
    int *entier = my_malloc(sizeof(int));
    short *court = my_malloc(sizeof(short));
    label_t *current;
    for (current = asms->lhead; current ;current = current->next) {
        if (my_strcompare_begin(current->name, inst + 2)) {
            break;
        }
    }
    if (current == NULL)
        my_exit(asms, ERROR);
    if (islabel == SPECIAL) {
        *court = letbe_s(current->pos - size);
        write(asms->fd, court, 2);
        return 2;
    } else {
        *entier = letbe(current->pos - size);
        write(asms->fd, entier, 4);
        return 4;
    }
}

int write_dir(int islabel, asms_t *asms, byte_t *byte)
{
    int *entier = my_malloc(sizeof(int));
    short *court = my_malloc(sizeof(short));

    if (islabel == SPECIAL) {
        *court = letbe_s(my_strtonbr(byte->inst + 1));
        write(asms->fd, court, 2);
        return 2;
    } else {
        *entier = letbe(my_strtonbr(byte->inst + 1));
        write(asms->fd, entier, 4);
        return 4;
    }
}

int write_ind(asms_t *asms, byte_t *byte)
{
    short *court = my_malloc(sizeof(short));

    *court = letbe_s(my_atos(byte->inst));
    write(asms->fd, court, 2);
    return 2;
}

int write_reg(asms_t *asms, byte_t *byte)
{
    char *charactère = my_malloc(sizeof(char) * 2);

    charactère[1] = '\0';
    charactère[0] = my_strtonbr(byte->inst + 1);
    write(asms->fd, charactère, 1);
    return 1;
}
