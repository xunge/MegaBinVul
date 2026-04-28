#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stddef.h>

#define MAX_REQ 32
#define MAX_TAG_LEN 32

typedef struct Error Error;

typedef struct V9fsPath {
    // Placeholder for V9fsPath structure
    // Actual implementation may contain fields
} V9fsPath;

typedef struct FsDriverEntry {
    int export_flags;
    char *path;
    struct {
        int (*init)(void *);
        int (*name_to_path)(void *, void *, const char *, V9fsPath *);
        int (*lstat)(void *, V9fsPath *, struct stat *);
    } *ops;
} FsDriverEntry;

typedef struct V9fsState {
    struct {
        char *fsdev_id;
        char *tag;
    } fsconf;
    struct {
        int export_flags;
        char *fs_root;
        struct {
            void *get_st_gen;
        } exops;
        int uid;
    } ctx;
    char *tag;
    struct {
        int (*init)(void *);
        int (*name_to_path)(void *, void *, const char *, V9fsPath *);
        int (*lstat)(void *, V9fsPath *, struct stat *);
    } *ops;
    void *fid_list;
    void *free_list;
    void *active_list;
    void *rename_lock;
} V9fsState;

typedef struct V9fsVirtioState {
    V9fsState state;
    struct {
        V9fsState *s;
        int idx;
        void *next;
    } pdus[MAX_REQ];
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
void qemu_co_rwlock_init(void *lock);
char *g_strdup(const char *str);
void g_free(void *ptr);