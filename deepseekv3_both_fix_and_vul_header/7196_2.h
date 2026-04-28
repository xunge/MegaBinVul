#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <time.h>

struct inode {
    _Atomic int i_count;
    unsigned long i_state;
    void *i_mapping;
    unsigned long dirtied_when;
    struct {
        void *i_lock;
    };
};

struct writeback_control {
    int sync_mode;
};

struct bdi_writeback {
    void *list_lock;
    struct {
        void *b_dirty_time;
    };
};

#define I_WILL_FREE (1 << 0)
#define I_FREEING (1 << 1)
#define I_SYNC (1 << 2)
#define I_DIRTY_ALL (1 << 3)
#define I_SYNC_QUEUED (1 << 4)
#define I_DIRTY (1 << 5)
#define I_DIRTY_TIME (1 << 6)

#define WB_SYNC_NONE 0
#define WB_SYNC_ALL 1

#define PAGECACHE_TAG_WRITEBACK 0

#define WARN_ON(condition) ((void)0)

static unsigned long jiffies = 0;

static void spin_lock(void *lock) {}
static void spin_unlock(void *lock) {}

static void __inode_wait_for_writeback(struct inode *inode) {}
static void wbc_attach_and_unlock_inode(struct writeback_control *wbc, struct inode *inode) {}
static int __writeback_single_inode(struct inode *inode, struct writeback_control *wbc) { return 0; }
static void wbc_detach_inode(struct writeback_control *wbc) {}
static struct bdi_writeback *inode_to_wb_and_lock_list(struct inode *inode) { return NULL; }
static void inode_cgwb_move_to_attached(struct inode *inode, struct bdi_writeback *wb) {}
static void redirty_tail_locked(struct inode *inode, struct bdi_writeback *wb) {}
static void inode_io_list_move_locked(struct inode *inode, struct bdi_writeback *wb, void *list) {}
static void inode_sync_complete(struct inode *inode) {}
static bool mapping_tagged(void *mapping, int tag) { return false; }