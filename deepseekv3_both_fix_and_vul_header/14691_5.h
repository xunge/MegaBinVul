#include <stdint.h>
#include <string.h>

#define NSPR_PAGESIZE_TRACE 4096
#define WTAP_ERR_BAD_FILE 0
#define FALSE 0

typedef int gboolean;
typedef char gchar;
typedef int64_t gint64;
typedef uint32_t guint32;
typedef uint64_t guint64;
typedef uint16_t guint16;
typedef uint8_t guint8;

typedef struct wtap {
    void *priv;
    void *fh;
    struct {
        int phdr;
    } phdr;
} wtap;

typedef struct nstrace_t {
    char *pnstrace_buf;
    guint32 nstrace_buf_offset;
    guint32 nstrace_buflen;
    guint32 xxx_offset;
} nstrace_t;

typedef struct nspr_hd_v20_t {
    guint32 phd_RecordType;
} nspr_hd_v20_t;

typedef struct nspr_abstime_v20_t {
    guint32 abs_Time;
    guint16 abs_RelTime;
} nspr_abstime_v20_t;

#define NSPR_PDPKTRACEFULLTX_V30 1
#define NSPR_PDPKTRACEFULLTXB_V30 2
#define NSPR_PDPKTRACEFULLRX_V30 3
#define NSPR_PDPKTRACEFULLNEWRX_V30 4
#define NSPR_PDPKTRACEFULLTX_V35 5
#define NSPR_PDPKTRACEFULLTXB_V35 6
#define NSPR_PDPKTRACEFULLRX_V35 7
#define NSPR_PDPKTRACEFULLNEWRX_V35 8
#define NSPR_ABSTIME_V20 9
#define NSPR_RELTIME_V20 10

#define PACKET_DESCRIBE(a,b,c,d,e,f,g)
#define pletoh32(x) (x)
#define pletoh16(x) (x)

static int file_eof(void *fh) { return 0; }
static int file_read(void *buf, int size, void *fh) { return 0; }
static void ns_setabstime(nstrace_t *nstrace, guint32 time, guint16 reltime) {}
static void ns_setrelativetime(nstrace_t *nstrace, guint16 reltime) {}
static guint32 nspr_getv20recordsize(nspr_hd_v20_t *hdp) { return 0; }
static char* g_strdup(const char *str) { return NULL; }