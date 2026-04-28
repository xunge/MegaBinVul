#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <endian.h>

#define HIVEX_OPEN_MSGLVL_MASK 0x03
#define HIVEX_OPEN_WRITE 0x04
#define O_BINARY 0
#define STREQ(a, b) (strcmp((a), (b)) == 0)
#define DEBUG(level, ...) do { if (h->msglvl >= (level)) fprintf(stderr, __VA_ARGS__); } while (0)
#define SET_ERRNO(e, ...) do { errno = (e); DEBUG(1, __VA_ARGS__); } while (0)
#define BITMAP_SET(bm, off) ((bm)[(off)/8] |= (1 << ((off)%8)))
#define c_isprint(c) isprint((unsigned char)(c))

struct ntreg_header {
    char magic[4];
    uint32_t sequence1;
    uint32_t sequence2;
    uint64_t last_modified;
    uint32_t major_ver;
    uint32_t minor_ver;
    uint32_t offset;
    uint32_t blocks;
    uint32_t csum;
    char name[64];
};

struct ntreg_hbin_page {
    char magic[4];
    uint32_t page_size;
};

struct ntreg_hbin_block {
    uint32_t seg_len;
    char id[2];
};

typedef struct hive_h {
    int msglvl;
    int writable;
    char *filename;
    int fd;
    size_t size;
    void *addr;
    struct ntreg_header *hdr;
    unsigned char *bitmap;
    uint64_t last_modified;
    size_t rootoffs;
    size_t endpages;
} hive_h;

static size_t block_len(hive_h *h, size_t blkoff, int *used) { return 0; }
static uint32_t header_checksum(hive_h *h) { return 0; }
static ssize_t full_read(int fd, void *buf, size_t count) { return 0; }
static char *_hivex_windows_utf16_to_utf8(const void *input, size_t len) { return NULL; }