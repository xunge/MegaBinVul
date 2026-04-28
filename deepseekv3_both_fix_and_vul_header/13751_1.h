#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct ttusb_dec {
    int usb_mutex;
    void *udev;
    unsigned int trans_count;
    unsigned int command_pipe;
    unsigned int result_pipe;
};

#define COMMAND_PACKET_SIZE 64
#define GFP_KERNEL 0
#define ENOMEM 12

#define dprintk(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define debug 0
#define KERN_DEBUG ""
#define printk printf

typedef unsigned char u8;

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline int mutex_lock_interruptible(int *mutex) { return 0; }
static inline void mutex_unlock(int *mutex) {}
static inline int usb_bulk_msg(void *udev, unsigned int pipe, void *data, int len, int *actual_len, int timeout) { return 0; }