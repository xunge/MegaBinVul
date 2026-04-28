#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned long long ut64;
typedef unsigned char ut8;

typedef struct RBin RBin;
struct RBin {
    int verbose;
};

typedef struct RBinFile RBinFile;
struct RBinFile {
    RBin *rbin;
};

typedef struct RListIter RListIter;
struct RListIter {
    void *data;
    RListIter *next;
    RListIter *prev;
};

typedef struct RDyldBinImage RDyldBinImage;
struct RDyldBinImage {
    ut64 header_at;
    ut64 hdr_offset;
};

typedef struct RDyldCache RDyldCache;
struct RDyldCache {
    void *buf;
    RListIter *bins;
    int n_hdr;
};

typedef struct section_t section_t;
struct section_t {
    char *name;
    ut64 size;
    ut64 offset;
    ut64 addr;
    bool last;
};

#define MACH0_(name) name
typedef struct MACH0_(opts_t) MACH0_(opts_t);
struct MACH0_(opts_t) {
    int verbose;
    ut64 header_at;
    ut64 symbols_off;
};

typedef struct MACH0_(obj_t) MACH0_(obj_t);
struct MACH0_(obj_t) {
    // dummy definition
};

#define R_MIN(x, y) ((x) < (y) ? (x) : (y))
#define R_FREE(x) { free(x); x = NULL; }

#define r_list_foreach(list, it, pos) \
    for ((it) = (list); (it) && ((pos) = (RDyldBinImage*)(it)->data); (it) = (it)->next)

struct MACH0_(obj_t) *MACH0_(new_buf)(void *buf, struct MACH0_(opts_t) *opts);
struct section_t *MACH0_(get_sections)(struct MACH0_(obj_t) *mach0);
void MACH0_(mach0_free)(struct MACH0_(obj_t) *mach0);

int r_buf_fread_at(void *buf, ut64 offset, ut8 *dst, const char *fmt, int n);