/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-louis.lions
** File description:
** init_types
*/

#include "../../include/asm.h"

unsigned char end_codingbyte(unsigned char byte, int i)
{
    for (; i < 4; i++) {
        byte = byte << 2;
        byte |= 0;
    }
    return byte;
}

unsigned char gen_coding_byte(asm_line_t *line, asms_t *asms)
{
    int i = 0;
    unsigned char coding_byte = 0;

    for (byte_t *current = line->contents->next;
    current; current = current->next) {
        coding_byte = coding_byte << 2;
        switch (current->type) {
            case T_LAB: case T_DIR: coding_byte |= 2 ;
                break;
            case T_REG: coding_byte |= 1;
                break;
            case T_IND: coding_byte |= 3;
                break;
            default: my_exit(asms, ERROR);
        }
        i++;
    }
    return end_codingbyte(coding_byte, i);
}

int get_type(char *inst)
{
    if (inst[0] == '%' && inst[1] == ':' && check_label(inst + 2))
        return T_LAB;
    if (inst[0] == 'r' && check_type(inst + 1)) {
        if (my_strtonbr(inst + 1) > REG_NUMBER)
            return ERROR;
        else
            return T_REG;
    }
    if (inst[0] == '%' && check_direct(inst + 1))
        return T_DIR;
    return T_IND;
}

void gen_types(asm_line_t *line, asms_t *asms)
{
    line->contents->type = 0;
    for (byte_t *current = line->contents->next;
    current; current = current->next) {
        current->type = get_type(current->inst);
        if (current->type == ERROR)
            my_exit(asms, ERROR);
    }
    line->coding_byte = gen_coding_byte(line, asms);
    check_types(line, asms);
}
