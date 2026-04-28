#include <stdio.h>

struct seq_file;
struct dentry {
    struct super_block *d_sb;
};
struct super_block {
    struct pid_namespace *s_fs_info;
};
struct pid_namespace {
    unsigned long pid_gid;
    unsigned int hide_pid;
};

int seq_printf(struct seq_file *seq, const char *fmt, ...);