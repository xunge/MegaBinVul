#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define coroutine_fn
#define NBD_FLAG_HAS_FLAGS 0x01
#define NBD_FLAG_SEND_TRIM 0x02
#define NBD_FLAG_SEND_FLUSH 0x04
#define NBD_FLAG_SEND_FUA 0x08
#define NBD_FLAG_SEND_WRITE_ZEROES 0x10
#define NBD_CLIENT_MAGIC 0x4e42444d41474943ULL
#define NBD_OPTS_MAGIC 0x49484156454F5054ULL
#define NBD_FLAG_FIXED_NEWSTYLE 0x01
#define NBD_FLAG_NO_ZEROES 0x02
#define PRIu64 "llu"
#define EINVAL 22

typedef struct NBDExport {
    uint64_t size;
    uint16_t nbdflags;
} NBDExport;

typedef struct NBDClient {
    void *ioc;
    NBDExport *exp;
    bool tlscreds;
    bool no_zeroes;
} NBDClient;

typedef struct NBDClientNewData {
    NBDClient *client;
} NBDClientNewData;

#define TRACE(fmt, ...)
#define LOG(fmt, ...)

static inline void stq_be_p(void *ptr, uint64_t value) {
    uint8_t *p = ptr;
    p[0] = value >> 56;
    p[1] = value >> 48;
    p[2] = value >> 40;
    p[3] = value >> 32;
    p[4] = value >> 24;
    p[5] = value >> 16;
    p[6] = value >> 8;
    p[7] = value;
}

static inline void stw_be_p(void *ptr, uint16_t value) {
    uint8_t *p = ptr;
    p[0] = value >> 8;
    p[1] = value;
}

static int nbd_negotiate_write(void *ioc, const void *buf, size_t len) {
    return 0;
}

static int nbd_negotiate_options(NBDClient *client) {
    return 0;
}

static void qio_channel_set_blocking(void *ioc, bool blocking, void *errp) {
}