#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

struct cli_exe_section {
    uint32_t rva;
    uint32_t vsz;
    uint32_t rsz;
};

#define CLI_ISCONTAINED(bb, bb_size, b, s) \
    ((bb) <= (b) && (bb_size) >= ((size_t)((b) - (bb)) + (s)))

static inline uint32_t cli_readint32(const void *p) {
    return *(const uint32_t*)p;
}

static inline void cli_writeint32(void *p, uint32_t v) {
    *(uint32_t*)p = v;
}

#define cli_malloc(s) malloc(s)
#define cli_writen(fd, buf, sz) write(fd, buf, sz)
#define cli_dbgmsg(...)

#define RESEED
#define BIT
#define BITS(n)