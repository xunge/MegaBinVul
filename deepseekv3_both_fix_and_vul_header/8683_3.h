#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define P9_MAXWELEM 16
#define P9_FID_NONE 0

typedef struct V9fsString {
    char *data;
} V9fsString;

typedef struct V9fsQID {
    uint8_t type;
    uint32_t version;
    uint64_t path;
} V9fsQID;

typedef struct V9fsPath {
    char *data;
} V9fsPath;

typedef struct V9fsFidState {
    int fid_type;
    V9fsPath path;
    int uid;
    int32_t fid;
} V9fsFidState;

typedef struct V9fsPDU {
    uint16_t tag;
    uint16_t id;
    struct V9fsState *s;
} V9fsPDU;

typedef struct V9fsState {
    V9fsQID root_qid;
} V9fsState;

static inline void *g_malloc0(size_t size) { return calloc(1, size); }
static inline void g_free(void *ptr) { free(ptr); }

static inline void v9fs_path_init(V9fsPath *path) {}
static inline void v9fs_path_copy(V9fsPath *dst, V9fsPath *src) {}
static inline void v9fs_path_free(V9fsPath *path) {}
static inline void v9fs_string_free(V9fsString *str) {}

static inline int pdu_unmarshal(V9fsPDU *pdu, size_t offset, const char *fmt, ...) { return 0; }
static inline void pdu_complete(V9fsPDU *pdu, int err) {}
static inline V9fsFidState *get_fid(V9fsPDU *pdu, int32_t fid) { return NULL; }
static inline void put_fid(V9fsPDU *pdu, V9fsFidState *fidp) {}
static inline V9fsFidState *alloc_fid(V9fsState *s, int32_t fid) { return NULL; }
static inline int fid_to_qid(V9fsPDU *pdu, V9fsFidState *fidp, V9fsQID *qid) { return 0; }
static inline int v9fs_co_name_to_path(V9fsPDU *pdu, V9fsPath *dpath, const char *name, V9fsPath *path) { return 0; }
static inline int v9fs_co_lstat(V9fsPDU *pdu, V9fsPath *path, struct stat *stbuf) { return 0; }
static inline void stat_to_qid(struct stat *stbuf, V9fsQID *qid) {}
static inline int v9fs_walk_marshal(V9fsPDU *pdu, uint16_t nwnames, V9fsQID *qids) { return 0; }
static inline int not_same_qid(V9fsQID *qid1, V9fsQID *qid2) { return 0; }
static inline int name_is_illegal(const char *name) { return 0; }
static inline void trace_v9fs_walk(uint16_t tag, uint16_t id, int32_t fid, int32_t newfid, uint16_t nwnames) {}
static inline void trace_v9fs_walk_return(uint16_t tag, uint16_t id, uint16_t nwnames, V9fsQID *qids) {}

#define BUG_ON(cond) do { if (cond) abort(); } while (0)