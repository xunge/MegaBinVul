#include <stdio.h>
#include <stdlib.h>

#define TGA_HEADER_SIZE 18

static unsigned short get_ushort(unsigned char *data);