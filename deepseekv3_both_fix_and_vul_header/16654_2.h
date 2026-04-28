#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <errno.h>

#define FD_DISK_CHANGED_BIT 0
#define FD_VERIFY_BIT 1
#define FD_RAW_NEED_DISK 0

struct gendisk {
    void *private_data;
};

struct ud_struct {
    unsigned long flags;
    int maxblock;
    int maxtrack;
    int fd_device;
    int generation;
};
extern struct ud_struct *UDRS;
extern unsigned long fake_change;
extern atomic_int usage_count;
extern int buffer_drive;
extern int buffer_track;
extern int *floppy_sizes;
extern void *opened_bdev[];

static inline int atomic_read(const atomic_int *v) {
    return atomic_load_explicit(v, memory_order_relaxed);
}

int lock_fdc(int drive, ...);
int drive_no_geom(int drive);
int __floppy_read_block_0(void *bdev, int drive);
void poll_drive(bool interruptible, int flag);
void process_fd_request();
void set_capacity(struct gendisk *disk, int size);
int test_bit(int nr, const volatile unsigned long *addr);
void clear_bit(int nr, volatile unsigned long *addr);
int WARN(int condition, const char *fmt, ...);