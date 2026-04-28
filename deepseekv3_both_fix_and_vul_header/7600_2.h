#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <stdarg.h>

typedef uint64_t ut64;
typedef uint32_t ut32;
typedef int32_t st32;
typedef uint8_t ut8;

#define UT32_MAX UINT32_MAX
#define UT64_MAX UINT64_MAX

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

#define R_NEW0(x) ((x*)calloc(1,sizeof(x)))
#define R_NEWS0(x,y) ((x*)calloc(y,sizeof(x)))
#define UT32_MUL_OVFCHK(a,b) ((a) > (UT32_MAX / (b)))

#define R_CS_EL_SIZE_SEG 32
#define R_CS_EL_OFF_SEGS 24
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
        return big_endian ? __builtin_bswap32(val) : val;
    }
    ut64 val = r_read_le64(src);
    return big_endian ? __builtin_bswap64(val) : val;
}

static inline char *str_dup_safe(const ut8 *origin, const ut8 *str, const ut8 *end) {
    if (str >= end) return NULL;
    return strdup((const char*)str);
}

static inline char *str_dup_safe_fixed(const ut8 *origin, const ut8 *str, size_t len, const ut8 *end) {
    if (str + len > end) return NULL;
    char *res = malloc(len + 1);
    if (!res) return NULL;
    memcpy(res, str, len);
    res[len] = 0;
    return res;
}

static inline ut64 r_coresym_cache_element_pa2va(RCoreSymCacheElement *element, ut64 pa) {
    return pa;
}

static inline void meta_add_fileline(RBinFile *bf, ut64 va, ut64 sz, RFLocation *flc) {
}

static inline RCoreSymCacheElementHdr *r_coresym_cache_element_header_new(RBuffer *buf, ut64 off, int bits) {
    return NULL;
}

static inline size_t r_buf_size(RBuffer *buf) {
    return 0;
}

static inline size_t r_buf_read_at(RBuffer *buf, ut64 off, ut8 *b, size_t len) {
    return 0;
}

static inline void eprintf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}