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

#define HIVEX_OPEN_MSGLVL_MASK 0xff
#define HIVEX_OPEN_WRITE 0x100
#define O_BINARY 0
#define STREQ(a,b) (strcmp((a),(b)) == 0)
#define DEBUG(level, ...) 
#define SET_ERRNO(err, ...) (errno = (err))
#define BITMAP_SET(bitmap, offset) 
#define c_isprint(c) isprint((unsigned char)(c))

struct ntreg_header {
    char magic[4];
    uint32_t major_ver;
    uint32_t minor_ver;
    uint32_t sequence1;
    uint32_t sequence2;
    uint64_t last_modified;
    char name[64];
    uint32_t offset;
    uint32_t blocks;
    uint32_t csum;
};

struct ntreg_hbin_page {
    char magic[4];
    uint32_t page_size;
};

struct ntreg_hbin_block {
    char id[2];
    uint32_t seg_len;
};

typedef struct hive_h {
    int msglvl;
    int writable;
    char *filename;
    int fd;
    size_t size;
    void *addr;
    struct ntreg_header *hdr;
    char *bitmap;
    uint64_t last_modified;
    size_t rootoffs;
    size_t endpages;
} hive_h;

static size_t block_len(hive_h *h, size_t blkoff, int *used);
static size_t full_read(int fd, void *buf, size_t count);
static uint32_t header_checksum(hive_h *h);
static char *_hivex_windows_utf16_to_utf8(const void *input, size_t len);
static uint32_t le32toh(uint32_t x);
static uint64_t le64toh(uint64_t x);