#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef int gboolean;
typedef unsigned char guint8;
typedef unsigned short guint16;
typedef unsigned int guint32;
typedef unsigned long long guint64;
typedef long long gint64;
typedef char gchar;

#define FALSE 0
#define TRUE 1

#define WTAP_ERR_BAD_FILE 1
#define NSPR_PAGESIZE_TRACE 4096

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

#define FULL 1

typedef struct {
    void* priv;
    void* fh;
} wtap;

typedef struct {
} wtap_rec;

typedef struct {
} Buffer;

typedef struct {
    gchar* pnstrace_buf;
    guint32 nstrace_buf_offset;
    guint32 nstrace_buflen;
    guint64 xxx_offset;
} nstrace_t;

typedef struct {
    guint8 phd_RecordType;
} nspr_hd_v20_t;

typedef struct {
    guint32 abs_Time;
    guint16 abs_RelTime;
} nspr_abstime_v20_t;

typedef struct {
} v30_full;

typedef struct {
} v35_full;

typedef struct {
} pktracefull_v30;

typedef struct {
} pktracefull_v35;

#define g_malloc malloc
#define g_strdup strdup
#define g_free free
#define PACKET_DESCRIBE(rec,buf,type,ver,struct_ver,fp,pktrace_struct,header_ver)

static gboolean nstrace_ensure_buflen(nstrace_t* nstrace, guint32 offset, guint32 size, int* err, gchar** err_info);
static void ns_setabstime(nstrace_t* nstrace, guint32 time, guint16 reltime);
static void ns_setrelativetime(nstrace_t* nstrace, guint16 reltime);
static guint32 nspr_getv20recordsize(nspr_hd_v20_t* hdp);
static guint32 pletoh32(const void* p);
static guint16 pletoh16(const void* p);
static int file_eof(void* fh);
static int file_read(void* buf, int size, void* fh);
static int file_error(void* fh, gchar** err_info);