#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void *alloc_temp(size_t size);
void new_chunk(void);

extern unsigned char *temp_end;
extern unsigned char *bottom;
extern unsigned char *top;
typedef unsigned char byte;