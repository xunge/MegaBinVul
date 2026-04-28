#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef int gboolean;
typedef int32_t gint32;
typedef int64_t gint64;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint64_t guint64;
typedef char gchar;

typedef struct wtap {
    void *priv;
    void *phdr;
    void *fh;
} wtap;

typedef struct nstrace_t {
    guint64 nsg_creltime;
    gchar *pnstrace_buf;
    guint32 nstrace_buf_offset;
    guint32 nstrace_buflen;
    guint64 xxx_offset;
    guint64 file_size;
} nstrace_t;

typedef struct nspr_header_v10_t {
    guint16 ph_RecordType;
} nspr_header_v10_t;

typedef struct nspr_pktracefull_v10_t {
    guint16 nsprRecordSize;
} nspr_pktracefull_v10_t;

typedef struct nspr_abstime_v10_t {
    guint32 abs_Time;
    guint32 abs_RelTime;
} nspr_abstime_v10_t;

#define FALSE 0
#define TRUE 1
#define NSPR_PDPKTRACEFULLTX_V10 1
#define NSPR_PDPKTRACEFULLTXB_V10 2
#define NSPR_PDPKTRACEFULLRX_V10 3
#define NSPR_PDPKTRACEPARTTX_V10 4
#define NSPR_PDPKTRACEPARTTXB_V10 5
#define NSPR_PDPKTRACEPARTRX_V10 6
#define NSPR_ABSTIME_V10 7
#define NSPR_RELTIME_V10 8
#define NSPR_UNUSEDSPACE_V10 9
#define WTAP_ERR_BAD_FILE 0

#define PACKET_DESCRIBE(phdr, type, part, ver, fp, HEADERVER)

static inline guint16 pletoh16(const void *p) {
    const uint8_t *bytes = (const uint8_t *)p;
    return (bytes[1] << 8) | bytes[0];
}

static inline guint32 pletoh32(const void *p) {
    const uint8_t *bytes = (const uint8_t *)p;
    return (bytes[3] << 24) | (bytes[2] << 16) | (bytes[1] << 8) | bytes[0];
}

static char* g_strdup(const char *str) {
    char *new_str = malloc(strlen(str) + 1);
    if (new_str) strcpy(new_str, str);
    return new_str;
}

static void ns_setabstime(nstrace_t *nstrace, guint32 time, guint32 reltime) {}
static void ns_setrelativetime(nstrace_t *nstrace, guint32 reltime) {}
static int file_read(void *buf, size_t count, void *fh) { return 0; }
#define GET_READ_PAGE_SIZE(x) (x)