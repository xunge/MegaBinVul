#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

typedef uint16_t u16;
#define GFP_KERNEL 0
#define KERN_DEBUG 0
#define ENOMEM 12

struct list_head {
    struct list_head *next, *prev;
};

struct device {
    // minimal device structure
};

struct megasas_cmd {
    int index;
    void *scmd;
    struct megasas_instance *instance;
    struct list_head list;
};

struct megasas_instance {
    u16 max_mfi_cmds;
    struct megasas_cmd **cmd_list;
    struct device *pdev;
    struct list_head cmd_pool;
};

#define kcalloc(n, size, flags) calloc(n, size)
#define kmalloc(size, flags) malloc(size)
#define kfree(ptr) free(ptr)
#define dev_printk(level, dev, fmt, ...) printf(fmt, ##__VA_ARGS__)

static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

int megasas_create_frame_pool(struct megasas_instance *instance);
void megasas_free_cmds(struct megasas_instance *instance);