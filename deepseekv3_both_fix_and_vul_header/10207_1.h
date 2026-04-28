#include <stdio.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

struct blkid_struct_tag {
    char *bit_name;
    char *bit_val;
    struct list_head bit_tags;
};

struct blkid_struct_dev {
    char bid_name[256];
    char *bid_type;
    unsigned long bid_devno;
    long bid_time;
    long bid_utime;
    int bid_pri;
    struct list_head bid_tags;
};

typedef struct blkid_struct_dev *blkid_dev;
typedef struct blkid_struct_tag *blkid_tag;

#define DBG(type, args)
#define SAVE 0
#define ul_debug(fmt, ...)