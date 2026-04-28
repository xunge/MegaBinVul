#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BGP_MAX_SOFT_VERSION 255

struct capability_header {
    uint16_t length;
};

struct peer {
    uint32_t cap;
    char *host;
    char *soft_version;
};

struct stream;

#define SET_FLAG(flags, flag) ((flags) |= (flag))
#define XFREE(type, ptr) free(ptr)
#define XSTRDUP(type, str) strdup(str)
#define MTYPE_BGP_SOFT_VERSION 0

enum {
    PEER_CAP_SOFT_VERSION_RCV,
};

enum {
    EC_BGP_CAPABILITY_INVALID_DATA,
    EC_BGP_CAPABILITY_INVALID_LENGTH,
};

#define BGP_INPUT(peer) ((struct stream *)NULL)

static inline uint8_t stream_getc(struct stream *s) { return 0; }
static inline void stream_get(void *buf, struct stream *s, size_t len) {}
static inline void stream_forward_getp(struct stream *s, size_t len) {}
static inline size_t stream_get_getp(struct stream *s) { return 0; }

static inline int bgp_debug_neighbor_events(struct peer *peer) { return 0; }
static inline void flog_warn(int code, const char *fmt, ...) {}
static inline void zlog_debug(const char *fmt, ...) {}