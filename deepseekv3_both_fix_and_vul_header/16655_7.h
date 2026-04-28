#include <stdbool.h>
#include <stddef.h>

#define FD_DISK_CHANGED_BIT 0
#define FD_VERIFY_BIT 1
#define DISK_EVENT_MEDIA_CHANGE 1
#define EINTR 4

struct gendisk {
    void *private_data;
};

struct ud_struct {
    unsigned long flags;
    unsigned long last_checked;
};

struct udp_struct {
    unsigned long checkfreq;
};

extern struct ud_struct *UDRS;
extern struct udp_struct *UDP;
extern unsigned long fake_change;
extern unsigned long jiffies;

int test_bit(int nr, const volatile unsigned long *addr);
int time_after(unsigned long a, unsigned long b);
int lock_fdc(int drive, ...);
void poll_drive(bool flag, int arg);
void process_fd_request();
int drive_no_geom(int drive);