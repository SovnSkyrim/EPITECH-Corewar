/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-louis.lions
** File description:
** check_types
*/

#include "../../include/asm.h"

void check_types(asm_line_t *line, asms_t *asms)
{
    op_t tab =  get_mnemonique(line->contents->inst);
    byte_t *next = line->contents->next;
    char comp;
    int type = 0;

    for (int i = 0; tab.type[i] != 0; i++) {
        type = next->type == 8 ? 2 : next->type;
        comp = tab.type[i] & type;
        if (comp != type) {
            my_exit(asms, ERROR);
        }
        next = next->next;
    }
}

int check_type(char *str)
{
    int nb = my_strtonbr(str);
    if (nb <= REG_NUMBER && nb > 0)
        return TRUE;
    else
        my_exit(NULL, ERROR);
    return ERROR;
}

int check_car(char c)
{
    for (int j = 0;  LABEL_CHARS[j]; j++) {
        if (c == LABEL_CHARS[j])
            return TRUE;
    }
    return ERROR;
}

int check_label(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (check_car(str[i]) == TRUE) {
            return TRUE;
        }
    }
    my_exit(NULL, ERROR);
    return ERROR;
}

int check_direct(char *str)
{
    int nb = my_strtonbr(str);
    if (nb > 0) {
        return TRUE;
    } else
        my_exit(NULL, ERROR);
    return ERROR;
}
