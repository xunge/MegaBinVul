#include <string.h>
#include <stdio.h>

extern char *t1_line_array;
extern char *charstringname;
extern char *t1_buf_array;
extern void t1_getline(void);
extern void alloc_array(char *array, int size, int buf_size);
extern char *strend(char *str);
extern char *eol(char *str);
extern char *t1_line_ptr;
extern char *t1_buf;
extern char *t1_line;
#define T1_BUF_SIZE 1024