#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef int64_t grub_disk_addr_t;
typedef uint64_t grub_off_t;
typedef size_t grub_size_t;
typedef ptrdiff_t grub_ssize_t;

struct grub_disk {
    void (*read_hook)(grub_disk_addr_t sector, unsigned offset, unsigned length, void *closure);
    void *closure;
};
typedef struct grub_disk *grub_disk_t;

struct grub_fshelp_node;
typedef struct grub_fshelp_node *grub_fshelp_node_t;

#define GRUB_DISK_SECTOR_BITS 9
extern int grub_errno;
extern grub_disk_addr_t grub_hack_lastoff;

extern grub_ssize_t grub_disk_read_ex(grub_disk_t disk, grub_disk_addr_t sector,
                                    unsigned offset, unsigned length,
                                    void *buf, int flags);
#define grub_memset memset