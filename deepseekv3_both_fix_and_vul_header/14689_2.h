#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define K12_RECORD_TYPE 0
#define K12_PACKET_FRAME_D0020 0
#define K12_PACKET_FRAME 0
#define K12_RECORD_FRAME_LEN 0
#define K12_PACKET_TIMESTAMP 0
#define K12_RECORD_SRC_ID 0
#define K12_RECORD_SRC_ID_MASK 0
#define K12_PACKET_OFFSET_CID 0
#define K12_PACKET_OFFSET_VP 0
#define K12_PACKET_OFFSET_VC 0
#define K12_REC_D0020 0
#define WTAP_ERR_BAD_FILE 0
#define REC_TYPE_PACKET 0
#define WTAP_HAS_TS 0
#define K12_PORT_ATMPVC 0

typedef int gboolean;
#define TRUE 1
#define FALSE 0
typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint64_t guint64;
typedef int gint;
typedef unsigned int guint;
typedef char gchar;

typedef struct {
    guint32 secs;
    guint32 nsecs;
} nstime_t;

typedef struct {
    guint8 *extra_info;
    guint32 extra_length;
    guint32 input;
    gchar *input_name;
    gchar *stack_file;
    guint32 input_type;
    union {
        struct {
            guint16 vp;
            guint16 vc;
            guint8 cid;
        } atm;
    } input_info;
    void *stuff;
} k12_pseudo_header_t;

typedef struct {
    gchar *input_name;
    gchar *stack_file;
    guint32 input_type;
    union {
        struct {
            guint16 vp;
            guint16 vc;
            guint8 cid;
        } atm;
    } input_info;
} k12_src_desc_t;

typedef struct Buffer {
    guint8 *data;
    guint allocated_len;
    guint reported_len;
} Buffer;

typedef struct {
    void *src_by_id;
    Buffer extra_info;
} k12_t;

struct wtap_pkthdr {
    int rec_type;
    int presence_flags;
    nstime_t ts;
    guint32 len;
    guint32 caplen;
    struct {
        k12_pseudo_header_t k12;
    } pseudo_header;
};

#define K12_DBG(level, args)

static inline guint32 pntoh32(const guint8 *p) {
    return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
}

static inline guint64 pntoh64(const guint8 *p) {
    return ((guint64)pntoh32(p) << 32) | pntoh32(p + 4);
}

static inline guint16 pntoh16(const guint8 *p) {
    return (p[0] << 8) | p[1];
}

static inline guint8 *ws_buffer_start_ptr(Buffer *buf) {
    return buf->data;
}

static inline void ws_buffer_assure_space(Buffer *buf, guint size) {
    if (buf->allocated_len < size) {
        buf->data = realloc(buf->data, size);
        buf->allocated_len = size;
    }
}

static inline gchar *g_strdup_printf(const char *format, ...) {
    char *buf = malloc(256);
    va_list args;
    va_start(args, format);
    vsnprintf(buf, 256, format, args);
    va_end(args);
    return buf;
}

static inline void *g_hash_table_lookup(void *hash_table, void *key) {
    return NULL;
}

#define GUINT_TO_POINTER(x) ((void*)(uintptr_t)(x))