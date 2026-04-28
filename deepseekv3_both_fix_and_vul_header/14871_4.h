#include <sys/types.h>
#include <stddef.h>

#define CONFIG_PROC_FS
#define CONFIG_PCI
#define SND_MEM_PROC_FILE "snd_mem"
#define __init

typedef long off_t;
typedef unsigned int mode_t;

struct file {
    // minimal stub definition
};

struct file_operations {
    // minimal stub definition
};

struct proc_dir_entry {
    const struct file_operations *proc_fops;
    int (*read_proc)(char *page, char **start, off_t off, int count, int *eof, void *data);
    int (*write_proc)(struct file *file, const char *buffer, unsigned long count, void *data);
};

static struct proc_dir_entry *snd_mem_proc;
static const struct file_operations snd_mem_proc_fops = {0};
static int snd_mem_proc_read(char *page, char **start, off_t off, int count, int *eof, void *data) { return 0; }
static int snd_mem_proc_write(struct file *file, const char *buffer, unsigned long count, void *data) { return 0; }
static struct proc_dir_entry *create_proc_entry(const char *name, mode_t mode, struct proc_dir_entry *parent) { return NULL; }