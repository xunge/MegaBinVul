#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct rec_parser_s {
    int error;
} *rec_parser_t;

typedef struct rec_comment_s {
    char *text;
} *rec_comment_t;

typedef struct rec_buf_s {
    char *data;
    size_t size;
    size_t pos;
} rec_buf_t;

enum {
    REC_PARSER_ENOMEM
};

rec_buf_t rec_buf_new(char **str, size_t *str_size);
int rec_buf_putc(char c, rec_buf_t buf);
void rec_buf_close(rec_buf_t buf);
bool rec_expect(rec_parser_t parser, const char *str);
int rec_parser_getc(rec_parser_t parser);
void rec_parser_ungetc(rec_parser_t parser, int c);
rec_comment_t rec_comment_new(char *str);