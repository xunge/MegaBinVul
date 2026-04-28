#include <stdbool.h>
#include <errno.h>

struct format_descr {
    int track;
    int head;
};

struct floppy_struct {
    int track;
    int head;
    int sect;
    int fmt_gap;
};

struct floppy_drive_params {
    int tracks;
};

extern struct floppy_struct *_floppy;
extern struct floppy_drive_params *DP;
extern struct format_descr format_req;
extern int format_errors;
extern void *cont;
extern int *errors;
extern void *format_cont;

#define FD_SIZECODE(floppy) ((floppy)->sect)

int lock_fdc(int drive, ...);
void set_floppy(int drive);
void process_fd_request(void);
int wait_til_done(void (*func)(void), bool interruptible);
void redo_format(void);