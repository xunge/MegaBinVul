#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef uint32_t ut32;
typedef uint64_t ut64;
typedef uint8_t ut8;

#define R_API
#define R_LIKELY(x) (x)
#define R_PERM_R 1
#define R_PERM_RELOC 2
#define R_MAX(a, b) ((a) > (b) ? (a) : (b))
#define R_MIN(a, b) ((a) < (b) ? (a) : (b))
#define r_return_val_if_fail(cond, val) if (!(cond)) return (val)

typedef struct r_io_t {
    int Oxff;
} RIO;

typedef struct r_rbnode_t RRBNode;

typedef struct {
    ut64 addr;
    ut64 size;
} RInterval;

typedef struct {
    void* data;
} RMapRef;

typedef struct r_io_map_t {
    int perm;
    int fd;
    ut64 delta;
    struct r_io_map_t* reloc_map;
    int (*read)(RIO*, struct r_io_map_t*, ut64, ut8*, int);
} RIOMap;

typedef struct r_io_submap_t {
    RInterval itv;
    RMapRef mapref;
} RIOSubMap;

typedef struct r_io_bank_t {
    RRBNode* last_used;
} RIOBank;

typedef struct r_rbnode_t {
    void* data;
    struct r_rbnode_t* next;
} RRBNode;

RIOBank* r_io_bank_get(RIO* io, ut32 bankid);
bool r_io_submap_contain(RIOSubMap* sm, ut64 addr);
RRBNode* _find_entry_submap_node(RIOBank* bank, RIOSubMap* sm);
bool r_io_submap_overlap(RIOSubMap* a, RIOSubMap* b);
RIOMap* r_io_map_get_by_ref(RIO* io, RMapRef* ref);
RRBNode* r_rbnode_next(RRBNode* node);
ut64 r_io_submap_from(RIOSubMap* sm);
ut64 r_io_submap_to(RIOSubMap* sm);
ut64 r_io_map_from(RIOMap* map);
int r_io_fd_read_at(RIO* io, int fd, ut64 addr, ut8* buf, int len);