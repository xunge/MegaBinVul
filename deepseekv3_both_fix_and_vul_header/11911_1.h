#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define UTIME_OMIT ((1l << 30) - 2l)
#define EINVAL 22
#define EIO 5

#define P9_STAT_MODE_TYPE_BITS 0xF000

typedef struct V9fsState V9fsState;

typedef struct V9fsStat {
    int16_t type;
    uint32_t dev;
    uint32_t qid;
    uint32_t mode;
    uint32_t atime;
    uint32_t mtime;
    uint64_t length;
    char *extension;
    uint32_t n_uid;
    uint32_t n_gid;
    uint32_t n_muid;
    struct {
        size_t size;
        char *data;
    } name;
} V9fsStat;

typedef struct V9fsFidState {
    char *path;
} V9fsFidState;

typedef struct V9fsPDU {
    int tag;
    int id;
    V9fsState *s;
} V9fsPDU;

#define coroutine_fn

static inline void v9fs_stat_init(V9fsStat *v9stat) {}
static inline void v9fs_stat_free(V9fsStat *v9stat) {}
static inline int pdu_unmarshal(V9fsPDU *pdu, size_t offset, const char *fmt, ...) { return 0; }
static inline V9fsFidState *get_fid(V9fsPDU *pdu, int32_t fid) { return NULL; }
static inline void put_fid(V9fsPDU *pdu, V9fsFidState *fidp) {}
static inline int donttouch_stat(V9fsStat *v9stat) { return 0; }
static inline int v9fs_co_fsync(V9fsPDU *pdu, V9fsFidState *fidp, int flags) { return 0; }
static inline int v9fs_co_lstat(V9fsPDU *pdu, char **path, struct stat *stbuf) { return 0; }
static inline uint32_t stat_to_v9mode(struct stat *stbuf) { return 0; }
static inline uint32_t v9mode_to_mode(uint32_t mode, char **extension) { return 0; }
static inline int v9fs_co_chmod(V9fsPDU *pdu, char **path, uint32_t mode) { return 0; }
static inline int v9fs_co_utimensat(V9fsPDU *pdu, char **path, struct timespec times[2]) { return 0; }
static inline int v9fs_co_chown(V9fsPDU *pdu, char **path, uint32_t uid, uint32_t gid) { return 0; }
static inline int v9fs_complete_rename(V9fsPDU *pdu, V9fsFidState *fidp, int newdirfd, void *name) { return 0; }
static inline int v9fs_co_truncate(V9fsPDU *pdu, char **path, uint64_t length) { return 0; }
static inline void pdu_complete(V9fsPDU *pdu, int err) {}
static inline void v9fs_path_write_lock(V9fsState *s) {}
static inline void v9fs_path_unlock(V9fsState *s) {}
static inline void trace_v9fs_wstat(int tag, int id, int32_t fid, uint32_t mode, uint32_t atime, uint32_t mtime) {}