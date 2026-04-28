#include <stddef.h>

#define RB_ROOT_CACHED (struct rb_root_cached){ NULL, NULL }
#define RB_ROOT (struct rb_root){ NULL }

struct rb_root {
    void *rb_node;
};

struct rb_root_cached {
    void *rb_root;
    void *rb_leftmost;
};

struct timerqueue_node;

struct timerqueue_head {
    union {
        struct rb_root_cached rb_root;
        struct {
            struct rb_root head;
            struct timerqueue_node *next;
        };
    };
};