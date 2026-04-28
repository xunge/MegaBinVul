#include <stddef.h>

struct inode;
struct file {
    void *private_data;
};
struct seq_file {
    void *private;
};

void psi_trigger_replace(void **ptr, void *trigger);
int single_release(struct inode *inode, struct file *file);