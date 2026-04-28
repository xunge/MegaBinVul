#include <stddef.h>

typedef int spinlock_t;

#define spin_lock(lock) do { (void)(lock); } while (0)
#define spin_unlock(lock) do { (void)(lock); } while (0)

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))((head)->next); &pos->member != (head); pos = (typeof(pos))(pos->member.next))

struct nfc_dev;
struct nfc_llcp_local {
    struct nfc_dev *dev;
    struct list_head list;
};

extern spinlock_t llcp_devices_lock;
extern struct list_head llcp_devices;
extern struct nfc_llcp_local *nfc_llcp_local_get(struct nfc_llcp_local *local);