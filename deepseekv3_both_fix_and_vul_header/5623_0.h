#include <stdint.h>

typedef struct FDCtrl FDCtrl;
typedef struct FDrive FDrive;
typedef struct BlockBackend BlockBackend;

#define FD_DOR_nRESET 0x04
#define FD_MSR_RQM 0x80
#define FD_MSR_DIO 0x40
#define FD_MSR_NONDMA 0x20
#define FD_MSR_CMDBUSY 0x10
#define FD_DSR_PWRDOWN 0x40
#define FD_SECTOR_LEN 512
#define FD_STATE_FORMAT 0x01

struct FDrive {
    BlockBackend *blk;
};

struct FDCtrl {
    uint32_t dor;
    uint32_t msr;
    uint32_t dsr;
    int data_pos;
    int data_len;
    uint8_t fifo[FD_SECTOR_LEN];
    int data_state;
};

extern FDrive *get_cur_drv(FDCtrl *fdctrl);
extern int fd_sector(FDrive *drv);
extern int fdctrl_seek_to_next_sect(FDCtrl *fdctrl, FDrive *drv);
extern void fdctrl_stop_transfer(FDCtrl *fdctrl, uint32_t arg0, uint32_t arg1, uint32_t arg2);
extern void fdctrl_format_sector(FDCtrl *fdctrl);
extern int blk_write(BlockBackend *blk, int sector, const uint8_t *buf, int nb_sectors);

extern const struct {
    const char *name;
    int parameters;
    void (*handler)(FDCtrl *, int);
    int direction;
} handlers[];

extern const int command_to_handler[];