#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>

#define AUGEAS_FILES_TREE ""
#define AUGEAS_COPY_IF_RENAME_FAILS ""
#define EXT_AUGNEW ""
#define EXT_AUGSAVE ""
#define AUG_SAVE_NEWFILE 0
#define AUG_SAVE_NOOP 0
#define AUG_SAVE_BACKUP 0
#define STREQ(a, b) (strcmp((a), (b)) == 0)

struct augeas {
    char *root;
    int flags;
};

struct tree {
    struct tree *children;
};

struct lns_error {
    int pos;
};

struct lens {
    // lens definition
};

static int xasprintf(char **strp, const char *fmt, ...) { return -1; }
static char *strappend(const char *s1, const char *s2) { return NULL; }
static char *xfread_file(FILE *fp) { return NULL; }
static char *xread_file(const char *path) { return NULL; }
static char *append_newline(char *text, size_t len) { return NULL; }
static int transfer_file_attrs(FILE *src, FILE *dst, const char **err) { return 0; }
static int clone_file(const char *src, const char *dst, const char **err, int flag1, int flag2) { return 0; }
static int add_file_info(struct augeas *aug, const char *path, struct lens *lens, const char *lens_name, char *augorig, bool force_reload) { return 0; }
static int file_saved_event(struct augeas *aug, const char *path) { return 0; }
static void store_error(struct augeas *aug, const char *filename, const char *path, const char *emsg, int errno_val, struct lns_error *err, char *text) {}
static void lens_release(struct lens *lens) {}
static void free_lns_error(struct lns_error *err) {}
static struct lens *xfm_lens(struct augeas *aug, struct tree *xfm, const char **lens_name) { return NULL; }
static int lns_put(FILE *fp, struct lens *lens, struct tree *tree, char *text, struct lns_error **err) { return 0; }
static int aug_get(struct augeas *aug, const char *path, void *value) { return 0; }
#define FREE(ptr) free(ptr)