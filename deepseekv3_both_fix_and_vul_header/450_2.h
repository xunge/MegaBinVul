#include <stdbool.h>

struct floppy_struct {
    int sect;
    int head;
    int track;
    int stretch;
    int size;
    const char *name;
};

struct block_device;

struct udp_struct {
    int tracks;
} *UDP;

struct mutex {
    int lock;
} open_lock;

#define FD_STRETCH 0x01
#define FD_SWAPSIDES 0x02
#define FD_SECTBASEMASK 0x3C

#define EINVAL 22
#define EPERM 1
#define EINTR 4
#define CAP_SYS_ADMIN 0

#define FDDEFPRM 1
#define FD_RAW_NEED_DISK 1

#define N_DRIVE 4
#define SUPBOUND(a, b) ((a) = ((a) > (b)) ? (b) : (a))
#define ITYPE(x) ((x) & 0xff)
#define STRETCH(x) ((x)->stretch & FD_STRETCH)

extern struct floppy_struct *floppy_type;
extern int *floppy_sizes;
extern struct block_device *opened_bdev[];
extern struct drive_data {
    int fd_device;
} drive_state[];
extern struct disk_data {
    int keep_data;
    int maxblock;
    int maxtrack;
} *DRS;
extern int buffer_drive;
extern int buffer_max;
extern struct floppy_struct user_params[];
extern struct floppy_struct *current_type[];

int capable(int cap);
int lock_fdc(int drive);
int poll_drive(bool flag, int cmd);
void process_fd_request();
void __invalidate_device(struct block_device *bdev, bool flag);
void invalidate_drive(struct block_device *bdev);

static inline void mutex_lock(struct mutex *lock) { lock->lock = 1; }
static inline void mutex_unlock(struct mutex *lock) { lock->lock = 0; }