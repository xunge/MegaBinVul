#include <stdint.h>
#include <limits.h>
#include <stdlib.h>

typedef unsigned int guint;
typedef uint8_t guint8;
typedef uint64_t guint64;
typedef int gboolean;
#define G_MAXUINT UINT_MAX

typedef struct tvbuff_t tvbuff_t;
struct wmem_allocator_t;
#define wmem_packet_scope() ((struct wmem_allocator_t *)0)
#define tvb_ensure_bytes_exist(tvb, offset, len) 
#define DISSECTOR_ASSERT(expr) 
#define DISSECTOR_ASSERT_HINT(expr, hint) 
#define THROW(err) 

struct data_blob {
    void* data;
    size_t size;
};

struct vt_vector {
    int len;
    union {
        guint8 *vt_ui1;
    } u;
};

struct vtype_data {
    int size;
    int (*tvb_get)(tvbuff_t *tvb, int offset, guint8 *data);
};

static void* wmem_alloc(struct wmem_allocator_t* scope, size_t size) {
    return malloc(size);
}