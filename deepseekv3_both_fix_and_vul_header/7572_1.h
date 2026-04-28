#include <stdlib.h>
#include <stdint.h>

typedef uint8_t ut8;
typedef uint16_t ut16;
typedef uint32_t ut32;
typedef uint64_t ut64;

typedef struct r_list_t RList;
typedef struct r_buf_t RBuffer;

typedef struct r_bin_addr_t {
    ut64 paddr;
    int bits;
} RBinAddr;

typedef struct r_bin_section_t {
    ut64 paddr;
} RBinSection;

typedef struct r_bin_ne_segment_entry_t {
    ut32 offset;
} r_bin_ne_segment_entry_t;

typedef struct r_bin_ne_header_t {
    ut16 csEntryPoint;
    ut16 ipEntryPoint;
    ut16 EntryTableOffset;
    ut16 EntryTableLength;
    ut16 SegCount;
} r_bin_ne_header_t;

typedef struct r_bin_ne_obj_t {
    r_bin_ne_header_t *ne_header;
    size_t header_offset;
    RBuffer *buf;
    ut8 *entry_table;
    r_bin_ne_segment_entry_t *segment_entries;
    ut32 alignment;
    RList *entries;
} r_bin_ne_obj_t;

#define R_NEW0(x) calloc(1, sizeof(x))