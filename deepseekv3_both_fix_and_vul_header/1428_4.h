#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

struct device {
    char name[64];
};

struct rfkill;
struct rfkill_ops {
    int dummy;
};

struct nfc_dev {
    struct device dev;
    struct rfkill *rfkill;
    bool shutting_down;
};

pthread_mutex_t nfc_devlist_mutex = PTHREAD_MUTEX_INITIALIZER;
unsigned int nfc_devlist_generation;
struct rfkill_ops nfc_rfkill_ops;

#define RFKILL_TYPE_NFC 1
#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define pr_err(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define mutex_lock(lock) pthread_mutex_lock(lock)
#define mutex_unlock(lock) pthread_mutex_unlock(lock)
#define device_lock(dev) 
#define device_unlock(dev) 

static inline char *dev_name(struct device *dev) {
    return dev->name;
}

static inline int device_add(struct device *dev) {
    return 0;
}

static inline int nfc_llcp_register_device(struct nfc_dev *dev) {
    return 0;
}

static inline int nfc_genl_device_added(struct nfc_dev *dev) {
    return 0;
}

static inline struct rfkill *rfkill_alloc(const char *name, struct device *dev, int type, struct rfkill_ops *ops, void *data) {
    return NULL;
}

static inline int rfkill_register(struct rfkill *rfkill) {
    return 0;
}

static inline void rfkill_destroy(struct rfkill *rfkill) {
}