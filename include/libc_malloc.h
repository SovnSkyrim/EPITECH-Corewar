/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-louis.lions
** File description:
** c_my_malloc
*/

#pragma once
#include <unistd.h>
#include <stdlib.h>

void free_array(char **str);

typedef struct cus_mal {
    void *ptr;
    struct cus_mal *next;
} cus_mal_t;

static cus_mal_t *mals = NULL;
