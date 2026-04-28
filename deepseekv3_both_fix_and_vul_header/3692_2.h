#include <stdbool.h>
#include <limits.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

struct snd_kcontrol {
    struct list_head list;
    struct {
        unsigned int numid;
    } id;
    unsigned int count;
};

struct snd_card {
    struct list_head controls;
    unsigned int last_numid;
};