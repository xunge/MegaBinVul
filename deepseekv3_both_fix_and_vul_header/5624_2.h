#include <stdint.h>
#include <string.h>

#define FD_DSR_PWRDOWN 0x40
#define FD_MSR_RQM 0x80
#define FD_MSR_DIO 0x40
#define FD_MSR_NONDMA 0x20
#define FD_SECTOR_LEN 512

typedef struct FDrive FDrive;
typedef struct FDCtrl FDCtrl;

struct FDrive {
    void *blk;
};

struct FDCtrl {
    uint8_t dsr;
    uint8_t msr;
    int data_pos;
    int data_len;
    uint8_t fifo[FD_SECTOR_LEN];
};

static FDrive* get_cur_drv(FDCtrl* fdctrl);
static int fd_sector(FDrive* drv);
static int fdctrl_seek_to_next_sect(FDCtrl* fdctrl, FDrive* drv);
static void fdctrl_stop_transfer(FDCtrl* fdctrl, uint8_t st0, uint8_t st1, uint8_t st2);
static void fdctrl_reset_fifo(FDCtrl* fdctrl);
static void fdctrl_reset_irq(FDCtrl* fdctrl);
static int blk_read(void* blk, int sector, uint8_t* fifo, int count);
#define FLOPPY_DPRINTF(fmt, ...)