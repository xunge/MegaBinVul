#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *prog;
extern char buf[1024];
extern void print_array(FILE *f, char *set, char *name, int size);

#define CTYPE_TABLE_SIZE 256
#define TO_LOWER_TABLE_SIZE 256
#define TO_UPPER_TABLE_SIZE 256
#define SORT_ORDER_TABLE_SIZE 256