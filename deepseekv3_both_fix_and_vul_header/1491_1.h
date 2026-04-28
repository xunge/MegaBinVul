#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define RZ_NEW0(x) calloc(1, sizeof(x))
#define RZ_NEWS0(x, n) calloc(n, sizeof(x))
#define MAX_N_HDR 16
#define UT64_MAX UINT64_MAX

typedef uint32_t ut32;
typedef uint64_t ut64;
typedef uint8_t ut8;

typedef struct rz_buf_t RzBuffer;

typedef struct {
    ut64 fileOffset;
    ut64 size;
    ut32 slideInfoOffset;
    ut32 slideInfoSize;
} cache_mapping_slide;

typedef struct {
    ut64 slide;
} RzDyldRebaseInfo;

typedef struct {
    ut64 start;
    ut64 end;
    RzDyldRebaseInfo *info;
} RzDyldRebaseInfosEntry;

typedef struct {
    RzDyldRebaseInfosEntry *entries;
    ut32 length;
} RzDyldRebaseInfos;

typedef struct {
    ut32 slideInfoOffset;
    ut32 slideInfoSize;
    ut32 mappingCount;
} rz_dyld_cache_header;

typedef struct {
    ut64 fileOffset;
    ut64 size;
} rz_dyld_cache_map;

typedef struct {
    RzBuffer *buf;
    rz_dyld_cache_header *hdr;
    rz_dyld_cache_map *maps;
    ut64 *hdr_offset;
    ut32 n_hdr;
} RzDyldCache;

int rz_buf_read_le32_at(RzBuffer *buf, ut64 offset, ut32 *result);
size_t rz_buf_fread_at(RzBuffer *buf, ut64 offset, ut8 *out, const char *fmt, int n);
RzDyldRebaseInfo *get_rebase_info(RzDyldCache *cache, ut64 offset, ut32 size, ut64 start, ut64 slide);