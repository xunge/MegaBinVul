#include <stddef.h>

void* top;
void* bottom;
void align_top(size_t align);
void new_chunk(void);