#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct file;
struct user_struct;

struct scm_fp_list {
    int count;
    int max;
    struct file **fp;
    struct user_struct *user;
};

#define GFP_KERNEL 0
#define offsetof(TYPE, MEMBER) ((size_t)&((TYPE *)0)->MEMBER)

static void *kmemdup(const void *src, size_t len, int gfp) {
    void *p = malloc(len);
    if (p) memcpy(p, src, len);
    return p;
}

static void get_file(struct file *f) {}
static struct user_struct *get_uid(struct user_struct *u) { return u; }