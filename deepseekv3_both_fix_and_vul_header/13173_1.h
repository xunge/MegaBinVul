#include <stdbool.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct tls_rec {
    bool tx_ready;
    struct list_head list;
};

struct tls_sw_context_tx {
    struct list_head tx_list;
};

#define container_of(ptr, type, member) ({ \
    const typeof( ((type *)0)->member ) *__mptr = (ptr); \
    (type *)( (char *)__mptr - offsetof(type, member) );})

#define list_first_entry(ptr, type, member) \
    container_of((ptr)->next, type, member)

#define list_first_entry_or_null(ptr, type, member) ({ \
    struct list_head *head__ = (ptr); \
    struct list_head *pos__ = head__->next; \
    pos__ != head__ ? list_first_entry(pos__, type, member) : NULL; })

#define READ_ONCE(x) (x)