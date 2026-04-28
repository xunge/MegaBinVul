#include <string.h>
#include <stddef.h>
#include <stdint.h>

typedef unsigned char guchar;
typedef ptrdiff_t gssize;
typedef size_t gsize;
typedef ptrdiff_t goffset;
typedef uint8_t guint8;
typedef int gboolean;

typedef struct {
    guchar *data;
    gsize pos;
} Buffer;

typedef struct {
    int auth_end_offset;
    struct {
        guint8 *data;
        gsize len;
    } *auth_buffer;
} FlatpakProxyClient;

#define AUTH_END_STRING ""
#define AUTH_LINE_SENTINEL ""
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define TRUE 1
#define FALSE 0
#define FIND_AUTH_END_ABORT -2
#define FIND_AUTH_END_CONTINUE -3

void *memmem(const void *haystack, size_t haystacklen,
             const void *needle, size_t needlelen);