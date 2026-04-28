#include <stddef.h>
#include <stdint.h>

struct raw_cmd_struct {
    int track;
    int flags;
    int rate;
    int cmd_count;
    void *kernel_data;
    int length;
};

struct floppy_struct {
    int rate;
    int sect;
    int fmt_gap;
    int stretch;
};

struct format_request {
    int track;
    int head;
};

#define FD_RAW_WRITE 0x01
#define FD_RAW_INTR 0x02
#define FD_RAW_SPIN 0x04
#define FD_RAW_NEED_DISK 0x08
#define FD_RAW_NEED_SEEK 0x10
#define NR_F 0
#define FM_MODE(f, cmd) 0
#define UNIT(drive) 0
#define PH_HEAD(f, head) 0
#define FD_SIZECODE(f) 0
#define FD_FILL_BYTE 0
#define FD_SECTBASEMASK 0
#define FD_SECTBASE(f) 0

static struct raw_cmd_struct default_raw_cmd;
static struct raw_cmd_struct *raw_cmd;
static struct floppy_struct *_floppy;
static struct format_request format_req;
static void *floppy_track_buffer;
static int current_drive;
static int COMMAND;
static int DR_SELECT;
static int F_SIZECODE;
static int F_SECT_PER_TRACK;
static int F_GAP;
static int F_FILL;