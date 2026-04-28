#include <stdlib.h>
#include <stdint.h>

typedef uint8_t ut8;
typedef uint16_t ut16;
typedef uint64_t ut64;

typedef struct RList RList;
typedef struct RBinAddr RBinAddr;
typedef struct RBinSection RBinSection;
typedef struct r_bin_ne_obj_t r_bin_ne_obj_t;

struct RBinAddr {
    ut64 paddr;
    int bits;
};

struct RBinSection {
    ut64 paddr;
};

struct r_bin_ne_obj_t {
    struct {
        ut16 csEntryPoint;
        ut16 ipEntryPoint;
        ut16 EntryTableLength;
    } *ne_header;
    ut8 *entry_table;
    void *buf;
    int alignment;
    struct {
        ut16 offset;
    } *segment_entries;
    RList *entries;
};

struct RList {
    void *free;
};

#define R_NEW0(x) calloc(1, sizeof(x))
#define r_list_newf(x) ((RList*)calloc(1, sizeof(RList)))
#define r_list_free(x) free(x)
#define r_list_append(x,y) 
#define r_list_get_n(x,y) ((RBinSection*)NULL)
#define r_buf_size(x) 0
#define r_bin_ne_get_segments(x) ((RList*)NULL)