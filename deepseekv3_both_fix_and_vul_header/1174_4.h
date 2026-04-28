#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int ut32;
typedef unsigned long long ut64;

typedef struct RIO RIO;
typedef struct RIOMap RIOMap;
typedef struct RIOMapRef RIOMapRef;
typedef struct RIOBank RIOBank;
typedef struct RIOSubMap RIOSubMap;
typedef struct RRBNode RRBNode;
typedef struct RContRBTree RContRBTree;

struct RContRBTree {
    void *free;
};

struct RIOBank {
    RContRBTree *submaps;
    void *maprefs;
    void *last_used;
};

struct RIOSubMap {
    ut64 from;
    ut64 to;
};

struct RRBNode {
    void *data;
    RRBNode *next;
};

#define R_API
#define r_return_val_if_fail(cond, val) if (!(cond)) return (val)
#define R_NEWCOPY(type, obj) malloc(sizeof(type)); memcpy(bdsm, bd, sizeof(type))

typedef bool (*find_sm_cb)(void *a, void *b);
static find_sm_cb _find_sm_by_from_vaddr_cb;

RIOBank *r_io_bank_get(RIO *io, ut32 bankid);
RIOMap *r_io_map_get(RIO *io, ut32 mapid);
RIOMapRef *_mapref_from_map(RIOMap *map);
RIOSubMap *r_io_submap_new(RIO *io, RIOMapRef *mapref);
RRBNode *_find_entry_submap_node(RIOBank *bank, RIOSubMap *sm);
bool r_crbtree_insert(RContRBTree *tree, void *data, find_sm_cb cb, void *user);
void r_list_append(void *list, void *data);
ut64 r_io_submap_to(RIOSubMap *sm);
ut64 r_io_submap_from(RIOSubMap *sm);
void r_io_submap_set_from(RIOSubMap *sm, ut64 from);
void r_io_submap_set_to(RIOSubMap *sm, ut64 to);
RRBNode *r_rbnode_next(RRBNode *node);
bool r_crbtree_delete(RContRBTree *tree, void *data, find_sm_cb cb, void *user);