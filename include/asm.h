/*
** EPITECH PROJECT, 2021
** bsq.h
** File description:
** my_ls
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libpool.h"
#include "op.h"
#include <fcntl.h>
#include <string.h>

#ifndef ASM_H_
    #define ASM_H_
    #define SUCCESS 0
    #define SPECIAL 2
    #define ERROR 84
    #define TRUE 1
    #define FALSE 0
    #define print printf
    #define prinft printf

typedef struct label {
    char *name;
    int pos;
    struct label *next;
} label_t;

typedef struct byte {
    char *inst;
    char type;
    struct byte *next;
} byte_t;

typedef struct asm_line {
    char *line;
    int label;
    unsigned char coding_byte;
    char *labelname;
    byte_t *contents;
    struct asm_line *next;
} asm_line_t;

typedef struct asms {
    char **file;
    int fd;
    header_t *header;
    label_t *lhead;
    asm_line_t *head;
} asms_t;

void *cus_mal(asms_t *asms, unsigned long long size);
void free_malloc(void);
void *my_malloc(unsigned long long size);
void put_to_mals(void *ptr);
void my_exit(__attribute__((unused))asms_t *asms, unsigned char value);
void free_array(char **array);
void print_help(void);
void getcommand(char *path, asms_t *asms);
void file_init(char *path, asms_t *asms);
void my_memset(void *input, unsigned int size, char val);
void starting_the_fun(asms_t *asms);
int letbe(int input);
short letbe_s(short input);
int is_label(char *line);
int get_nbarg(char *mnemonique);
op_t get_mnemonique(char *mnemonique);
void check_types(asm_line_t *line, asms_t *asms);
void init_lines(int i, asms_t *asms);
void init_content_line(asms_t *asms);
void init_labelstruct(asms_t *asms, asm_line_t *line,
    char **array, char *next);
void setline_nolabel(asms_t *asms, asm_line_t *line, char **array);
void setline_label(asms_t *asms, asm_line_t *line, char **array);
void setline_error(asms_t *asms, asm_line_t *line,
    __attribute__((unused))char **array);
void gen_types(asm_line_t *line, asms_t *asms);
int type_to_size(int type);
void time_to_write(asms_t *asms);
int check_type(char *str);
int check_direct(char *str);
int check_car(char c);
int check_label(char *str);
void get_program_size(header_t *header, asms_t *asms);
int check_inst(char *mnemonique);
int write_lab(char *inst, asms_t* asms, int size, int islabel);
int write_dir(int islabel, asms_t *asms, byte_t *byte);
int write_reg(asms_t *asms, byte_t *byte);
int write_ind(asms_t *asms, byte_t *byte);

#endif
