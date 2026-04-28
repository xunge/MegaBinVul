#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

typedef uint64_t ut64;
typedef uint8_t ut8;

typedef struct cache_accel_t {
    ut64 imagesExtrasOffset;
    ut64 bottomUpListOffset;
    ut64 dylibTrieOffset;
    ut64 initializersOffset;
    ut64 dofSectionsOffset;
    ut64 reExportListOffset;
    ut64 depListOffset;
    ut64 rangeTableOffset;
} cache_accel_t;

typedef struct cache_hdr_t {
    ut64 accelerateInfoSize;
    ut64 accelerateInfoAddr;
    ut64 mappingCount;
} cache_hdr_t;

typedef struct cache_map_t {
    // Define fields as needed
} cache_map_t;

typedef struct RBuffer {
    // Define fields as needed
} RBuffer;

#define R_NEW0(type) ((type *)calloc(1, sizeof(type)))
#define R_FREE(ptr) free(ptr)

ut64 va2pa(ut64 va, ut64 mappingCount, cache_map_t *maps, RBuffer *cache_buf, int perm, void *sym, void *sym_name);
size_t r_buf_fread_at(RBuffer *buf, ut64 addr, ut8 *buf_out, const char *fmt, int n);