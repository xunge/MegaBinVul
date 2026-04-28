#include <stddef.h>

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct list_head {
    struct list_head *next, *prev;
};

struct fs_pin {
    struct list_head wait;
    struct hlist_node s_list;
    struct hlist_node m_list;
    void (*kill)(struct fs_pin *);
};

#define INIT_HLIST_NODE(ptr) ((ptr)->next = NULL, (ptr)->pprev = NULL)
#define init_waitqueue_head(ptr) do { (ptr)->next = (ptr); (ptr)->prev = (ptr); } while (0)