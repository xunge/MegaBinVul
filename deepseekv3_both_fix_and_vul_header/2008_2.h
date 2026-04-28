#include <stddef.h>
#include <signal.h>
#include <stdio.h>

struct sysex_info {
    int len;
    char data[0];
};

struct synth_operations {
    int midi_dev;
};

struct midi_operations {
    int (*outputc)(int dev, unsigned char data);
};

extern struct synth_operations *synth_devs[];
extern struct midi_operations *midi_devs[];

#define SYSEX_PATCH 0
#define EINVAL 22
#define EFAULT 14
#define KERN_WARNING

#define __user
#define current (0)

int leave_sysex(int dev);
int prefix_cmd(int orig_dev, int cmd);
int midi_outc(int orig_dev, unsigned char data);
int copy_from_user(void *dst, const void *src, unsigned long size);
int get_user(unsigned char data, const unsigned char *src);
void schedule(void);
int signal_pending(int p);