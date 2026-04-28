#include <stdlib.h>

typedef struct r_buf_t RBuffer;
typedef struct r_asm_op_t {
    RBuffer *buf_inc;
} RAsmOp;

char *r_file_slurp(const char *file, int *sz);
void r_str_replace_char(char *s, char a, char b);
void r_str_word_set0(char *str);
const char *r_str_word_get0(const char *str, int num);
long long r_num_math(void *num, const char *str);
RBuffer *r_buf_new_with_string(const char *s);
void r_buf_free(RBuffer *b);