#include <stdint.h>
#include <stdlib.h>

#define MAX_VT_VECTOR_SIZE 65535
#define G_MAXUINT UINT32_MAX

typedef uint8_t guint8;
typedef uint32_t guint;
typedef uint64_t guint64;
typedef int gint;
typedef int gboolean;

typedef struct tvbuff_t tvbuff_t;
struct wmem_allocator;

struct vt_vector {
    guint len;
    union {
        guint8 *vt_ui1;
    } u;
};

struct vtype_data {
    gint size;
    int (*tvb_get)(tvbuff_t *tvb, int offset, guint8 *data);
};

struct data_blob {
    guint8 *data;
    guint size;
};

#define THROW(x) do { return -1; } while (0)
#define DISSECTOR_ASSERT(x) do { if (!(x)) abort(); } while (0)
#define DISSECTOR_ASSERT_HINT(x, y) do { if (!(x)) abort(); } while (0)

void tvb_ensure_bytes_exist(tvbuff_t *tvb, int offset, int length);
void *wmem_alloc(struct wmem_allocator *allocator, size_t size);
struct wmem_allocator *wmem_packet_scope(void);