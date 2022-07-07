/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-louis.lions
** File description:
** write_cor
*/

#include "../../include/asm.h"

int check_inst(char *mnemonique)
{
    if (my_strcompare(mnemonique, "zjmp") ||
        my_strcompare(mnemonique, "live") ||
        my_strcompare(mnemonique, "fork") ||
        my_strcompare(mnemonique, "lfork"))
        return TRUE;
    if (my_strcompare(mnemonique, "ldi") ||
        my_strcompare(mnemonique, "lldi") ||
        my_strcompare(mnemonique, "sti"))
        return SPECIAL;
    return FALSE;
}

void write_contents(asm_line_t *line, asms_t *asms, int islabel)
{
    static int size = 0;
    size += islabel == TRUE ? 1 : 2;
    for (byte_t *byte = line->contents->next; byte; byte = byte->next) {
        switch (byte->type) {
            case T_REG: size += write_reg(asms, byte);
                break;
            case T_DIR: size += write_dir(islabel, asms, byte);
                break;
            case T_IND: size += write_ind(asms, byte);
                break;
            case T_LAB: size += write_lab(byte->inst, asms, size, islabel);
                break;
            default: my_exit(NULL, 84);
        }
    }
}

void time_to_write(asms_t *asms)
{
    char *to_write = my_malloc(sizeof(char) * 2);
    op_t current_tab;
    int is_label = 0;

    to_write[1] = '\0';
    asms->header->prog_size = letbe(asms->header->prog_size);
    write(asms->fd, asms->header, sizeof(header_t));
    for (asm_line_t *line = asms->head; line; line = line->next) {
        current_tab = get_mnemonique(line->contents->inst);
        to_write[0] = current_tab.code;
        write(asms->fd, to_write, 1);
        is_label = check_inst(current_tab.mnemonique);
        if (line->coding_byte && !is_label)
            to_write[0] = line->coding_byte;
        write(asms->fd, to_write, 1);
        write_contents(line, asms, is_label);
    }
}
