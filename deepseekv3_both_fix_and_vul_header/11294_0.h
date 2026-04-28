#include <stdint.h>
#include <string.h>

typedef struct QIOChannel QIOChannel;
typedef struct NBDExport {
    const char *name;
    const char *description;
} NBDExport;

#define NBD_REP_SERVER 0
#define NBD_OPT_LIST 0
#define TRACE(fmt, ...)
#define LOG(fmt)
#define EINVAL 22

static int nbd_negotiate_send_rep_len(QIOChannel *ioc, int rep, int opt, uint32_t len);
static int nbd_negotiate_write(QIOChannel *ioc, const void *buffer, size_t size);
static uint32_t cpu_to_be32(uint32_t x);