#include <stdint.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define REC_EOF 0
#define REC_FRAME2 1
#define REC_FRAME4 2
#define REC_FRAME6 3
#define REC_TYPE_PACKET 4

#define NETWORK_ATM 1
#define WTAP_ERR_BAD_FILE 1
#define WTAP_HAS_TS 1
#define WTAP_HAS_CAP_LEN 2

typedef int gboolean;
typedef unsigned int guint;
typedef uint16_t guint16;
typedef uint8_t guint8;
typedef uint64_t guint64;
typedef char gchar;

struct wtap_pkthdr {
    int rec_type;
    int presence_flags;
    guint len;
    guint caplen;
    struct {
        time_t secs;
        int nsecs;
    } ts;
    void *pseudo_header;
    int pkt_encap;
};

typedef struct {
    void *priv;
    int file_encap;
} wtap;

typedef struct {
    void *start_ptr;
    void *(*start_ptr_func)(void*);
    void (*assure_space_func)(void*, guint);
} Buffer;

struct frame2_rec {
    guint16 time_low;
    guint16 time_med;
    guint8 time_high;
    guint8 time_day;
    guint16 size;
    guint16 true_size;
};

struct frame4_rec {
    guint16 time_low;
    guint16 time_med;
    guint8 time_high;
    guint8 time_day;
    guint16 size;
    guint16 true_size;
};

struct frame6_rec {
    guint16 time_low;
    guint16 time_med;
    guint8 time_high;
    guint8 time_day;
    guint16 size;
    guint16 true_size;
};

typedef struct {
    guint network;
    guint maj_vers;
    guint min_vers;
    guint64 timeunit;
    guint64 start;
} ngsniffer_t;

static inline guint16 pletoh16(const void *p) {
    const guint8 *bytes = (const guint8 *)p;
    return (bytes[1] << 8) | bytes[0];
}

static char* g_strdup(const char *str) {
    return strdup(str);
}

static void ws_buffer_assure_space(Buffer *buf, guint size) {
    if (buf->assure_space_func) buf->assure_space_func(buf, size);
}

static void* ws_buffer_start_ptr(Buffer *buf) {
    return buf->start_ptr_func ? buf->start_ptr_func(buf) : buf->start_ptr;
}

static int ng_read_bytes_or_eof(wtap *wth, void *buf, int size, gboolean is_random, int *err, gchar **err_info) {
    return 0;
}

static int ng_read_bytes(wtap *wth, void *buf, int size, gboolean is_random, int *err, gchar **err_info) {
    return 0;
}

static void set_pseudo_header_frame2(wtap *wth, void *phdr, struct frame2_rec *frame) {}
static void set_pseudo_header_frame4(void *phdr, struct frame4_rec *frame) {}
static void set_pseudo_header_frame6(wtap *wth, void *phdr, struct frame6_rec *frame) {}
static int fix_pseudo_header(int encap, Buffer *buf, guint length, void *phdr) { return 0; }

#define G_GUINT64_CONSTANT(v) (v##ULL)