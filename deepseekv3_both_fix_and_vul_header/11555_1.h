#include <string.h>
#include <stdio.h>

#define T1_BUF_SIZE 1024

extern char *t1_line_array;
extern char *charstringname;
extern char *t1_buf_array;
extern char *t1_line_ptr;
extern char *t1_buf;
extern char *t1_line;

void t1_getline(void);
char *strend(char *str);
char *eol(char *str);
void alloc_array(char *array, int size, int buf_size);