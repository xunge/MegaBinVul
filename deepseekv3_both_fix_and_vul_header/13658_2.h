#include <stdbool.h>
#include <stddef.h>
#include <string.h>

typedef unsigned int u32;

struct vmmdev_hgcm_function_parameter {
    int type;
    union {
        struct {
            union {
                unsigned long linear_addr;
            } u;
            u32 size;
        } pointer;
    } u;
};

#define __user
#define VMMDEV_HGCM_PARM_TYPE_LINADDR_OUT 0
#define VBG_MAX_HGCM_USER_PARM 0
#define E2BIG 0
#define ENOMEM 0
#define EFAULT 0
#define GFP_KERNEL 0

void *kvmalloc(size_t size, int flags);
int copy_from_user(void *to, const void *from, size_t n);
void hgcm_call_add_pagelist_size(void *buf, size_t len, size_t *extra);