/*
** EPITECH PROJECT, 2022
** B-CPE-201-LIL-2-1-corewar-louis.lions
** File description:
** my_memset
*/

void my_memset(void *input, unsigned int size, char val)
{
    char *output = (char *)input;

    for (unsigned int i = 0; i < size; i++)
        output[i] = val;
}
