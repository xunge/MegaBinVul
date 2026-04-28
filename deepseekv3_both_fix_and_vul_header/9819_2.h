#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>

typedef unsigned short umode_t;

struct dentry;
struct file_operations {
    // Minimal stub to satisfy compilation
    int dummy;
};

#define S_IWUGO (S_IWUSR|S_IWGRP|S_IWOTH)
#define __init
#define EINVAL 22

struct dentry *debugfs_create_dir(const char *name, struct dentry *parent) { return NULL; }
struct dentry *debugfs_create_file(const char *name, umode_t mode, struct dentry *parent, void *data, const struct file_operations *fops) { return NULL; }
void debugfs_remove(struct dentry *dentry) {}

extern struct file_operations cm_fops;