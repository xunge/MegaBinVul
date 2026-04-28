#include <sys/stat.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAGIC_SETS 2
#define MAXPATHLEN 4096
#define FILE_CHECK 1
#define REPORT_ERRORS 0
#define MAGIC_CHECK 0x00000001

struct magic_set {
    int flags;
};

struct magic_map {
    void *magic[MAGIC_SETS];
    size_t nmagic[MAGIC_SETS];
};

struct magic_entry_set {
    struct magic_entry *me;
    size_t count;
};

struct magic_entry {
    struct magic *mp;
};

struct magic {
    int cont_level;
};

typedef struct _php_stream_dirent {
    char d_name[256];
} php_stream_dirent;

typedef struct _php_stream php_stream;

#define TSRMLS_FETCH()
#define CAST(type, ptr) ((type)(ptr))
#define ecalloc(n, size) calloc(n, size)
#define erealloc(ptr, size) realloc(ptr, size)
#define efree(ptr) free(ptr)
#define estrndup(str, len) strndup(str, len)
#define php_stream_opendir(path, flags, ctx) NULL
#define php_stream_readdir(stream, entry) 0
#define php_stream_closedir(stream)
#define php_sys_stat(path, buf) stat(path, buf)

static const char *usg_hdr = "";
static void file_oomem(struct magic_set *ms, size_t size) {}
static int load_1(struct magic_set *ms, int action, const char *fn, int *errs, struct magic_entry_set *mset) { return 0; }
static int cmpstrp(const void *a, const void *b) { return 0; }
static int set_text_binary(struct magic_set *ms, struct magic_entry *me, size_t count, size_t i) { return 0; }
static int apprentice_sort(const void *a, const void *b) { return 0; }
static void set_last_default(struct magic_set *ms, struct magic_entry *me, size_t count) {}
static int coalesce_entries(struct magic_set *ms, struct magic_entry *me, size_t count, void **magic, size_t *nmagic) { return 0; }
static void magic_entry_free(struct magic_entry *me, size_t count) {}

typedef struct magic_map magic_map;