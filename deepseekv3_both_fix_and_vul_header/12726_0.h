#include <stdbool.h>

typedef struct IDEState IDEState;
typedef struct IDEBus IDEBus;
typedef struct DMADevice DMADevice;
typedef struct DMAOps DMAOps;
typedef struct BlockBackend BlockBackend;

typedef enum {
    BLOCK_ERROR_ACTION_IGNORE,
    BLOCK_ERROR_ACTION_REPORT,
    BLOCK_ERROR_ACTION_STOP
} BlockErrorAction;

#define IDE_RETRY_READ  0x01
#define IDE_RETRY_DMA   0x02

struct DMAOps {
    void (*set_unit)(DMADevice *dma, int unit);
};

struct DMADevice {
    const DMAOps *ops;
};

struct IDEBus {
    DMADevice *dma;
    int error_status;
};

struct IDEState {
    IDEBus *bus;
    BlockBackend *blk;
    int unit;
};

BlockErrorAction blk_get_error_action(BlockBackend *blk, bool is_read, int error);
void blk_error_action(BlockBackend *blk, BlockErrorAction action, bool is_read, int error);
void dma_buf_commit(IDEState *s);
void ide_dma_error(IDEState *s);
void ide_rw_error(IDEState *s);