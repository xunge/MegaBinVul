#include <stdlib.h>
#include <string.h>

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {
    int dummy;
};

struct snd_info_entry {
    struct list_head list;
    struct list_head children;
    struct snd_info_entry *parent;
    struct snd_info_entry *p;
    struct mutex access;
    char *name;
    void (*private_free)(struct snd_info_entry *);
};

extern struct mutex info_mutex;
extern void mutex_lock(struct mutex *);
extern void mutex_unlock(struct mutex *);
extern void snd_info_disconnect(struct snd_info_entry *);
extern void kfree(void *);
extern void list_del(struct list_head *);
#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; pos != (head); pos = n)