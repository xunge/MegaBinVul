#include <stdio.h>
#include <stdlib.h>

struct dentry {
    // 简化版dentry结构体定义
};

struct dentry *debugfs_create_dir(const char *name, struct dentry *parent);
void acpi_custom_method_init(void);

extern struct dentry *acpi_debugfs_dir;
#define __init