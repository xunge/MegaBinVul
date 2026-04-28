#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

typedef uint64_t ut64;
typedef uint8_t ut8;

typedef struct RList RList;
typedef struct RListIter RListIter;
typedef struct RFSFile RFSFile;
typedef struct RFSRoot RFSRoot;
typedef struct RFSPlugin RFSPlugin;
typedef struct RFSPartition RFSPartition;
typedef struct RCore RCore;
typedef struct PJ PJ;
typedef struct RIODesc RIODesc;
typedef struct RLine RLine;
typedef struct RLineCompletion RLineCompletion;
typedef struct RFSShell RFSShell;

struct RList {
    void *head;
    void *tail;
};

struct RListIter {
    void *data;
    RListIter *n;
    RListIter *p;
};

#define r_list_foreach(list, it, ptr) \
    for ((it) = (list)->head; (it) && ((ptr) = (it)->data, 1); (it) = (it)->n)

struct RFSFile {
    ut64 size;
    ut64 off;
    ut8 *data;
};

struct RFSRoot {
    char *path;
    RFSPlugin *p;
    ut64 delta;
};

struct RFSPlugin {
    char *name;
    char *desc;
};

struct RFSPartition {
    int number;
    int type;
    ut64 start;
    ut64 length;
};

struct RCore {
    struct {
        RList *roots;
        RList *plugins;
    } *fs;
    void *num;
    void *io;
    ut64 offset;
    bool http_up;
};

struct PJ {
    // Minimal PJ structure
};

struct RIODesc {
    // Minimal RIODesc structure
};

struct RLineCompletion {
    void *args;
    void (*run)(void *, const char *, const char *);
    void *run_user;
};

struct RLine {
    RLineCompletion completion;
    void *user;
};

struct RFSShell {
    char **cwd;
    void (*set_prompt)(const char *);
    char *(*readline)(void);
    void (*hist_add)(const char *);
};

#define PFMT64x "llx"
#define R_PERM_RW 6

static char *cwd = NULL;
static int ms_argc = 0;
static char **ms_argv = NULL;
static const char *help_msg_m = "";

static void eprintf(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
}

static void r_line_set_prompt(const char *prompt) {}
static char *r_line_readline(void) { return NULL; }
static void r_line_hist_add(const char *line) {}

static void ms_autocomplete(void *a, const char *b, const char *c) {}
static int cmd_mkdir(void *data, const char *input) { return 0; }
static int cmd_mv(void *data, const char *input) { return 0; }
static int cmd_mount_ls(RCore *core, const char *input) { return 0; }
static void r_core_cmd_help(RCore *core, const char *msg) {}

static char *r_str_trim_ro(const char *s) { return strdup(s); }
static ut64 r_num_math(void *num, const char *str) { return 0; }
static int r_fs_mount(void *fs, const char *a, const char *b, ut64 off) { return 0; }
static char *r_fs_name(void *fs, ut64 off) { return NULL; }
static void r_fs_umount(void *fs, const char *path) {}
static PJ *pj_new(void) { return NULL; }
static void pj_o(PJ *pj) {}
static void pj_k(PJ *pj, const char *k) {}
static void pj_a(PJ *pj) {}
static void pj_ks(PJ *pj, const char *k, const char *v) {}
static void pj_kn(PJ *pj, const char *k, ut64 v) {}
static void pj_end(PJ *pj) {}
static char *pj_string(PJ *pj) { return NULL; }
static void pj_free(PJ *pj) {}
static void r_cons_printf(const char *fmt, ...) {}
static RList *r_fs_partitions(void *fs, const char *input, ut64 off) { return NULL; }
static RFSFile *r_fs_open(void *fs, const char *path, bool write) { return NULL; }
static void r_fs_read(void *fs, RFSFile *file, ut64 off, ut64 size) {}
static char *r_str_newf(const char *fmt, ...) { return NULL; }
static RIODesc *r_io_open(void *io, const char *uri, int perm, int mode) { return NULL; }
static int r_io_desc_write(RIODesc *fd, const ut8 *buf, int len) { return 0; }
static void r_fs_close(void *fs, RFSFile *file) {}
static void r_cons_memcat(const char *data, int len) {}
static int r_fs_dir_dump(void *fs, const char *path, const char *dest) { return 0; }
static char *r_str_rchr(const char *str, const char *end, int ch) { return NULL; }
static int r_file_dump(const char *file, const ut8 *buf, int len, bool append) { return 0; }
static RList *r_fs_find_name(void *fs, const char *path, const char *name) { return NULL; }
static RList *r_fs_find_off(void *fs, const char *path, ut64 off) { return NULL; }
static void r_cons_set_raw(bool b) {}
static RLine *r_line_singleton(void) { return NULL; }
static void r_pvector_init(void *vec, void (*free)(void*)) {}
static void r_line_completion_set(RLineCompletion *c, int argc, char **argv) {}
static void r_fs_shell_prompt(RFSShell *shell, void *fs, const char *input) {}
static void r_pvector_clear(void *vec) {}
static char *r_str_trim_dup(const char *s) { return strdup(s); }
static int r_fs_write(void *fs, RFSFile *f, ut64 off, const ut8 *buf, int len) { return 0; }
static void r_fs_file_free(RFSFile *f) {}
static void r_str_trim_path(char *s) {}