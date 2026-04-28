#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

#define MAX_IPC_FLOOD_DURATION_MS 1000
#define MAX_IPC_FLOOD_COUNT 10000
#define GFP_KERNEL 0
#define ENOMEM 12
#define EINVAL 22
#define IS_ENABLED(x) 0

typedef long ssize_t;

struct file {
    void *private_data;
    struct {
        struct dentry *dentry;
    } f_path;
};

struct dentry {
    struct {
        char *name;
    } d_name;
};

struct snd_sof_dfsentry {
    struct snd_sof_dev *sdev;
};

struct snd_sof_dev {
    void *dev;
};

#define __user

void *kzalloc(size_t size, int flags);
void kfree(const void *objp);
size_t simple_write_to_buffer(char *to, size_t count, loff_t *ppos, const char *from, size_t available);
int kstrtoul(const char *s, unsigned int base, unsigned long *res);
int pm_runtime_get_sync(void *dev);
void pm_runtime_put_noidle(void *dev);
void pm_runtime_mark_last_busy(void *dev);
int pm_runtime_put_autosuspend(void *dev);
int sof_debug_ipc_flood_test(struct snd_sof_dev *sdev, struct snd_sof_dfsentry *dfse, bool flood_duration_test, unsigned long ipc_duration_ms, unsigned long ipc_count);