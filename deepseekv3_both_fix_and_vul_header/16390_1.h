#include <string.h>
#include <stdint.h>

typedef int gboolean;
typedef const void* gconstpointer;

typedef struct coherent_set_key {
    uint8_t data[16];
} coherent_set_key;