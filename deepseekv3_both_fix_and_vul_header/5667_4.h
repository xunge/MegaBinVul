#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef bool gboolean;
typedef uint32_t guint32;
typedef uint8_t guint8;

typedef struct _tvbuff_t {
    guint8* real_data;
    guint32 length;
} tvbuff_t;

typedef struct _frame_data {
    guint32 num;
} frame_data;

typedef struct _packet_info {
    frame_data* fd;
    guint32 curr_layer_num;
} packet_info;

typedef struct _fragment_item {
    struct _fragment_item *next;
    guint32 flags;
    guint32 frame;
    guint32 offset;
    guint32 fragment_nr_offset;
    guint32 len;
    tvbuff_t *tvb_data;
    const char *error;
} fragment_item;

typedef struct _fragment_head {
    fragment_item *next;
    guint32 flags;
    guint32 frame;
    guint32 datalen;
    guint32 reassembled_in;
    guint32 reas_in_layer_num;
    tvbuff_t *tvb_data;
    const char *error;
} fragment_head;

#define FD_DEFRAGMENTED          (1 << 0)
#define FD_DATALEN_SET           (1 << 1)
#define FD_PARTIAL_REASSEMBLY    (1 << 2)
#define FD_OVERLAP               (1 << 3)
#define FD_OVERLAPCONFLICT       (1 << 4)
#define FD_TOOLONGFRAGMENT       (1 << 5)
#define FD_MULTIPLETAILS         (1 << 6)
#define FD_SUBSET_TVB            (1 << 7)

#define TRUE true
#define FALSE false

#define LINK_FRAG(fd_head,fd) \
    do { \
        fragment_item **fdp = &(fd_head)->next; \
        while (*fdp && (*fdp)->offset < (fd)->offset) \
            fdp = &(*fdp)->next; \
        (fd)->next = *fdp; \
        *fdp = (fd); \
    } while(0)

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

#define THROW_MESSAGE(type, msg) return FALSE
#define THROW(type) return FALSE

static void* g_malloc(size_t size) { return malloc(size); }
static void g_free(void* ptr) { free(ptr); }
#define g_slice_new(type) ((type*)malloc(sizeof(type)))
#define g_slice_free(type, ptr) free(ptr)

static tvbuff_t* tvb_new_subset_remaining(tvbuff_t* tvb, guint32 offset) {
    tvbuff_t* new_tvb = malloc(sizeof(tvbuff_t));
    new_tvb->real_data = tvb->real_data + offset;
    new_tvb->length = tvb->length - offset;
    return new_tvb;
}

static tvbuff_t* tvb_clone_offset_len(tvbuff_t* tvb, int offset, guint32 len) {
    tvbuff_t* new_tvb = malloc(sizeof(tvbuff_t));
    new_tvb->real_data = malloc(len);
    memcpy(new_tvb->real_data, tvb->real_data + offset, len);
    new_tvb->length = len;
    return new_tvb;
}

static tvbuff_t* tvb_new_real_data(guint8* data, guint32 length, guint32 reported_length) {
    tvbuff_t* tvb = malloc(sizeof(tvbuff_t));
    tvb->real_data = data;
    tvb->length = length;
    return tvb;
}

static void tvb_set_free_cb(tvbuff_t* tvb, void (*free_cb)(void*)) {}

static void tvb_free(tvbuff_t* tvb) {
    if (tvb) {
        free(tvb->real_data);
        free(tvb);
    }
}

static void tvb_add_to_chain(tvbuff_t* parent, tvbuff_t* child) {}

static int tvb_memeql(tvbuff_t* tvb, guint32 offset, const guint8* pattern, guint32 len) {
    return memcmp(tvb->real_data + offset, pattern, len) == 0;
}

static const guint8* tvb_get_ptr(tvbuff_t* tvb, int offset, int length) {
    return tvb->real_data + offset;
}

static int tvb_bytes_exist(tvbuff_t* tvb, int offset, int length) {
    return (offset >= 0) && (length >= 0) && ((guint32)(offset + length) <= tvb->length);
}