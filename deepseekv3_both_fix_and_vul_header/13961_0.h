#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define CLI_ISCONTAINED(bb, bb_size, b, s) ((bb) <= (b) && (bb_size) >= (s) && (bb_size) - ((b) - (bb)) >= (s))
#define cli_readint32(p) (*(uint32_t *)(p))
#define cli_writeint32(p, v) (*(uint32_t *)(p) = (v))
#define cli_dbgmsg(...)
#define cli_writen(fd, buf, sz) write(fd, buf, sz)
#define CL_EFORMAT 1

struct cli_exe_section {
    uint32_t rva;
    uint32_t vsz;
    uint32_t rsz;
};

#define RESEED do { bits = 0; bt = 0; } while(0)
#define BIT do { \
    if(!bt) { \
        if(ccur >= compd + szd) { error = 1; break; } \
        bc = *ccur++; \
        bt = 8; \
    } \
    bits = (bc >> 7) & 1; \
    bc <<= 1; \
    bt--; \
} while(0)

#define BITS(n) do { \
    bits = 0; \
    for(i = 0; i < (n); i++) { \
        BIT; \
        if(error) break; \
        bits = (bits << 1) | bits; \
    } \
} while(0)