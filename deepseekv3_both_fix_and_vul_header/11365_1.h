#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct rpmts_s *rpmts;
typedef struct rpmte_s *rpmte;
typedef struct rpmfiles_s *rpmfiles;
typedef struct rpmpsm_s *rpmpsm;
typedef struct rpmfi_s *rpmfi;
typedef struct rpmfs_s *rpmfs;
typedef struct rpmPlugins_s *rpmPlugins;
typedef struct FD_s *FD_t;

#define RPMERR_BAD_MAGIC 1
#define RPMERR_ITER_END 2
#define RPMERR_ENOENT 3
#define RPMERR_UNKNOWN_FILETYPE 4

#define RPMTRANS_FLAG_NOFILEDIGEST (1 << 0)
#define RPMTRANS_FLAG_NOCAPS (1 << 1)

#define RPMFI_ITER_READ_ARCHIVE 0
#define RPMTS_OP_UNCOMPRESS 0
#define RPMTS_OP_DIGEST 1
#define FDSTAT_READ 0
#define FDSTAT_DIGEST 1

#define RPMCALLBACK_INST_PROGRESS 0

#define XFA_SKIPPING(action) ((action) == FA_SKIP)

enum rpmFileAction_e {
    FA_TOUCH,
    FA_SKIP,
    FA_CREATE,
    FA_BACKUP,
    FA_SAVE,
    FA_SKIPNSTATE,
    FA_SKIPNETSHARED,
    FA_SKIPCOLOR
};
typedef enum rpmFileAction_e rpmFileAction;

#define IS_DEV_LOG(path) (strcmp(path, "/dev/log") == 0)

static inline void * _free(void *p) { free(p); return NULL; }
static inline char * xstrdup(const char *s) { return strdup(s); }