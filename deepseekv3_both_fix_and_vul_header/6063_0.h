#include <stdlib.h>
#include <string.h>

extern void *bottom;
extern void *top;
extern void *temp_end;

void *alloc_temp(size_t s);
void new_chunk(void);

typedef unsigned char byte;