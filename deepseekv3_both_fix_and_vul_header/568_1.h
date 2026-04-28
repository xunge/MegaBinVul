#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

struct list_head {
    struct list_head *next, *prev;
};

struct module;

struct snd_info_entry {
    const char *name;
    struct list_head list;
    struct list_head children;
    struct snd_info_entry *parent;
    struct module *module;
    mode_t mode;
    long content;
    struct {
        int dummy;
    } access;
};

#define GFP_KERNEL 0
#define S_IFREG 0100000
#define SNDRV_INFO_CONTENT_TEXT 0

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

static inline void mutex_init(void *mutex) {
    (void)mutex;
}

static inline void *kzalloc(size_t size, int flags) {
    (void)flags;
    return calloc(1, size);
}

static inline char *kstrdup(const char *s, int flags) {
    (void)flags;
    return strdup(s);
}

static inline void kfree(void *p) {
    free(p);
}