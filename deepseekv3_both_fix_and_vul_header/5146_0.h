#include <ctype.h>
#include <stdlib.h>

struct buffer_st;

unsigned char dtable[256];

void buffer_new(struct buffer_st *bfr);
void buffer_add(struct buffer_st *bfr, unsigned char c);