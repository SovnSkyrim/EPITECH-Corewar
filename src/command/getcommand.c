/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-louis.lions
** File description:
** getcommand
*/

#include "../../include/asm.h"

char *yeet_first_space(char *input)
{
    int i = 0;
    int j = 1;

    if (input[0] == ' ' && input[1] != ' ') {
        while (input[j]) {
            input[i] = input[j];
            i++;
            j++;
        }
        input[i] = '\0';
    }
    return input;
}

char *tab_to_space(char *input)
{
    for (int i = 0; input[i]; i++)
        if (input[i] == '\t' || input[i] == ',')
            input[i] = ' ';
    return input;
}

char *clean_input(char *input, asms_t *asms)
{
    int j = 0;
    input = tab_to_space(input);
    char *output = cus_mal(asms, sizeof(char) * (my_strlen(input) + 1));

    for (int i = 0; input[i]; i++) {
        if (input[i] != '\t') {
            output[j] = input[i];
            j++;
        if (input[i] == ' ' && input[i + 1] == ' ')
            i++;
        }
    }
    output[j] = '\0';
    for (int i = 0; output[i] != '\0'; i++)
        if (output[i] == ' ' && output[i + 1] == ' ')
            return clean_input(output, asms);
    return output;
}

void getcommand(char *path, asms_t *asms)
{
    char **output;
    int fd = open(path, O_RDONLY);
    fd < 0 ? my_exit(asms, ERROR) : 0;
    int offset = lseek(fd, 0, SEEK_END);
    offset < 0 ? my_exit(asms, ERROR) : 0;
    close(fd);
    int fd2 = open(path, O_RDONLY);
    fd2 < 0 ? my_exit(asms, ERROR) : 0;
    char *buffer = my_malloc(sizeof(char) * (offset + 1));
    read(fd2, buffer, offset + 1);
    close(fd2);
    buffer[offset] = '\0';
    buffer = clean_input(buffer, asms);
    output = my_str_to_word_array(buffer, '\n');
    for (int i = 0; output[i]; i++)
        if (output[i])
            output[i] = yeet_first_space(output[i]);
    asms->file = output;
}
