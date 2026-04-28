#include <stdatomic.h>

struct file {
    atomic_long f_count;
};

void security_file_free(struct file *file);
void file_sb_list_del(struct file *file);
void file_free(struct file *file);