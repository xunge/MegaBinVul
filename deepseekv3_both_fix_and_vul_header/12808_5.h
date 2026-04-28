#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    uint8_t* data;
    size_t size;
} ByteBuffer;

static ByteBuffer create_uninitialized(size_t size) {
    ByteBuffer buffer;
    buffer.data = size ? (uint8_t*)malloc(size) : NULL;
    buffer.size = size;
    return buffer;
}

#define auto ByteBuffer
#define data() data