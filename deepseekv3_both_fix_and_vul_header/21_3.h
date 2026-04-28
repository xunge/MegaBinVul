#include <stddef.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned int fmode_t;

#define CAP_SYS_ADMIN 0
#define __user
#define FDEJECT 0x0200
#define FDCLRPRM 0x0201
#define FDSETPRM 0x0202
#define FDDEFPRM 0x0203
#define FDGETPRM 0x0204
#define FDMSGON 0x0205
#define FDMSGOFF 0x0206
#define FDFMTBEG 0x0207
#define FDFMTTRK 0x0208
#define FDFMTEND 0x0209
#define FDFLUSH 0x020A
#define FDSETEMSGTRESH 0x020B
#define FDGETMAXERRS 0x020C
#define FDSETMAXERRS 0x020D
#define FDGETDRVTYP 0x020E
#define FDSETDRVPRM 0x020F
#define FDGETDRVPRM 0x0210
#define FDPOLLDRVSTAT 0x0211
#define FDGETDRVSTAT 0x0212
#define FDRESET 0x0213
#define FDGETFDCSTAT 0x0214
#define FDWERRORCLR 0x0215
#define FDWERRORGET 0x0216
#define FDRAWCMD 0x0217
#define FDTWADDLE 0x0218

struct block_device {
    struct {
        void *private_data;
    } *bd_disk;
};

struct floppy_struct {
    char name[0];
};

struct format_descr {};
struct floppy_max_errors {
    unsigned short reporting;
};
struct floppy_drive_params {
    int autodetect;
    int native_format;
    int flags;
    struct floppy_max_errors max_errors;
};

struct drive_state_t {
    int fd_device;
    int fd_ref;
    int flags;
    int keep_data;
};

#define ITYPE(x) ((x) & 0xff)
#define UNIT(x) ((x) >> 8)
#define FDC(x) ((x) & 0xff)
#define DPRINT(x)
#define MAX_DISK_SIZE 2880
#define FD_RAW_NEED_DISK 0
#define FD_VERIFY 0
#define FD_DISK_WRITABLE 0
#define FD_VERIFY_BIT 0
#define FD_DISK_CHANGED_BIT 0
#define FTD_MSG 0
#define FMODE_WRITE 0x1
#define FMODE_WRITE_IOCTL 0x2
#define _IOC_DIR(x) 0
#define _IOC_WRITE 0
#define _IOC_READ 0
#define WARN_ON(x) 0
#define fallthrough
#define CDROMEJECT 0
#define EINVAL 1
#define EPERM 2
#define EBUSY 3
#define EINTR 4
#define ENODEV 5
#define EROFS 6

static struct drive_state_t drive_state[1];
static void *current_type[1];
static int floppy_sizes[1];
static struct floppy_drive_params drive_params[1];
static int write_errors[1];
static int fdc_state[1];
static int current_fdc;
static int current_drive;

static int capable(int cap) { return 1; }
static int set_bit(int nr, int *addr) { return 0; }
static int SUPBOUND(int *size, int len) { return 0; }
static int normalize_ioctl(unsigned int *cmd, int *size) { return 0; }
static int fd_copyin(void *src, void *dest, int size) { return 0; }
static int fd_copyout(void *dest, const void *src, int size) { return 0; }
static int lock_fdc(int drive) { return 0; }
static int fd_eject(int unit) { return 0; }
static void process_fd_request(void) {}
static int invalidate_drive(struct block_device *bdev) { return 0; }
static int set_geometry(int cmd, struct floppy_struct *g, int drive, int type, struct block_device *bdev) { return 0; }
static int get_floppy_geometry(int drive, int type, struct floppy_struct **outparam) { return 0; }
static int poll_drive(bool arg1, int arg2) { return 0; }
static int do_format(int drive, struct format_descr *f) { return 0; }
static const char *drive_name(int type, int drive) { return NULL; }
static int valid_floppy_drive_params(int autodetect, int native_format) { return 0; }
static int user_reset_fdc(int drive, int param, bool arg) { return 0; }
static void set_floppy(int drive) {}
static int raw_cmd_ioctl(int cmd, void *param) { return 0; }
static void twaddle(int fdc, int drive) {}