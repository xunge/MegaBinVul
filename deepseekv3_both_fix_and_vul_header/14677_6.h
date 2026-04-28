#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef bool gboolean;
typedef char gchar;
typedef int32_t gint32;
typedef int64_t gint64;
typedef uint32_t guint32;
typedef uint64_t guint64;
typedef uint16_t guint16;

typedef struct nspr_hd_v20 {
    guint32 phd_RecordType;
} nspr_hd_v20_t;

typedef struct nspr_pktracefull_v20 {
    nspr_hd_v20_t hdr;
} nspr_pktracefull_v20_t;

typedef struct nspr_abstime_v20 {
    guint32 abs_Time;
    guint16 abs_RelTime;
} nspr_abstime_v20_t;

typedef struct nstrace {
    guint64 nsg_creltime;
    gchar* pnstrace_buf;
    guint32 nstrace_buf_offset;
    guint32 nstrace_buflen;
    guint64 xxx_offset;
    guint64 file_size;
} nstrace_t;

typedef struct wtap {
    void* priv;
    void* phdr;
    void* fh;
} wtap;

#define NSPR_PAGESIZE 8192
#define NSPR_ABSTIME_V20 1
#define NSPR_RELTIME_V20 2
#define NSPR_UNUSEDSPACE_V20 3

#define NSPR_PDPKTRACEFULLTX_V20 10
#define NSPR_PDPKTRACEFULLTXB_V20 11
#define NSPR_PDPKTRACEFULLRX_V20 12
#define NSPR_PDPKTRACEPARTTX_V20 13
#define NSPR_PDPKTRACEPARTTXB_V20 14
#define NSPR_PDPKTRACEPARTRX_V20 15

#define NSPR_PDPKTRACEFULLTX_V21 20
#define NSPR_PDPKTRACEFULLTXB_V21 21
#define NSPR_PDPKTRACEFULLRX_V21 22
#define NSPR_PDPKTRACEPARTTX_V21 23
#define NSPR_PDPKTRACEPARTTXB_V21 24
#define NSPR_PDPKTRACEPARTRX_V21 25

#define NSPR_PDPKTRACEFULLTX_V22 30
#define NSPR_PDPKTRACEFULLTXB_V22 31
#define NSPR_PDPKTRACEFULLRX_V22 32
#define NSPR_PDPKTRACEPARTTX_V22 33
#define NSPR_PDPKTRACEPARTTXB_V22 34
#define NSPR_PDPKTRACEPARTRX_V22 35

#define NSPR_PDPKTRACEFULLTX_V23 40
#define NSPR_PDPKTRACEFULLTXB_V23 41
#define NSPR_PDPKTRACEFULLRX_V23 42
#define NSPR_PDPKTRACEPARTTX_V23 43
#define NSPR_PDPKTRACEPARTTXB_V23 44
#define NSPR_PDPKTRACEPARTRX_V23 45

#define NSPR_PDPKTRACEFULLTX_V24 50
#define NSPR_PDPKTRACEFULLTXB_V24 51
#define NSPR_PDPKTRACEFULLRX_V24 52
#define NSPR_PDPKTRACEFULLNEWRX_V24 53
#define NSPR_PDPKTRACEPARTTX_V24 54
#define NSPR_PDPKTRACEPARTTXB_V24 55
#define NSPR_PDPKTRACEPARTRX_V24 56
#define NSPR_PDPKTRACEPARTNEWRX_V24 57

#define NSPR_PDPKTRACEFULLTX_V25 60
#define NSPR_PDPKTRACEFULLTXB_V25 61
#define NSPR_PDPKTRACEFULLRX_V25 62
#define NSPR_PDPKTRACEFULLNEWRX_V25 63
#define NSPR_PDPKTRACEPARTTX_V25 64
#define NSPR_PDPKTRACEPARTTXB_V25 65
#define NSPR_PDPKTRACEPARTRX_V25 66
#define NSPR_PDPKTRACEPARTNEWRX_V25 67

#define NSPR_PDPKTRACEFULLTX_V26 70
#define NSPR_PDPKTRACEFULLTXB_V26 71
#define NSPR_PDPKTRACEFULLRX_V26 72
#define NSPR_PDPKTRACEFULLNEWRX_V26 73
#define NSPR_PDPKTRACEPARTTX_V26 74
#define NSPR_PDPKTRACEPARTTXB_V26 75
#define NSPR_PDPKTRACEPARTRX_V26 76
#define NSPR_PDPKTRACEPARTNEWRX_V26 77

#define PACKET_DESCRIBE(phdr, type, ver, v_ver, fp, pktrace, HEADERVER)
#define GET_READ_PAGE_SIZE(size) (size)
#define pletoh32(ptr) (*(guint32*)(ptr))
#define pletoh16(ptr) (*(guint16*)(ptr))
#define FALSE false

static guint32 nspr_getv20recordsize(nspr_hd_v20_t *hd) { return 0; }
static void ns_setabstime(nstrace_t *nstrace, guint32 time, guint16 reltime) {}
static void ns_setrelativetime(nstrace_t *nstrace, guint16 reltime) {}
static int file_read(void *buf, int size, void *fh) { return 0; }