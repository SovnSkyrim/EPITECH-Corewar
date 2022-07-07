/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-louis.lions
** File description:
** free_struct
*/

#include "libc_malloc.h"

void free_array(char **str)
{
    for (int i = 0; str[i]; i++)
        free(str[i]);
    free(str);
}

void put_to_mals(void *ptr)
{
    cus_mal_t *elem = mals;
    cus_mal_t *tmp = malloc(sizeof(cus_mal_t));
    tmp->ptr = ptr;
    tmp->next = NULL;
    if (mals == NULL) {
        mals = tmp;
    } else {
        for (; elem->next != NULL; elem = elem->next);
        elem->next = tmp;
    }

}

void *my_malloc(unsigned long long size)
{
    void *ptr = malloc(size);
    if (ptr == NULL) {
        write(2, "Error: my_malloc failed\n", 21);
        exit(84);
    }
    put_to_mals(ptr);
    return (ptr);
}

void free_malloc(void)
{
    cus_mal_t *elem = mals->next;
    cus_mal_t *tmp;
    int i = 0;
    while (elem != NULL) {
        tmp = elem;
        elem = elem->next;
        free(tmp->ptr);
        free(tmp);
    }
    free(mals->ptr);
    free(mals);
    free(elem);
}
