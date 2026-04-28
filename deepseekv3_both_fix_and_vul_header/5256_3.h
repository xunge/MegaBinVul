#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef int8_t gint8;
typedef uint8_t guint8;
typedef int16_t gint16;
typedef uint16_t guint16;
typedef int32_t gint32;
typedef uint32_t guint32;
typedef int64_t gint64;
typedef uint64_t guint64;
typedef char gchar;

typedef struct wtap {
    void *priv;
    void *phdr;
    FILE *fh;
} wtap;

typedef struct nstrace_t {
    guint64 nsg_creltime;
    gchar *pnstrace_buf;
    guint32 nstrace_buf_offset;
    guint32 nstrace_buflen;
    guint64 xxx_offset;
    guint64 file_size;
} nstrace_t;

typedef struct nspr_hd_v20_t {
    guint16 phd_RecordType;
} nspr_hd_v20_t;

typedef struct nspr_pktracefull_v20_t {
    nspr_hd_v20_t hdr;
} nspr_pktracefull_v20_t;

typedef struct nspr_abstime_v20_t {
    guint32 abs_Time;
    guint16 abs_RelTime;
} nspr_abstime_v20_t;

#define WTAP_ERR_BAD_FILE 0
#define NSPR_PAGESIZE 4096

#define NSPR_PDPKTRACEFULLTX_V20 1
#define NSPR_PDPKTRACEFULLTXB_V20 2
#define NSPR_PDPKTRACEFULLRX_V20 3
#define NSPR_PDPKTRACEFULLNEWRX_V20 4
#define NSPR_PDPKTRACEPARTTX_V20 5
#define NSPR_PDPKTRACEPARTTXB_V20 6
#define NSPR_PDPKTRACEPARTRX_V20 7
#define NSPR_PDPKTRACEPARTNEWRX_V20 8
#define NSPR_ABSTIME_V20 9
#define NSPR_RELTIME_V20 10
#define NSPR_UNUSEDSPACE_V20 11

#define NSPR_PDPKTRACEFULLTX_V21 12
#define NSPR_PDPKTRACEFULLTXB_V21 13
#define NSPR_PDPKTRACEFULLRX_V21 14
#define NSPR_PDPKTRACEPARTTX_V21 15
#define NSPR_PDPKTRACEPARTTXB_V21 16
#define NSPR_PDPKTRACEPARTRX_V21 17

#define NSPR_PDPKTRACEFULLTX_V22 18
#define NSPR_PDPKTRACEFULLTXB_V22 19
#define NSPR_PDPKTRACEFULLRX_V22 20
#define NSPR_PDPKTRACEPARTTX_V22 21
#define NSPR_PDPKTRACEPARTTXB_V22 22
#define NSPR_PDPKTRACEPARTRX_V22 23

#define NSPR_PDPKTRACEFULLTX_V23 24
#define NSPR_PDPKTRACEFULLTXB_V23 25
#define NSPR_PDPKTRACEFULLRX_V23 26
#define NSPR_PDPKTRACEPARTTX_V23 27
#define NSPR_PDPKTRACEPARTTXB_V23 28
#define NSPR_PDPKTRACEPARTRX_V23 29

#define NSPR_PDPKTRACEFULLTX_V24 30
#define NSPR_PDPKTRACEFULLTXB_V24 31
#define NSPR_PDPKTRACEFULLRX_V24 32
#define NSPR_PDPKTRACEFULLNEWRX_V24 33
#define NSPR_PDPKTRACEPARTTX_V24 34
#define NSPR_PDPKTRACEPARTTXB_V24 35
#define NSPR_PDPKTRACEPARTRX_V24 36
#define NSPR_PDPKTRACEPARTNEWRX_V24 37

#define NSPR_PDPKTRACEFULLTX_V25 38
#define NSPR_PDPKTRACEFULLTXB_V25 39
#define NSPR_PDPKTRACEFULLRX_V25 40
#define NSPR_PDPKTRACEFULLNEWRX_V25 41
#define NSPR_PDPKTRACEPARTTX_V25 42
#define NSPR_PDPKTRACEPARTTXB_V25 43
#define NSPR_PDPKTRACEPARTRX_V25 44
#define NSPR_PDPKTRACEPARTNEWRX_V25 45

#define NSPR_PDPKTRACEFULLTX_V26 46
#define NSPR_PDPKTRACEFULLTXB_V26 47
#define NSPR_PDPKTRACEFULLRX_V26 48
#define NSPR_PDPKTRACEFULLNEWRX_V26 49
#define NSPR_PDPKTRACEPARTTX_V26 50
#define NSPR_PDPKTRACEPARTTXB_V26 51
#define NSPR_PDPKTRACEPARTRX_V26 52
#define NSPR_PDPKTRACEPARTNEWRX_V26 53

#define PACKET_DESCRIBE(a,b,c,d,e,f,g)
#define pletoh32(x) (x)
#define pletoh16(x) (x)
#define GET_READ_PAGE_SIZE(size) (size)

static guint32 nspr_getv20recordsize(nspr_hd_v20_t *hdr) { return sizeof(*hdr); }
static void ns_setabstime(nstrace_t *nstrace, guint32 time, guint16 reltime) {}
static void ns_setrelativetime(nstrace_t *nstrace, guint16 reltime) {}
static gboolean nstrace_read_buf(FILE *fh, gchar *buf, guint32 buflen, int *err, gchar **err_info) { return FALSE; }
static char* g_strdup(const char *str) { return str ? strdup(str) : NULL; }