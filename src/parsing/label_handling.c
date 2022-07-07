/*
** EPITECH PROJECT, 2022
** asm
** File description:
** label_handling
*/

#include "../../include/asm.h"

void set_labelstruct(asms_t *asms, char *name)
{
    label_t *current;

    if (!asms->lhead) {
        asms->lhead = cus_mal(asms, sizeof(label_t));
        asms->lhead->name = name;
        asms->lhead->next = NULL;
        return;
    }
    for (current = asms->lhead; current; current = current->next) {
        if (my_strcompare(current->name, name))
            my_exit(asms, ERROR);
        if (!current->next) {
            current->next = cus_mal(asms, sizeof(label_t));
            current->next->name = name;
            current->next->next = NULL;
            return;
        }
    }
}

void init_labelstruct(asms_t *asms, asm_line_t *line, char **array, char *next)
{
    int rm = 0;
    char *name = my_strdup(array[0]);

    line->labelname = my_strdup(name);
    if (my_arrayheight(array) == 1) {
        if (next == NULL)
            my_exit(asms, ERROR);
        array = my_str_to_word_array(next, ' ');
        rm = 1;
    } else
        array = array + 1;
    setline_nolabel(asms, line, array);
    set_labelstruct(asms, name);
    line->label = TRUE;
    if (rm == 1)
        line->next = line->next->next;
}
