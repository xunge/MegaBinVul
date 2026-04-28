#include <stdio.h>
#include <stdlib.h>

struct file {
    void *private_data;
};

struct inode {
};

struct capsule_info {
    int index;
    size_t count;
    size_t total_size;
    struct {
        size_t headersize;
    } header;
    void *pages;
    void *phys;
};

#define pr_err(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define kfree free

void efi_free_all_buff_pages(struct capsule_info *cap_info);