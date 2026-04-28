#include <stdint.h>
#include <inttypes.h>
#include <unistd.h>
#include <endian.h>

#define NBD_REP_MAGIC 0x3e889045565a9ULL
#define PRIx32 "x"
#define PRIu32 "u"
#define TRACE(fmt, ...)
#define LOG(fmt)
#define EINVAL 22

typedef struct QIOChannel QIOChannel;

static int nbd_negotiate_write(QIOChannel *ioc, const void *data, size_t size);

static inline uint64_t cpu_to_be64(uint64_t x) {
    return htobe64(x);
}

static inline uint32_t cpu_to_be32(uint32_t x) {
    return htobe32(x);
}