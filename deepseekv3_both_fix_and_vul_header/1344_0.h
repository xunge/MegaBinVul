#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

typedef struct filedata_s {
    char *fpath;
    char *suffix;
    struct stat sb;
    int action;
    int skip;
    int setmeta;
    int stage;
} filedata_t;

typedef struct diriter_s {
    int dirfd;
} diriter_t;

#define RPMERR_ENOENT (-2)
#define RPMERR_ITER_END (-3)
#define RPMERR_BAD_MAGIC (-4)
#define RPMERR_OPEN_FAILED (-5)
#define RPMERR_UNKNOWN_FILETYPE (-6)

#define RPMTRANS_FLAG_NOFILEDIGEST (1 << 0)
#define RPMTRANS_FLAG_NOCAPS (1 << 1)

#define RPMFILE_GHOST (1 << 0)

#define FA_SKIP 0
#define FA_CREATE 1
#define FA_TOUCH 2

#define XFA_SKIPPING(action) ((action) == FA_SKIP)
#define XFA_CREATING(action) ((action) == FA_CREATE)

#define FILE_NONE 0
#define FILE_PRE 1
#define FILE_UNPACK 2
#define FILE_COMMIT 3

#define IS_DEV_LOG(path) (strcmp(path, "/dev/log") == 0)

#define RPMLOG_DEBUG 1

typedef void *rpmts;
typedef void *rpmte;
typedef void *rpmfiles;
typedef void *rpmpsm;
typedef void *rpmfi;
typedef void *rpmfs;
typedef void *rpmPlugins;
typedef void *FD_t;

#define FDSTAT_READ 0
#define FDSTAT_DIGEST 1

#define RPMTS_OP_UNCOMPRESS 0
#define RPMTS_OP_DIGEST 1

#define RPMCALLBACK_INST_PROGRESS 0

#define RPMFI_ITER_FWD 0
#define RPMFI_ITER_READ_ARCHIVE 1
#define RPMFI_ITER_BACK 2

#define AT_SYMLINK_NOFOLLOW 0x100

static inline void *xcalloc(size_t nmemb, size_t size) {
    return calloc(nmemb, size);
}

static inline char *xstrdup(const char *s) {
    return strdup(s);
}

static inline int rasprintf(char **strp, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int ret = vasprintf(strp, fmt, ap);
    va_end(ap);
    return ret;
}

static inline void fsmDebug(const char *path, int action, struct stat *st) {}
static inline void setFileState(rpmfs fs, int fx) {}
static inline int rpmfiStat(rpmfi fi, int follow, struct stat *st) { return 0; }
static inline char *fsmFsPath(rpmfi fi, char *suffix) { return NULL; }
static inline rpmfi rpmfilesIter(rpmfiles files, int iter) { return NULL; }
static inline int rpmfiNext(rpmfi fi) { return 0; }
static inline int rpmfiFFlags(rpmfi fi) { return 0; }
static inline int rpmfsGetAction(rpmfs fs, int fx) { return 0; }
static inline rpmfi rpmfiFree(rpmfi fi) { return NULL; }
static inline rpmfi fsmIter(FD_t payload, rpmfiles files, int iter, diriter_t *di) { return NULL; }
static inline int rpmfiArchiveHasContent(rpmfi fi) { return 0; }
static inline int fsmBackup(int dirfd, rpmfi fi, int action) { return 0; }
static inline int ensureDir(rpmPlugins plugins, int dn, int create, int recursive, int cleanup, int *dirfd) { return 0; }
static inline int rpmpluginsCallFsmFilePre(rpmPlugins plugins, rpmfi fi, const char *path, mode_t mode, int action) { return 0; }
static inline int fsmStat(int dirfd, const char *path, int follow, struct stat *st) { return 0; }
static inline int fsmVerify(int dirfd, const char *path, rpmfi fi) { return 0; }
static inline int fsmMkfile(int dirfd, rpmfi fi, filedata_t *fp, rpmfiles files, rpmpsm psm, int nodigest, filedata_t **firstlink, int *firstlinkfile, int *fd) { return 0; }
static inline int fsmMkdir(int dirfd, const char *path, mode_t mode) { return 0; }
static inline int fsmSymlink(const char *target, int dirfd, const char *path) { return 0; }
static inline int fsmMkfifo(int dirfd, const char *path, mode_t mode) { return 0; }
static inline int fsmMknod(int dirfd, const char *path, mode_t mode, dev_t dev) { return 0; }
static inline int fsmOpenat(int dirfd, const char *path, int flags) { return 0; }
static inline int fsmSetmeta(int fd, int dirfd, const char *path, rpmfi fi, rpmPlugins plugins, int action, struct stat *st, int nofcaps) { return 0; }
static inline void fsmClose(int *fd) {}
static inline void rpmpsmNotify(rpmpsm psm, int callback, int arg) {}
static inline rpmfi fsmIterFini(rpmfi fi, diriter_t *di) { return NULL; }
static inline int fsmCommit(int dirfd, char **path, rpmfi fi, int action, char *suffix) { return 0; }
static inline int rpmpluginsCallFsmFilePost(rpmPlugins plugins, rpmfi fi, const char *path, mode_t mode, int action, int rc) { return 0; }
static inline int fsmRemove(int dirfd, const char *path, mode_t mode) { return 0; }
static inline void rpmswAdd(int op, int arg) {}
static inline void Fclose(FD_t fd) {}
static inline int rpmtsFlags(rpmts ts) { return 0; }
static inline rpmPlugins rpmtsPlugins(rpmts ts) { return NULL; }
static inline rpmfs rpmteGetFileStates(rpmte te) { return NULL; }
static inline FD_t rpmtePayload(rpmte te) { return NULL; }
static inline int rpmfilesFC(rpmfiles files) { return 0; }
static inline unsigned rpmtsGetTid(rpmts ts) { return 0; }
static inline int rpmtsOp(rpmts ts, int op) { return 0; }
static inline int fdOp(FD_t fd, int stat) { return 0; }
static inline int rpmfiArchiveTell(rpmfi fi) { return 0; }
static inline mode_t rpmfiFMode(rpmfi fi) { return 0; }
static inline const char *rpmfiFLink(rpmfi fi) { return NULL; }
static inline int rpmfiDN(rpmfi fi) { return 0; }
static inline void rpmlog(int level, const char *format, ...) {}