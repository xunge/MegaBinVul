#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#define UT32_MAX UINT32_MAX
#define UT32_MUL_OVFCHK(a, b) ((a) > (UT32_MAX / (b)))

typedef uint64_t ut64;
typedef uint32_t ut32;
typedef uint8_t ut8;
typedef int32_t st32;

typedef struct RBinFile RBinFile;
typedef struct RBuffer RBuffer;

typedef struct RCoreSymCacheElementHdr {
    int version;
    ut32 size;
    ut32 file_name_off;
    ut32 version_off;
    ut32 n_segments;
    ut32 n_sections;
    ut32 n_symbols;
    ut32 n_lined_symbols;
    ut32 n_line_info;
} RCoreSymCacheElementHdr;

typedef struct RCoreSymCacheElementSegment {
    ut64 paddr;
    ut64 vaddr;
    ut64 size;
    ut64 vsize;
    char *name;
} RCoreSymCacheElementSegment;

typedef struct RCoreSymCacheElementSection {
    ut64 paddr;
    ut64 vaddr;
    ut64 size;
    char *name;
} RCoreSymCacheElementSection;

typedef struct RCoreSymCacheElementSymbol {
    ut32 paddr;
    ut32 size;
    ut32 unk1;
    ut32 unk2;
    char *name;
    char *mangled_name;
} RCoreSymCacheElementSymbol;

typedef struct RFLocation {
    char *file;
    ut32 line;
    ut32 col;
} RFLocation;

typedef struct RCoreSymCacheElementLinedSymbol {
    RCoreSymCacheElementSymbol sym;
    RFLocation flc;
} RCoreSymCacheElementLinedSymbol;

typedef struct RCoreSymCacheElementLineInfo {
    ut32 paddr;
    ut32 size;
    RFLocation flc;
} RCoreSymCacheElementLineInfo;

typedef struct RCoreSymCacheElement {
    RCoreSymCacheElementHdr *hdr;
    char *file_name;
    char *binary_version;
    RCoreSymCacheElementSegment *segments;
    RCoreSymCacheElementSection *sections;
    RCoreSymCacheElementSymbol *symbols;
    RCoreSymCacheElementLinedSymbol *lined_symbols;
    RCoreSymCacheElementLineInfo *line_info;
} RCoreSymCacheElement;

#define R_NEW0(x) calloc(1, sizeof(x))
#define R_NEWS0(x, n) calloc(n, sizeof(x))

#define R_CS_EL_SIZE_SEG 32
#define R_CS_EL_OFF_SEGS 0x20
#define R_CS_EL_SIZE_SECT_32 12
#define R_CS_EL_SIZE_SECT_64 24
#define R_CS_EL_SIZE_SYM 24
#define R_CS_EL_SIZE_LSYM 36
#define R_CS_EL_SIZE_LINFO 20

static inline ut64 r_read_le64(const ut8 *src) {
    return (ut64)src[0] | ((ut64)src[1] << 8) | ((ut64)src[2] << 16) | ((ut64)src[3] << 24) |
           ((ut64)src[4] << 32) | ((ut64)src[5] << 40) | ((ut64)src[6] << 48) | ((ut64)src[7] << 56);
}

static inline ut32 r_read_le32(const ut8 *src) {
    return (ut32)src[0] | ((ut32)src[1] << 8) | ((ut32)src[2] << 16) | ((ut32)src[3] << 24);
}

static inline ut64 r_read_ble(const ut8 *src, bool big_endian, int bits) {
    if (bits == 32) {
        ut32 val = r_read_le32(src);
        return big_endian ? ((val >> 24) | ((val >> 8) & 0xff00) | ((val << 8) & 0xff0000) | (val << 24)) : val;
    } else {
        ut64 val = r_read_le64(src);
        return big_endian ? ((val >> 56) | ((val >> 40) & 0xff00) | ((val >> 24) & 0xff0000) | ((val >> 8) & 0xff000000) |
                           ((val << 8) & 0xff00000000) | ((val << 24) & 0xff0000000000) | ((val << 40) & 0xff000000000000) | (val << 56)) : val;
    }
}

static char *str_dup_safe(const ut8 *b, const ut8 *start, const ut8 *end) {
    if (start < b || start >= end) {
        return NULL;
    }
    size_t max_len = (size_t)(end - start);
    size_t len = strnlen((const char *)start, max_len);
    if (len == max_len) {
        return NULL;
    }
    return strndup((const char *)start, len);
}

static char *str_dup_safe_fixed(const ut8 *b, const ut8 *start, size_t fixed_len, const ut8 *end) {
    if (start < b || start + fixed_len > end) {
        return NULL;
    }
    size_t len = strnlen((const char *)start, fixed_len);
    return strndup((const char *)start, len);
}

static void eprintf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}

static RCoreSymCacheElementHdr *r_coresym_cache_element_header_new(RBuffer *buf, ut64 off, int bits) {
    return NULL;
}

static ut64 r_coresym_cache_element_pa2va(RCoreSymCacheElement *element, ut64 pa) {
    return 0;
}

static void meta_add_fileline(RBinFile *bf, ut64 va, ut64 size, RFLocation *flc) {
}

static ut64 r_buf_size(RBuffer *buf) {
    return 0;
}

static ut64 r_buf_read_at(RBuffer *buf, ut64 off, ut8 *b, ut64 size) {
    return 0;
}