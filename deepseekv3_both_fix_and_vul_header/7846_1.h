#include <stdint.h>

#define N_DRIVE 4
#define N_FDC 2
#define FDC(drive) ((drive) < 2 ? 0 : 1)
#define STATUS_READY 0x80
#define FD_STATUS 0x3F4

extern int fdc;
extern int current_drive;

struct floppy_struct {
    int rawcmd;
    int reset;
};

extern struct floppy_struct *FDCS;

void pr_info(const char *fmt, ...);
void set_dor(int fdc, uint32_t mask, uint32_t val);
void reset_fdc_info(int flag);
uint8_t fd_inb(uint16_t port);