#include <stdint.h>
#include <stdatomic.h>
#include <stddef.h>

struct btrfs_trans_handle;
struct btrfs_fs_info;
struct btrfs_transaction;

struct list_head {
    struct list_head *next, *prev;
};

struct btrfs_block_rsv {
    // Minimal definition for compilation
    uint64_t size;
};

void btrfs_block_rsv_release(struct btrfs_fs_info *fs_info, struct btrfs_block_rsv *block_rsv, uint64_t num_bytes, void *unused);
void cond_wake_up(void *wait);
int list_empty(struct list_head *head);
void WARN_ON_ONCE(int condition);

struct btrfs_trans_handle {
    struct btrfs_fs_info *fs_info;
    struct btrfs_transaction *transaction;
    uint64_t chunk_bytes_reserved;
    struct list_head new_bgs;
};

struct btrfs_transaction {
    _Atomic uint64_t chunk_bytes_reserved;
    void *chunk_reserve_wait;
};

struct btrfs_fs_info {
    struct btrfs_block_rsv chunk_block_rsv;
};