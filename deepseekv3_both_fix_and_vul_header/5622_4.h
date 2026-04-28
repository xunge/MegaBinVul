#include <stdint.h>

#define FD_SECTOR_LEN 512
#define GET_CUR_DRV(fdctrl) (0)

typedef struct FDrive FDrive;
typedef struct FDCtrl FDCtrl;

struct FDrive {
    uint32_t head;
};

struct FDCtrl {
    uint32_t data_pos;
    uint8_t fifo[FD_SECTOR_LEN];
    uint32_t data_len;
};

FDrive *get_cur_drv(FDCtrl *fdctrl);
void fdctrl_set_fifo(FDCtrl *fdctrl, int size);
void fdctrl_reset_fifo(FDCtrl *fdctrl);