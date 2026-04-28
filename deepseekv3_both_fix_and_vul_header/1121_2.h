#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define ST32_MAX 0x7FFFFFFF
#define TYPE_LIST 1

typedef uint32_t ut32;

typedef struct pyc_object {
    int type;
} pyc_object;

typedef struct RBuffer RBuffer;

extern ut32 get_ut32(RBuffer *buffer, bool *error);
extern struct pyc_object *get_array_object_generic(RBuffer *buffer, ut32 n);
extern void eprintf(const char *format, ...);