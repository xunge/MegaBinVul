#include <stdbool.h>

#define EINTR 4
#define FD_RESET_ALWAYS 1

struct fd_controller {
    int reset;
};

extern struct fd_controller *FDCS;
extern struct cont_struct *cont;
extern struct cont_struct reset_cont;

int lock_fdc(int drive, ...);
int wait_til_done(void (*func)(void), bool interruptible);
void reset_fdc(void);
void process_fd_request(void);