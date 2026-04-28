#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

struct dyld_chained_fixups_header {
    uint32_t fixups_version;
    uint32_t starts_offset;
};

struct r_dyld_chained_starts_in_segment {
    uint32_t size;
    uint16_t page_size;
    uint16_t pointer_format;
    uint64_t segment_offset;
    int32_t max_valid_pointer;
    uint16_t page_count;
    uint16_t *page_start;
};

#define UT32_MAX UINT32_MAX
typedef uint32_t ut32;
typedef uint8_t ut8;
typedef uint16_t ut16;
typedef uint64_t ut64;

#define R_NEW0(x) calloc(1, sizeof(x))
#define R_NEWS0(x, y) calloc(y, sizeof(x))

struct MACH0_obj_t {
    void *b;
    struct r_dyld_chained_starts_in_segment **chained_starts;
    struct dyld_chained_fixups_header fixups_header;
    ut32 fixups_offset;
    ut32 fixups_size;
    ut32 nsegs;
    ut32 segs_count;
};
#define MACH0_(obj_t) MACH0_obj_t

extern size_t r_buf_size(void *b);
extern int r_buf_fread_at(void *b, ut64 offset, ut8 *buf, const char *fmt, int count);
extern ut32 r_buf_read_le32_at(void *b, ut64 offset);
extern void eprintf(const char *fmt, ...);