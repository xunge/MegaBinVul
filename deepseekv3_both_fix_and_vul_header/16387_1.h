#include <stdint.h>
#include <stdlib.h>

typedef unsigned int guint;
typedef const void* gconstpointer;
typedef uint8_t guint8;

typedef struct {
    uint8_t data[16];
} coherent_set_key;

typedef struct {
    void* data;
    size_t size;
} GBytes;

guint wmem_strong_hash(const guint8* data, size_t len);
GBytes* g_bytes_new(gconstpointer data, size_t size);
guint g_bytes_hash(GBytes* bytes);