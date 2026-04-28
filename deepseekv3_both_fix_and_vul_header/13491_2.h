#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef int32_t gint32;
typedef int64_t gint64;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint64_t guint64;
typedef char gchar;

typedef struct wtap {
    void *priv;
    FILE *fh;
} wtap;

typedef struct wtap_rec wtap_rec;
typedef struct Buffer Buffer;

typedef struct nstrace_t {
    guint64 nsg_creltime;
    gchar *pnstrace_buf;
    guint32 nstrace_buf_offset;
    guint32 nstrace_buflen;
    gint64 file_size;
    gint64 xxx_offset;
} nstrace_t;

typedef struct nspr_header_v10_t {
    guint16 ph_RecordType;
    guint16 nsprRecordSize;
} nspr_header_v10_t;

typedef struct nspr_pktracefull_v10_t {
    guint16 ph_RecordType;
    guint16 nsprRecordSize;
} nspr_pktracefull_v10_t;

typedef struct nspr_abstime_v10_t {
    guint16 ph_RecordType;
    guint16 nsprRecordSize;
    guint32 abs_Time;
    guint32 abs_RelTime;
} nspr_abstime_v10_t;

#define NSPR_PDPKTRACEFULLTX_V10 1
#define NSPR_PDPKTRACEFULLTXB_V10 2
#define NSPR_PDPKTRACEFULLRX_V10 3
#define NSPR_PDPKTRACEPARTTX_V10 4
#define NSPR_PDPKTRACEPARTTXB_V10 5
#define NSPR_PDPKTRACEPARTRX_V10 6
#define NSPR_ABSTIME_V10 7
#define NSPR_RELTIME_V10 8
#define NSPR_UNUSEDSPACE_V10 9

#define WTAP_ERR_BAD_FILE 1

#define PACKET_DESCRIBE(rec,buf,type,prefix,ver,ptr,HEADERVER)

static guint16 pletoh16(const guint16 *p) {
    return *p;
}

static guint32 pletoh32(const guint32 *p) {
    return *p;
}

static void ns_setabstime(nstrace_t *nstrace, guint32 time, guint32 reltime) {
    nstrace->nsg_creltime = time;
}

static void ns_setrelativetime(nstrace_t *nstrace, guint32 reltime) {
    nstrace->nsg_creltime = reltime;
}

static gboolean nstrace_read_buf(FILE *fh, gchar *buf, guint32 buflen, int *err, gchar **err_info) {
    return fread(buf, 1, buflen, fh) == buflen;
}

static guint32 GET_READ_PAGE_SIZE(guint64 remaining) {
    return (guint32)(remaining > 4096 ? 4096 : remaining);
}

static char *g_strdup(const char *str) {
    if (!str) return NULL;
    char *new_str = malloc(strlen(str) + 1);
    if (new_str) strcpy(new_str, str);
    return new_str;
}