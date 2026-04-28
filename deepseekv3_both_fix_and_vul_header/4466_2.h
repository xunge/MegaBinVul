#include <stdbool.h>

struct seq_file;

struct dentry {
    struct super_block *d_sb;
};

struct super_block {
    void *s_fs_info;
};

struct ovl_config {
    char *lowerdir;
    char *upperdir;
    char *workdir;
    bool default_permissions;
};

struct ovl_fs {
    struct ovl_config config;
};

int seq_show_option(struct seq_file *m, const char *name, const char *value);
int seq_puts(struct seq_file *m, const char *s);