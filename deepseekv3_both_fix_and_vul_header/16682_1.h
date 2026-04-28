#include <stddef.h>
#include <stdint.h>

typedef uint64_t u64;

struct btrfs_root {
    struct btrfs_fs_info *fs_info;
    struct {
        u64 objectid;
    } root_key;
};

struct btrfs_fs_info;

struct extent_buffer {
    u64 start;
    u64 bytenr;
    int level;
    u64 owner;
    u64 generation;
    int nritems;
};

struct tree_mod_root {
    u64 logical;
    int level;
};

struct tree_mod_elem {
    int op;
    u64 generation;
    struct tree_mod_root old_root;
};

enum {
    MOD_LOG_ROOT_REPLACE,
    MOD_LOG_KEY_REMOVE_WHILE_FREEING
};

#define BTRFS_MIXED_BACKREF_REV 0
#define WARN_ON(cond) (cond)
#define IS_ERR(ptr) (0)
#define BTRFS_NODEPTRS_PER_BLOCK(fs_info) (0)

struct extent_buffer *btrfs_read_lock_root_node(struct btrfs_root *root);
struct tree_mod_elem *__tree_mod_log_oldest_root(struct extent_buffer *eb, u64 time_seq);
int btrfs_header_level(struct extent_buffer *eb);
struct tree_mod_elem *tree_mod_log_search(struct btrfs_fs_info *fs_info, u64 logical, u64 time_seq);
void btrfs_tree_read_unlock(struct extent_buffer *eb);
void free_extent_buffer(struct extent_buffer *eb);
struct extent_buffer *read_tree_block(struct btrfs_fs_info *fs_info, u64 logical, u64 objectid, int unused, int level, void *null);
int extent_buffer_uptodate(struct extent_buffer *eb);
void btrfs_warn(struct btrfs_fs_info *fs_info, const char *fmt, ...);
struct extent_buffer *btrfs_clone_extent_buffer(struct extent_buffer *old);
u64 btrfs_header_owner(struct extent_buffer *eb);
struct extent_buffer *alloc_dummy_extent_buffer(struct btrfs_fs_info *fs_info, u64 logical);
void btrfs_set_header_bytenr(struct extent_buffer *eb, u64 bytenr);
void btrfs_set_header_backref_rev(struct extent_buffer *eb, int rev);
void btrfs_set_header_owner(struct extent_buffer *eb, u64 owner);
void btrfs_set_header_level(struct extent_buffer *eb, int level);
void btrfs_set_header_generation(struct extent_buffer *eb, u64 generation);
void btrfs_set_buffer_lockdep_class(u64 owner, struct extent_buffer *eb, int level);
void btrfs_tree_read_lock(struct extent_buffer *eb);
void __tree_mod_log_rewind(struct btrfs_fs_info *fs_info, struct extent_buffer *eb, u64 time_seq, struct tree_mod_elem *tm);
int btrfs_header_nritems(struct extent_buffer *eb);