#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define GFP_KERNEL 0
#define PAGE_SIZE 4096
#define MAX_WBITS 15
#define Z_OK 0
#define Z_STREAM_END 1
#define EINVAL 22
#define ENOMEM 12

struct load_info;
struct page;

struct z_stream_s {
    void *workspace;
    const unsigned char *next_in;
    unsigned int avail_in;
    unsigned char *next_out;
    unsigned int avail_out;
};

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void *kmap_local_page(struct page *page) { return NULL; }
static inline void kunmap_local(void *addr) {}
static inline size_t zlib_inflate_workspacesize(void) { return 0; }
static inline int zlib_inflateInit2(struct z_stream_s *strm, int windowBits) { return 0; }
static inline int zlib_inflate(struct z_stream_s *strm, int flush) { return 0; }
static inline int zlib_inflateEnd(struct z_stream_s *strm) { return 0; }
static inline size_t module_gzip_header_len(const void *buf, size_t size) { return 0; }
static inline struct page *module_get_next_page(struct load_info *info) { return NULL; }
static inline void pr_err(const char *fmt, ...) {}