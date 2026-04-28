#include <string.h>

typedef unsigned char byte;

struct WebPImage {
    long getHeaderOffset(byte *data, long data_size, byte *header, long header_size);
};