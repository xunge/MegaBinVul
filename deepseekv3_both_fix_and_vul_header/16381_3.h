#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef bool gboolean;
#define FALSE false
#define TRUE true

typedef uint32_t guint32;
typedef uint8_t guint8;
typedef unsigned int guint;
typedef int gint;

#define COL_INFO 0

typedef struct tvbuff_t {
    // dummy structure
} tvbuff_t;

typedef struct packet_info {
    void *pool;
    void *cinfo;
} packet_info;

typedef enum {
    SNAPPY_OK
} snappy_status;

static const guint8 kafka_xerial_header[] = {0x82, 'S', 'N', 'A', 'P', 'P', 'Y', 0};

void *wmem_packet_scope(void);
void *tvb_memdup(void *scope, tvbuff_t *tvb, int offset, guint32 length);
int tvb_memeql(tvbuff_t *tvb, int offset, const guint8 *pattern, size_t size);
guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset);
snappy_status snappy_uncompressed_length(const char *input, size_t input_length, size_t *result);
void *wmem_alloc(void *pool, size_t size);
snappy_status snappy_uncompress(const char *compressed, size_t compressed_length, char *uncompressed, size_t *uncompressed_length);
tvbuff_t *tvb_new_composite(void);
void tvb_composite_append(tvbuff_t *composite, tvbuff_t *child);
tvbuff_t *tvb_new_child_real_data(tvbuff_t *parent, const void *data, guint length, gint reported_length);
void tvb_composite_finalize(tvbuff_t *composite);
void col_append_str(void *cinfo, int column, const char *text);