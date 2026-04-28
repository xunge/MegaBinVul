#include <stdint.h>

#define ABRT_ERR 0x04
#define READY_STAT 0x40
#define ERR_STAT 0x01

typedef struct IDEState {
    uint8_t error;
    uint8_t status;
} IDEState;

typedef struct IDEDrive {
    struct {
        IDEState ifs[1];
    } port;
    struct {
        uint32_t scr_err;
    } port_regs;
} IDEDrive;

typedef struct NCQTransferState {
    IDEDrive *drive;
    unsigned tag;
    int used;
} NCQTransferState;