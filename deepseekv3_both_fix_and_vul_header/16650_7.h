#include <stdbool.h>

#define FD_STRETCH 0x01
#define FD_SWAPSIDES 0x02
#define FD_SECTBASEMASK 0xFC
#define FD_RAW_NEED_DISK 0x80
#define FDDEFPRM 0
#define N_DRIVE 4
#define EINVAL 22
#define EPERM 1
#define EINTR 4
#define CAP_SYS_ADMIN 0

struct floppy_struct {
    int sect;
    int head;
    int track;
    int stretch;
    int size;
    char *name;
    int tracks;
    int keep_data;
    int maxblock;
    int maxtrack;
};

struct block_device;
struct mutex {
    int dummy;
};
extern struct mutex open_lock;
struct floppy_struct *floppy_type;
struct floppy_struct *user_params;
struct floppy_struct **current_type;
int *floppy_sizes;
int buffer_drive;
int buffer_max;
struct block_device **opened_bdev;
struct drive_state {
    int fd_device;
} *drive_state;

#define ITYPE(x) ((x) & 0xff)
#define STRETCH(g) ((g)->stretch & FD_STRETCH)
#define SUPBOUND(a, b) do { if ((a) > (b)) (a) = (b); } while (0)
#define UDP ((struct floppy_struct *)0)
#define DRS ((struct floppy_struct *)0)

static inline int capable(int cap) { return 1; }
static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline int lock_fdc(int drive, ...) { 
    if (drive) return 0; 
    return 0;
}
int poll_drive(int arg1, int arg2) { return 0; }
void process_fd_request(void) {}
void __invalidate_device(struct block_device *bdev, bool flag) {}
void invalidate_drive(struct block_device *bdev) {}