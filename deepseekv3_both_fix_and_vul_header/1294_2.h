#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <getopt.h>
#include <limits.h>
#include <stdint.h>
#include <libintl.h>

#define MNT_ITER_FORWARD 0
#define MNT_ITER_BACKWARD 1
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define PACKAGE ""
#define LOCALEDIR ""
#define _PATH_PROC_MOUNTINFO "/proc/self/mountinfo"
#define MNT_UNIQ_KEEPTREE 1

enum {
    FL_TREE = 1 << 0,
    FL_ALL = 1 << 1,
    FL_ASCII = 1 << 2,
    FL_BYTES = 1 << 3,
    FL_NOCACHE = 1 << 4,
    FL_CANONICALIZE = 1 << 5,
    FL_DF = 1 << 6,
    FL_EVALUATE = 1 << 7,
    FL_INVERT = 1 << 8,
    FL_JSON = 1 << 9,
    FL_FIRSTONLY = 1 << 10,
    FL_EXPORT = 1 << 11,
    FL_RAW = 1 << 12,
    FL_NOHEADINGS = 1 << 13,
    FL_NOFSROOT = 1 << 14,
    FL_SUBMOUNTS = 1 << 15,
    FL_STRICTTARGET = 1 << 16,
    FL_UNIQ = 1 << 17,
    FL_VERBOSE = 1 << 18,
    FL_PSEUDO = 1 << 19,
    FL_REAL = 1 << 20,
    FL_VFS_ALL = 1 << 21,
    FL_SHADOWED = 1 << 22,
    FL_DELETED = 1 << 23,
    FL_NOSWAPMATCH = 1 << 24,
    FL_POLL = 1 << 25
};

enum {
    COL_TARGET,
    COL_SOURCE,
    COL_FSTYPE,
    COL_OPTIONS,
    COL_MAJMIN,
    COL_SIZE,
    COL_USED,
    COL_AVAIL,
    COL_USEPERC,
    COL_ACTION,
    COL_ID,
    COL_PARENT,
    COL_FREQ,
    COL_PASSNO,
    COL_TID,
    COL_DELETED
};

enum {
    TABTYPE_MTAB,
    TABTYPE_FSTAB,
    TABTYPE_KERNEL
};

enum {
    SCOLS_FL_TREE = 1 << 0,
    SCOLS_FL_WRAP = 1 << 1,
    SCOLS_JSON_NUMBER,
    SCOLS_JSON_BOOLEAN,
    SCOLS_JSON_STRING,
    SCOLS_JSON_ARRAY_STRING
};

struct libmnt_table;
struct libmnt_cache;
struct libmnt_fs;
struct libscols_table;
struct libscols_column;
struct libscols_line;
struct option;

typedef struct {
    int dummy;
} ul_excl_t;

#define UL_EXCL_STATUS_INIT {0}

static struct libmnt_cache *cache = NULL;
static unsigned int flags = 0;
static int ncolumns = 0;
static int columns[32];
static int nactions = 0;
static int actions[32];
static struct {
    int dummy;
} infos[32];

static inline const char *_(const char *s) { return s; }

static inline int poll_action_name_to_id(const char *name) { return 0; }
static inline int column_name_to_id(const char *name) { return 0; }
static inline int uniq_fs_target_cmp(struct libmnt_fs *a, struct libmnt_fs *b) { return 0; }
static inline size_t scols_wrapnl_chunksize(struct libscols_line *ln, const char *data, void *userdata) { return 0; }
static inline char *scols_wrapnl_nextchunk(struct libscols_line *ln, const char *data, void *userdata) { return NULL; }