#include <stdlib.h>

struct super_block {
    void *s_fs_info;
};

struct nilfs_root;

struct the_nilfs {
    void *ns_writer;
    struct {
        struct {
            void *bd_inode;
        } *ns_bdev;
    };
};

int nilfs_detach_log_writer(struct super_block *sb);
void *nilfs_segctor_new(struct super_block *sb, struct nilfs_root *root);
int nilfs_segctor_start_thread(void *writer);
void kfree(void *ptr);

#define ENOMEM 12