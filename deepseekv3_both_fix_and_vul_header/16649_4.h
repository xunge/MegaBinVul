#include <stdbool.h>

#define EINTR 4
#define ENODEV 19

struct floppy_struct {
    int dummy;
};

extern struct floppy_struct floppy_type[];
extern struct floppy_struct *current_type[];

int lock_fdc(int drive, ...);
int poll_drive(bool arg1, int arg2);
void process_fd_request();