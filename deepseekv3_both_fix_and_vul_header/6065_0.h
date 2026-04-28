#include <stddef.h>
#include <stdint.h>

typedef uint8_t byte;
extern byte *bottom;
extern byte *top;
void new_chunk(void);