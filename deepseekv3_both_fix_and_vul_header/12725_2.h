#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include <stddef.h>

#define ECANCELED 125
#define IDE_RETRY_DMA 0
#define IDE_RETRY_READ 1
#define IDE_RETRY_TRIM 2
#define IDE_DMA_READ 0
#define IDE_DMA_WRITE 1
#define IDE_DMA_TRIM 2
#define READY_STAT 0
#define SEEK_STAT 0
#define DMA_DIRECTION_TO_DEVICE 0

typedef struct IDEState IDEState;
typedef struct IDEDMA IDEDMA;
typedef struct BlockBackend BlockBackend;
typedef struct BlockAcctStats BlockAcctStats;
typedef struct BlockAcctCookie BlockAcctCookie;
typedef struct ScatterGatherEntry ScatterGatherEntry;

struct BlockAcctCookie {};
struct BlockAcctStats {};
struct ScatterGatherEntry {
    int size;
};

struct IDEState {
    int io_buffer_size;
    int nsector;
    int dma_cmd;
    int status;
    int io_buffer_index;
    BlockBackend *blk;
    BlockAcctCookie acct;
    struct {
        IDEDMA *dma;
    } *bus;
    ScatterGatherEntry sg;
};

struct IDEDMA {
    struct {
        int (*prepare_buf)(IDEDMA *, bool);
    } *ops;
    void *aiocb;
};

static inline int64_t ide_get_sector(IDEState *s) { return 0; }
static inline void ide_set_sector(IDEState *s, int64_t sector_num) {}
static inline void ide_set_irq(void *bus) {}
static inline bool ide_cmd_is_read(IDEState *s) { return false; }
static inline bool ide_sect_range_ok(IDEState *s, int64_t sector_num, int n) { return false; }
static inline void ide_dma_error(IDEState *s) {}
static inline bool ide_handle_rw_error(IDEState *s, int error, int op) { return false; }
static inline void ide_set_inactive(IDEState *s, bool stay_active) {}
static inline void dma_buf_commit(IDEState *s, ...) {}
static inline void *dma_blk_read(BlockBackend *blk, ScatterGatherEntry *sg, int64_t sector_num, void (*cb)(void *, int), void *opaque) { return NULL; }
static inline void *dma_blk_write(BlockBackend *blk, ScatterGatherEntry *sg, int64_t sector_num, void (*cb)(void *, int), void *opaque) { return NULL; }
static inline void *dma_blk_io(BlockBackend *blk, ScatterGatherEntry *sg, int64_t sector_num, void (*issue)(void *), void (*cb)(void *, int), void *opaque, int direction) { return NULL; }
static inline void ide_issue_trim(void *opaque) {}
static inline BlockAcctStats *blk_get_stats(BlockBackend *blk) { return NULL; }
static inline void block_acct_done(BlockAcctStats *stats, BlockAcctCookie *cookie) {}