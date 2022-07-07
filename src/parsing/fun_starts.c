/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-louis.lions
** File description:
** fun_starts
*/

#include "../../include/asm.h"

void put_into_str(char *buffer, char *input, int size)
{
    for (int i = 0; i < size; i++)
        buffer[i] = input[i];
}

int *init_header_loop(header_t *header, asms_t *asms)
{
    char **array;
    int *header_strs = my_malloc(sizeof(int) * 2);
    header_strs[0] = 0;
    header_strs[1] = 0;

    for (int i = 0; asms->file[i]; i++) {
        if (my_strcompare_begin(asms->file[i], NAME_CMD_STRING)) {
            array = my_str_to_word_array(asms->file[i], 34);
            put_into_str(header->prog_name, array[1], my_strlen(array[1]));
            header_strs[0] = header_strs[0] + 1;
        } else if (my_strcompare_begin(asms->file[i], COMMENT_CMD_STRING)) {
            array = my_str_to_word_array(asms->file[i], 34);
            put_into_str(header->comment, array[1], my_strlen(array[1]));
            header_strs[1] = header_strs[1] + 1;
        }
    }
    return header_strs;
}

void init_header(asms_t *asms, header_t *header)
{
    int *header_strs = init_header_loop(header, asms);

    if (header->prog_name [0] == 0 || header->comment[0] == 0
        || header_strs[0] != 1 || header_strs[1] != 1)
        my_exit(asms, ERROR);
    header->prog_size = 0;
    header->magic = letbe(COREWAR_EXEC_MAGIC);
    asms->header = header;
    asms->head = NULL;
    asms->lhead = NULL;
}

void starting_the_fun(asms_t *asms)
{
    header_t *header = my_malloc(sizeof(header_t));

    my_memset(header, sizeof(header_t), 0);
    init_header(asms, header);
    for (int i = 3; asms->file[i]; i++) {
        if (asms->file[i][0] != '\0')
            init_lines(i, asms);
    }
    init_content_line(asms);
    get_program_size(header, asms);
}
