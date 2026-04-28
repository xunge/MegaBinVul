#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

typedef uint8_t guint8;
typedef size_t gsize;
typedef unsigned int guint;

#define G_MAXUINT UINT_MAX
#define g_return_val_if_fail(expr, val) if (!(expr)) return (val)
#define g_assert assert

typedef struct _GByteArray GByteArray;
typedef struct _GRealArray GRealArray;

struct _GRealArray {
    guint8 *data;
    guint len;
    guint alloc;
};

GByteArray* g_byte_array_new(void);