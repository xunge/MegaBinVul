#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

struct archive_rb_node;

struct archive_rb_tree_ops {
    int (*cmp_node)(const struct archive_rb_node *, const struct archive_rb_node *);
    int (*cmp_key)(const struct archive_rb_node *, const void *);
};

struct archive_string {
    char *s;
    size_t length;
    size_t buffer_length;
};

struct archive_entry {
    const char *pathname;
};

struct file_info {
    struct archive_string basename;
    struct archive_string basename_utf16;
    struct archive_entry *entry;
};

struct isoent {
    struct isoent *parent;
    struct isoent *chnext;
    struct file_info *file;
    char *identifier;
    int ext_off;
    int ext_len;
    int id_len;
    int mb_len;
    struct {
        struct isoent *first;
        int cnt;
    } children;
};

struct archive {
    int dummy;
};

struct archive_write {
    struct archive archive;
    void *format_data;
};

struct iso9660 {
    struct archive_string mbs;
    void *sconv_from_utf16be;
    struct {
        int joliet;
    } opt;
};

struct idr {
    int dummy;
};

#define ARCHIVE_OK 0
#define ARCHIVE_FATAL -1
#define ARCHIVE_ERRNO_MISC (-1)
#define OPT_JOLIET_LONGNAME 1

static int isoent_cmp_node_joliet(const struct archive_rb_node *a,
    const struct archive_rb_node *b) { return 0; }

static int isoent_cmp_key_joliet(const struct archive_rb_node *a,
    const void *key) { return 0; }

static int joliet_allowed_char(unsigned char c1, unsigned char c2) { return 1; }

static void archive_be16enc(unsigned char *p, uint16_t v) {
    p[0] = (v >> 8) & 0xff;
    p[1] = v & 0xff;
}

static int archive_strncpy_l(struct archive_string *as, const char *s,
    size_t n, void *sc) { return 0; }

static void archive_set_error(struct archive *a, int e, const char *fmt, ...) {}

static int idr_start(struct archive_write *a, struct idr *idr, int cnt,
    int ffmax, int a1, int a2, const struct archive_rb_tree_ops *ops) { return 0; }

static void idr_register(struct idr *idr, struct isoent *np, int w, int n) {}

static void idr_resolve(struct idr *idr,
    void (*func)(struct idr *, struct isoent *)) {}

static void idr_set_num_beutf16(struct idr *idr, struct isoent *np) {}