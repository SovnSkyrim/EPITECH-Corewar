/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-louis.lions
** File description:
** init_struct
*/

#include "../../include/asm.h"

static void (*psetline[])(asms_t *asms, asm_line_t *line, char **array) = {
        setline_nolabel,
        setline_label,
        setline_error,
    };

void init_content_line(asms_t *asms)
{
    asm_line_t *line;
    char **array;

    for (line = asms->head; line; line = line->next) {
        array = my_str_to_word_array(line->line, ' ');
        if (is_label(array[0]) == 1)
            init_labelstruct(asms, line, array,
            line->next ? line->next->line : NULL);
        else
            (*psetline[is_label(array[0])])(asms, line, array);
    }
    for (asm_line_t *line = asms->head; line; line = line->next) {
        gen_types(line, asms);
    }
}

void init_lines(int i, asms_t *asms)
{
    asm_line_t *current;

    if (!asms->head) {
        asms->head = cus_mal(asms, sizeof(asm_line_t));
        asms->head->line = my_strdup(asms->file[i]);
        asms->head->next = NULL;
        return;
    }

    for (current = asms->head; current; current = current->next) {
        if (!current->next) {
            current->next = cus_mal(asms, sizeof(asm_line_t));
            current->next->line = my_strdup(asms->file[i]);
            current->next->next = NULL;
            return;
        }
    }
}
