#include <stdbool.h>

#define N_DRIVE 4
#define FD_STRETCH 0x01
#define FD_SWAPSIDES 0x02
#define FD_SECTBASEMASK 0xFC
#define FDDEFPRM 1
#define FD_RAW_NEED_DISK 1
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
};

struct block_device;
struct mutex {
    int dummy;
};
struct fd_drive_struct {
    int maxblock;
    int maxtrack;
    int keep_data;
};
struct fd_drive_state {
    int fd_device;
};
struct udp_struct {
    int tracks;
};

#define FD_SIZECODE(g) ((g)->stretch & 3)
#define STRETCH(g) ((g)->stretch & 1)
#define ITYPE(dev) ((dev) & 0x03)
#define SUPBOUND(a,b) ((a) = ((a) > (b) ? (b) : (a)))

extern struct floppy_struct floppy_type[];
extern int floppy_sizes[];
extern struct block_device *opened_bdev[];
extern struct fd_drive_state drive_state[];
extern struct fd_drive_struct *DRS;
extern int buffer_drive;
extern int buffer_max;
extern struct floppy_struct user_params[];
extern struct floppy_struct *current_type[];
extern struct mutex open_lock;
extern struct udp_struct *UDP;

static int lock_fdc(int drive);
static int poll_drive(bool arg1, int arg2);
static void process_fd_request(void);
static void invalidate_drive(struct block_device *bdev);
static void __invalidate_device(struct block_device *bdev, bool arg);
static int capable(int cap);
static void mutex_lock(struct mutex *lock);
static void mutex_unlock(struct mutex *lock);