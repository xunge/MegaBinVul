#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct work_struct {
    unsigned long data;
    struct list_head entry;
};

struct tty_struct;
struct tty_driver;
struct module;
struct pid;

struct tty_operations {
    void (*cleanup)(struct tty_struct *tty);
};

struct tty_driver {
    struct module *owner;
};

struct tty_struct {
    struct work_struct hangup_work;
    struct tty_driver *driver;
    struct tty_operations *ops;
    unsigned long magic;
    struct list_head tty_files;
    struct pid *pgrp;
    struct pid *session;
};

static inline void list_del_init(struct list_head *entry) {
    entry->next = entry;
    entry->prev = entry;
}

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

extern void file_list_lock(void);
extern void file_list_unlock(void);
extern void tty_driver_kref_put(struct tty_driver *driver);
extern void free_tty_struct(struct tty_struct *tty);
extern void module_put(struct module *module);
extern void put_pid(struct pid *pid);