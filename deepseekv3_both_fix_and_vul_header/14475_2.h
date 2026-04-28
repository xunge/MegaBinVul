#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int ut32;

typedef struct r_io_t RIO;
typedef struct r_io_bank_t {
    void *submaps;
    void *maprefs;
    void *last_used;
} RIOBank;
typedef struct r_io_map_t RIOMap;
typedef struct r_io_map_ref_t RIOMapRef;
typedef struct r_io_submap_t {
    ut32 from;
    ut32 to;
} RIOSubMap;
typedef struct r_rbnode_t {
    void *data;
    struct r_rbnode_t *next;
} RRBNode;
typedef struct r_list_t RList;

#define R_API
#define r_return_val_if_fail(cond, val) if (!(cond)) return (val)
#define R_NEWCOPY(type, obj) ((type *)malloc(sizeof(type)))

typedef bool (*FindSmByFromVaddrCb)(void *, void *);
static FindSmByFromVaddrCb _find_sm_by_from_vaddr_cb;

RIOBank *r_io_bank_get(RIO *io, ut32 bankid);
RIOMap *r_io_map_get(RIO *io, ut32 mapid);
RIOMapRef *_mapref_from_map(RIOMap *map);
RIOSubMap *r_io_submap_new(RIO *io, RIOMapRef *mapref);
RRBNode *_find_entry_submap_node(RIOBank *bank, RIOSubMap *sm);
bool r_crbtree_insert(void *tree, void *data, FindSmByFromVaddrCb cb, void *user);
void r_list_append(void *list, void *data);
ut32 r_io_submap_to(RIOSubMap *sm);
ut32 r_io_submap_from(RIOSubMap *sm);
void r_io_submap_set_from(RIOSubMap *sm, ut32 from);
void r_io_submap_set_to(RIOSubMap *sm, ut32 to);
RRBNode *r_rbnode_next(RRBNode *node);
bool r_crbtree_delete(void *tree, void *data, FindSmByFromVaddrCb cb, void *user);