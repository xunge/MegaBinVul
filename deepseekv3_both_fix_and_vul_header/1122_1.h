#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define ST32_MAX 0x7FFFFFFF
#define TYPE_SET 42

typedef struct RBuffer RBuffer;

typedef struct pyc_object {
    int type;
    // other members would be needed for a complete definition
} pyc_object;

typedef uint32_t ut32;

extern ut32 get_ut32(RBuffer *buffer, bool *error);
extern pyc_object *get_array_object_generic(RBuffer *buffer, ut32 n);
extern int eprintf(const char *format, ...);