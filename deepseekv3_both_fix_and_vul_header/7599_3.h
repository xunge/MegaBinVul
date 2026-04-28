#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef uint64_t ut64;
typedef uint16_t ut16;

typedef struct NE_image_segment_entry {
    ut16 offset;
    ut16 length;
    ut16 flags;
    ut16 minAllocSz;
} NE_image_segment_entry;

typedef struct RBinSection {
    ut64 size;
    ut64 vsize;
    int bits;
    bool is_data;
    int perm;
    ut64 paddr;
    char *name;
    bool is_segment;
} RBinSection;

typedef struct RList {
    void *head;
    void *tail;
    size_t length;
    void (*free)(void *);
} RList;

typedef struct {
    int SegCount;
} NE_header;

typedef struct r_bin_ne_obj_t {
    NE_header *ne_header;
    NE_image_segment_entry *segment_entries;
    int alignment;
    RList *segments;
} r_bin_ne_obj_t;

#define IS_DATA 1
#define IS_MOVEABLE 2
#define R_SYS_BITS_16 16
#define PFMT64d "llu"

#define R_NEW0(x) calloc(1, sizeof(x))