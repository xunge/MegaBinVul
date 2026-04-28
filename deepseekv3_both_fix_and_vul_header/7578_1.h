#include <stdlib.h>
#include <stdint.h>

typedef uint8_t ut8;
typedef uint16_t ut16;
typedef uint32_t ut32;
typedef uint64_t ut64;

typedef struct r_bin_ne_obj_t r_bin_ne_obj_t;
typedef struct r_list_t RList;
typedef struct r_buf_t r_buf_t;
typedef struct r_bin_addr_t RBinAddr;
typedef struct r_bin_section_t RBinSection;
typedef struct r_bin_ne_header_t r_bin_ne_header_t;
typedef struct r_bin_ne_segment_entry_t r_bin_ne_segment_entry_t;

struct r_bin_addr_t {
    ut64 paddr;
    int bits;
};

struct r_bin_section_t {
    ut64 paddr;
};

struct r_bin_ne_header_t {
    ut16 csEntryPoint;
    ut16 ipEntryPoint;
    ut16 EntryTableOffset;
    ut16 EntryTableLength;
    ut16 SegCount;
};

struct r_bin_ne_segment_entry_t {
    ut32 offset;
};

struct r_bin_ne_obj_t {
    r_bin_ne_header_t *ne_header;
    ut8 *entry_table;
    r_buf_t *buf;
    r_bin_ne_segment_entry_t *segment_entries;
    RList *entries;
    size_t header_offset;
    ut32 alignment;
};

#define R_NEW0(x) calloc(1, sizeof(x))

RList *r_list_newf(void (*free)(void *));
void r_list_free(RList *list);
void r_list_append(RList *list, void *data);
void *r_list_get_n(RList *list, int n);
RList *r_bin_ne_get_segments(r_bin_ne_obj_t *bin);
size_t r_buf_size(r_buf_t *buf);