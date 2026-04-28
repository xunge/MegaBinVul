#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef bool gboolean;
#define FALSE false
#define TRUE true

typedef int32_t gint32;
typedef int64_t gint64;
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
    gint64 xxx_offset;
    gint64 file_size;
} nstrace_t;

typedef struct nspr_header_v10_t {
    uint16_t ph_RecordType;
} nspr_header_v10_t;

typedef struct nspr_pktracefull_v10_t {
    uint16_t nsprRecordSize;
} nspr_pktracefull_v10_t;

typedef struct nspr_abstime_v10_t {
    uint32_t abs_Time;
    uint32_t abs_RelTime;
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

#define PACKET_DESCRIBE(phdr, type, name, ver, fp, HEADERVER)
static inline uint16_t pletoh16(const void *p) {
    const uint8_t *bytes = (const uint8_t *)p;
    return (bytes[1] << 8) | bytes[0];
}
static inline uint32_t pletoh32(const void *p) {
    const uint8_t *bytes = (const uint8_t *)p;
    return (bytes[3] << 24) | (bytes[2] << 16) | (bytes[1] << 8) | bytes[0];
}
#define GET_READ_PAGE_SIZE(size) (4096)

static int file_read(void *buf, int size, void *fh) { return 0; }
static void ns_setabstime(nstrace_t *nstrace, uint32_t time, uint32_t reltime) {}
static void ns_setrelativetime(nstrace_t *nstrace, uint32_t reltime) {}