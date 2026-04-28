#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <stdbool.h>

#define I64d "ld"

typedef unsigned long uLong;
typedef unsigned long uLongf;

typedef struct AFFILE {
    int openmode;
    size_t image_pagesize;
    size_t image_sectorsize;
    unsigned char *badflag;
    size_t bytes_memcpy;
    void (*error_reporter)(const char *fmt, ...);
    int pages_decompressed;
    FILE *trace;
} AFFILE;

#define AF_BADBLOCK_FILL 1
#define AF_PAGE_COMPRESSED 1
#define AF_PAGE_COMP_ALG_MASK 0x0f
#define AF_PAGE_COMP_ALG_ZERO 0
#define AF_PAGE_COMP_ALG_ZLIB 1
#define AF_PAGE_COMP_ALG_LZMA 2

#define Z_OK 0
#define Z_ERRNO (-1)
#define Z_STREAM_ERROR (-2)
#define Z_DATA_ERROR (-3)
#define Z_MEM_ERROR (-4)
#define Z_BUF_ERROR (-5)
#define Z_VERSION_ERROR (-6)

extern FILE *af_trace;
extern int af_get_page_raw(AFFILE *af, int64_t pagenum, uint32_t *arg, unsigned char *data, size_t *bytes);
extern int uncompress(unsigned char *dest, uLongf *destLen, const unsigned char *source, uLong sourceLen);