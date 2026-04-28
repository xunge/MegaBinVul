#include <stdint.h>
#include <stddef.h>

typedef uint8_t ut8;
typedef uint32_t ut32;
typedef uint64_t ut64;

#define R_API
#define R_PERM_R 1
#define R_PERM_RELOC 2

typedef struct RIO RIO;

typedef struct RIORelocMap {
    int (*read)(RIO *io, void *map, ut64 addr, ut8 *buf, int len);
} RIORelocMap;

typedef struct RIOMap {
    int perm;
    RIORelocMap *reloc_map;
    int fd;
    ut64 delta;
} RIOMap;

typedef struct RIOSubMap {
    RIOMap mapref;
} RIOSubMap;

typedef struct RRBNode {
    RIOSubMap *data;
} RRBNode;

typedef struct RIOBank {
    void *submaps;
    RRBNode *last_used;
} RIOBank;

#define r_return_val_if_fail(cond, val) if (!(cond)) return (val)
#define R_MIN(a, b) ((a) < (b) ? (a) : (b))

RIOBank *r_io_bank_get(RIO *io, const ut32 bankid);
int r_io_submap_contain(RIOSubMap *sm, ut64 addr);
RRBNode *r_crbtree_find_node(void *tree, const void *key, void *cb, void *user);
int _find_sm_by_vaddr_cb(void *incoming, void *in, void *user);
ut64 r_io_submap_to(RIOSubMap *sm);
RIOMap *r_io_map_get_by_ref(RIO *io, RIOMap *ref);
ut64 r_io_map_from(RIOMap *map);
int r_io_fd_read_at(RIO *io, int fd, ut64 addr, ut8 *buf, int len);