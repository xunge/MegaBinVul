#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = ({ typeof(*(pos)) *__ptr = (head)->next; \
                  __ptr != (head) ? container_of(__ptr, typeof(*(pos)), member) : NULL; }); \
         pos != NULL; \
         pos = ({ typeof(*(pos)) *__ptr = pos->member.next; \
                  __ptr != (head) ? container_of(__ptr, typeof(*(pos)), member) : NULL; }))

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = ({ typeof(*(pos)) *__ptr = (head)->next; \
                  __ptr != (head) ? container_of(__ptr, typeof(*(pos)), member) : NULL; }), \
         n = pos ? ({ typeof(*(pos)) *__ptr = pos->member.next; \
                     __ptr != (head) ? container_of(__ptr, typeof(*(pos)), member) : NULL; }) : NULL; \
         pos != NULL; \
         pos = n, \
         n = pos ? ({ typeof(*(pos)) *__ptr = pos->member.next; \
                     __ptr != (head) ? container_of(__ptr, typeof(*(pos)), member) : NULL; }) : NULL)

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

struct domain {
    int domid;
    bool shutdown;
    void *conn;
    struct list_head list;
};

typedef struct {
    int domid;
    bool crashed;
    bool shutdown;
    bool dying;
} xc_dominfo_t;

extern int *xc_handle;
extern struct list_head domains;
extern void *talloc_autofree_context();
extern void talloc_unlink(void *ctx, void *ptr);
extern void talloc_free(void *ptr);
extern void fire_watches(void *a, void *b, const char *c, bool d);