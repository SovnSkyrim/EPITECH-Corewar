/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-louis.lions
** File description:
** getfilename
*/

#include "../../include/asm.h"

void file_init(char *path, asms_t *asms)
{
    char **a_path = my_str_to_word_array(path, '/');
    int height = my_arrayheight(a_path) - 1;
    char **name =  my_str_to_word_array(a_path[height], '.');
    char *actual_name = my_strdup(name[0]);
    char *extension = concatenating2(actual_name, ".cor");

    asms->fd = open(extension, O_WRONLY | O_CREAT | O_TRUNC,
                S_IRWXU | S_IRWXG | S_IRWXO);
    if (asms->fd == -1)
        my_exit(asms, ERROR);
}
