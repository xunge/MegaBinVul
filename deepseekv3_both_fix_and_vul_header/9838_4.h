#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>

struct list_head {
    struct list_head *next, *prev;
};

struct ibm_struct {
    struct list_head all_drivers;
    struct {
        unsigned int experimental:1;
        unsigned int init_called:1;
        unsigned int proc_created:1;
    } flags;
    const char *name;
    struct {
        void *hid;
        void *notify;
    } *acpi;
    void *read;
    void *write;
};

struct ibm_init_struct {
    void *data;
    int (*init)(struct ibm_init_struct *);
    mode_t base_procfs_mode;
};

struct proc_dir_entry;
struct file_operations;

extern int experimental;
extern struct proc_dir_entry *proc_dir;
extern const struct file_operations dispatch_proc_fops;
extern struct list_head tpacpi_all_drivers;
extern void dbg_printk(int level, const char *fmt, ...);
extern int register_tpacpi_subdriver(struct ibm_struct *ibm);
extern int setup_acpi_notify(struct ibm_struct *ibm);
extern void ibm_exit(struct ibm_struct *ibm);

#define BUG_ON(condition) ((void)0)
#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)
#define TPACPI_DBG_INIT 0
#define TPACPI_NOTICE "NOTICE: "
#define TPACPI_ERR "ERROR: "
#define __init
#define list_add_tail(new, head) ((void)0)
#define printk printf
#define proc_create_data(name, mode, parent, fops, data) NULL

#define S_IRUGO (S_IRUSR | S_IRGRP | S_IROTH)
#define S_IWUSR 0200