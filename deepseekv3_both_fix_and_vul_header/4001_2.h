#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MAX_LOOP_ITERATIONS 1000
#define FALSE false
#define TRUE true
#define COL_INFO 0

typedef bool gboolean;
typedef uint32_t guint32;
typedef uint8_t guint8;
typedef int32_t gint;
typedef uint32_t guint;

typedef enum {
    SNAPPY_OK,
    SNAPPY_INVALID_INPUT,
    SNAPPY_BUFFER_TOO_SMALL
} snappy_status;

typedef struct tvbuff {
    // Minimal tvbuff_t structure
} tvbuff_t;

typedef struct packet_info {
    void *pool;
    void *cinfo;
} packet_info;

typedef struct wmem_allocator {
    // Minimal wmem allocator structure
} wmem_allocator_t;

#define DISSECTOR_ASSERT_HINT(cond, msg) do { if (!(cond)) {} } while(0)

static const guint8 kafka_xerial_header[] = {0x82, 'S', 'N', 'A', 'P', 'P', 'Y', 0};

// Function prototypes
void *tvb_memdup(wmem_allocator_t *pool, tvbuff_t *tvb, int offset, guint32 length);
int tvb_memeql(tvbuff_t *tvb, int offset, const guint8 *pattern, size_t size);
guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset);
snappy_status snappy_uncompressed_length(const char *input, size_t length, size_t *result);
snappy_status snappy_uncompress(const char *compressed, size_t compressed_length, char *uncompressed, size_t *uncompressed_length);
void *wmem_alloc(wmem_allocator_t *allocator, size_t size);
void wmem_free(wmem_allocator_t *allocator, void *ptr);
tvbuff_t *tvb_new_composite(void);
void tvb_composite_append(tvbuff_t *composite, tvbuff_t *child);
tvbuff_t *tvb_new_child_real_data(tvbuff_t *parent, const void *data, guint length, gint reported_length);
void tvb_composite_finalize(tvbuff_t *composite);
void col_append_str(void *cinfo, int column, const char *text);