#include <pthread.h>

extern pthread_mutex_t nfc_devlist_mutex;
extern unsigned int nfc_devlist_generation;
extern const struct rfkill_ops nfc_rfkill_ops;

struct device {
    char name[64];
};

struct rfkill;
struct rfkill_ops;

struct nfc_dev {
    struct device dev;
    struct rfkill *rfkill;
};

int nfc_llcp_register_device(struct nfc_dev *dev);
int nfc_genl_device_added(struct nfc_dev *dev);
int device_add(struct device *dev);
char *dev_name(struct device *dev);
struct rfkill *rfkill_alloc(const char *name, struct device *dev, int type, const struct rfkill_ops *ops, void *priv);
int rfkill_register(struct rfkill *rfkill);
void rfkill_destroy(struct rfkill *rfkill);

#define RFKILL_TYPE_NFC 0
#define pr_debug(fmt, ...) 
#define pr_err(fmt, ...) 

static inline void mutex_lock(pthread_mutex_t *mutex) {
    pthread_mutex_lock(mutex);
}

static inline void mutex_unlock(pthread_mutex_t *mutex) {
    pthread_mutex_unlock(mutex);
}