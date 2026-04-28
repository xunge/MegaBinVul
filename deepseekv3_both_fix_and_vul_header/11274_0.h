#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <inttypes.h>

#define NBD_REPLY_SIZE 16
#define NBD_REPLY_MAGIC 0x67446698

typedef struct QIOChannel QIOChannel;

typedef struct NBDReply {
    uint32_t error;
    uint64_t handle;
} NBDReply;

#define LOG(fmt, ...)
#define TRACE(fmt, ...)

static inline uint32_t ldl_be_p(const uint8_t *buf) {
    return (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];
}

static inline uint64_t ldq_be_p(const uint8_t *buf) {
    return ((uint64_t)buf[0] << 56) | ((uint64_t)buf[1] << 48) |
           ((uint64_t)buf[2] << 40) | ((uint64_t)buf[3] << 32) |
           ((uint64_t)buf[4] << 24) | ((uint64_t)buf[5] << 16) |
           ((uint64_t)buf[6] << 8) | (uint64_t)buf[7];
}

static ssize_t read_sync(QIOChannel *ioc, void *buf, size_t count);
static int nbd_errno_to_system_errno(int err);