#include <stddef.h>
#include <stdint.h>

typedef uint8_t byte;
extern byte *bottom;
extern byte *top;

void align_bottom(size_t align);
void new_chunk(void);