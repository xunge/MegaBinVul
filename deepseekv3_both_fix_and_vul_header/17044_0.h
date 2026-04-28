#include <string.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

typedef struct {
    int raw_lock;
} spinlock_t;

#define spin_lock_init(lock) ((void)(lock))

struct asd_sas_port {
    int id;
    struct list_head dev_list;
    struct list_head disco_list;
    struct list_head destroy_list;
    spinlock_t phy_list_lock;
    struct list_head phy_list;
    struct sas_ha_struct *ha;
    spinlock_t dev_list_lock;
    struct list_head sas_port_del_list;
};

struct sas_ha_struct {
};