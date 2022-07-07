/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-louis.lions
** File description:
** is_label
*/

#include "../../include/asm.h"

void setline_label(__attribute__((unused))asms_t *asms, asm_line_t *line,
        __attribute__((unused))char **array)
{
    line->label = TRUE;
    my_exit(NULL, ERROR);
}

void setline_nolabel_struct(asms_t *asms, asm_line_t *line, char **array)
{
    byte_t *new;
    byte_t *current = cus_mal(asms, sizeof(byte_t));
    line->contents->next = current;

    for (int i = 1; array[i]; i++) {
        current->inst = my_strdup(array[i]);
        if (array[i + 1]) {
            new = cus_mal(asms, sizeof(byte_t));
            current->next = new;
            current = current->next;
        } else
            current->next = NULL;
    }
}

void setline_nolabel(asms_t *asms, asm_line_t *line, char **array)
{
    byte_t *init;
    int nb_args;
    int check = 0;

    line->label = FALSE;
    nb_args = get_nbarg(array[0]);
    if (nb_args == -1)
        my_exit(asms, ERROR);
    if (array[1][0] == '\0')
        return;
    init = cus_mal(asms, sizeof(byte_t));
    init->inst = my_strdup(array[0]);
    init->next = NULL;
    line->contents = init;
    setline_nolabel_struct(asms, line, array);
    for (byte_t *current = line->contents; current; (current = current->next ))
        check++;
    check != nb_args + 1 ? my_exit(asms, ERROR) : 0;
}

void setline_error(__attribute__((unused))asms_t *asms, asm_line_t *line,
                    __attribute__((unused))char **array)
{
    line->line = NULL;
    line->coding_byte = 0;
    line->contents = NULL;
    return;
}

int is_label(char *line)
{
    for (int i = 0; i < my_strlen(line); i++) {
        if (line[i] == ':')
            return TRUE;
    }
    for (int i = 0; i < 17; i++) {
        if (my_strcompare_begin(line, op_tab[i].mnemonique))
            return FALSE;
    }
    return 2;
}
