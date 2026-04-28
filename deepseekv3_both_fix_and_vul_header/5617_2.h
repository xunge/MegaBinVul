#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include <stddef.h>

#define ECANCELED 125

#define IDE_RETRY_DMA 0x01
#define IDE_RETRY_READ 0x02
#define IDE_RETRY_TRIM 0x04

#define IDE_DMA_READ 0
#define IDE_DMA_WRITE 1
#define IDE_DMA_TRIM 2

#define READY_STAT 0x40
#define SEEK_STAT 0x10

typedef struct IDEState IDEState;
typedef struct IDEDMA IDEDMA;
typedef struct BlockBackend BlockBackend;
typedef struct BlockAcctStats BlockAcctStats;
typedef struct BlockAcctCookie BlockAcctCookie;

struct ScatterGatherList {
    size_t size;
};

struct BlockAcctCookie {
    int dummy;
};

struct IDEState {
    int io_buffer_size;
    int io_buffer_index;
    int nsector;
    int status;
    int dma_cmd;
    BlockBackend *blk;
    struct {
        IDEDMA *dma;
    } *bus;
    struct ScatterGatherList sg;
    struct BlockAcctCookie acct;
    int64_t sector_num;
};

struct IDEDMA {
    struct {
        int (*prepare_buf)(IDEDMA *, bool);
    } *ops;
    void *aiocb;
};

enum DMA_DIRECTION {
    DMA_DIRECTION_TO_DEVICE,
    DMA_DIRECTION_FROM_DEVICE
};

int ide_handle_rw_error(IDEState *s, int error, int op);
int64_t ide_get_sector(IDEState *s);
void ide_set_sector(IDEState *s, int64_t sector_num);
void ide_set_irq(void *bus);
bool ide_cmd_is_read(IDEState *s);
bool ide_sect_range_ok(IDEState *s, int64_t sector_num, int n);
void ide_dma_error(IDEState *s);
void *dma_blk_read(BlockBackend *blk, struct ScatterGatherList *sg, int64_t sector_num, 
                  void (*cb)(void *, int), void *opaque);
void *dma_blk_write(BlockBackend *blk, struct ScatterGatherList *sg, int64_t sector_num,
                   void (*cb)(void *, int), void *opaque);
void *dma_blk_io(BlockBackend *blk, struct ScatterGatherList *sg, int64_t sector_num,
                void (*io_func)(void *), void (*cb)(void *, int), void *opaque,
                enum DMA_DIRECTION direction);
void ide_issue_trim(void *opaque);
void dma_buf_commit(IDEState *s, int size);
void ide_set_inactive(IDEState *s, bool stay_active);
BlockAcctStats *blk_get_stats(BlockBackend *blk);
void block_acct_done(BlockAcctStats *stats, struct BlockAcctCookie *cookie);