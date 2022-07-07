/*
** EPITECH PROJECT, 2022
** clibpool
** File description:
** lib
*/

#ifndef LIBPOOL_H_
#define LIBPOOL_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #define SUCCESS 0
    #define ERROR 84
    #define FALSE 0
    #define TRUE 1
    #define SPECIAL 2

    void free_malloc(void);
    void *my_malloc(unsigned long long size);
    void put_to_mals(void *ptr);
    char *my_nbrtostr(int result);
    short my_atos(char *input);
    void my_putchar(char c);
    void my_putstr(char const *str);
    void my_putstr_n(char const *str);
    void my_putnbr(int nbr);
    char *my_revstr(char *str);
    char **my_str_to_word_array(char const *str, char c);
    char *concatenating3(char *begin, char *middle, char *end);
    char *concatenating2(char *begin, char *end);
    int my_strlen(char const *str);
    int my_strtonbr(char *input);
    int my_arrayheight(char **a);
    int my_strcompare(char *first, char *second);
    int my_strcompare_begin(char *first, char *second);
    char *my_strxdupe(char *input, char cinput);
    char *my_strxdupb(char *input, char cinput);
    char *my_strncpy(char *dest, const char *src, int start, int n);
    char *my_array_to_str(char **array);
    char **my_arraycpy(char **env);
    char *my_strdup(char *input);
    char *my_strdupn(char *input, int length);

#endif/* !LIBPOOL_H_ */
