/*
** EPITECH PROJECT, 2022
** asm
** File description:
** get_program_size
*/

#include "../../include/asm.h"

void get_label_pos(asm_line_t *line, asms_t *asms, int isindex)
{
    if (line->label != TRUE)
        return;
    for (label_t *current = asms->lhead;
        current; current = current->next) {
        if (my_strcompare(current->name, line->labelname)) {
            current->pos = (asms->header->prog_size)
            + (isindex == TRUE ? 1 : 2);
            return;
        }
    }
}

void add_to_size(header_t *header, byte_t *byte, int isindex)
{
    if (!byte->type) {
        header->prog_size += 2;
        if (isindex == TRUE)
            header->prog_size -= 1;
        return;
    }
    switch (byte->type) {
        case T_REG: header->prog_size += 1;
            break;
        case T_DIR: case T_LAB:
            if (isindex == SPECIAL)
                header->prog_size += 2;
            else
                header->prog_size += 4;
            break;
        case T_IND: header->prog_size += 2;
            break;
    }
}

void get_program_size(header_t *header, asms_t *asms)
{
    int isindex = 0;

    for (asm_line_t *line = asms->head; line; line = line->next) {
        get_label_pos(line, asms, isindex);
        isindex = check_inst(line->contents->inst);
        for (byte_t *byte = line->contents; byte; byte = byte->next)
            add_to_size(header, byte, isindex);
        isindex = 0;
    }
}
