#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_REQ 128
#define MAX_TAG_LEN 32

typedef struct Error Error;

typedef struct V9fsPath {
    int dummy;
} V9fsPath;

typedef struct V9fsOps {
    int (*init)(void *);
    int (*name_to_path)(void *, void *, const char *, V9fsPath *);
    int (*lstat)(void *, V9fsPath *, struct stat *);
    void (*cleanup)(void *);
} V9fsOps;

typedef struct V9fsState V9fsState;

typedef struct V9fsPdu {
    V9fsState *s;
    int idx;
    struct V9fsPdu *next;
} V9fsPdu;

struct V9fsState {
    struct {
        char *fsdev_id;
        char *tag;
    } fsconf;
    struct {
        int export_flags;
        char *fs_root;
        int uid;
        void *private;
        struct {
            void (*get_st_gen)(void);
        } exops;
    } ctx;
    V9fsOps *ops;
    void *fid_list;
    V9fsPdu *free_list;
    V9fsPdu *active_list;
    char *tag;
    void *rename_lock;
};

typedef struct FsDriverEntry {
    char *path;
    int export_flags;
    V9fsOps *ops;
} FsDriverEntry;

typedef struct V9fsVirtioState {
    V9fsState state;
    V9fsPdu pdus[MAX_REQ];
} V9fsVirtioState;

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define QLIST_INIT(head) do { *(head) = NULL; } while (0)
#define QLIST_INSERT_HEAD(head, elm, field) do { \
    (elm)->field = *(head); \
    *(head) = (elm); \
} while (0)

void error_setg(Error **errp, const char *fmt, ...);
void v9fs_path_init(V9fsPath *path);
void v9fs_path_free(V9fsPath *path);
FsDriverEntry *get_fsdev_fsentry(const char *id);
void g_free(void *ptr);
char *g_strdup(const char *str);
void qemu_co_rwlock_init(void *lock);