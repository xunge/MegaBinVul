#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define GFP_KERNEL 0
#define ENOMEM 12
#define IPMI_DYN_DEV_ID_EXPIRY 0

typedef unsigned long jiffies_t;
#define jiffies ((jiffies_t)0)

typedef struct {
    unsigned char b[16];
} guid_t;

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {
    int dummy;
};

struct work_struct {
    int dummy;
};

struct kobject {
    int dummy;
};

struct kref {
    int dummy;
};

struct device_type {
    const char *name;
};

struct device_driver {
    const char *name;
};

struct device {
    struct device_driver *driver;
    void (*release)(struct device *);
    struct kobject kobj;
    const struct device_type *type;
};

struct platform_device {
    struct device dev;
    int id;
    const char *name;
};

struct ipmi_device_id {
    int manufacturer_id;
    int product_id;
    int device_id;
};

struct bmc_device {
    struct ipmi_device_id id;
    int dyn_id_set;
    bool dyn_guid_set;
    guid_t guid;
    jiffies_t dyn_id_expiry;
    struct platform_device pdev;
    struct list_head intfs;
    struct mutex dyn_mutex;
    struct work_struct remove_work;
    struct kref usecount;
};

struct ipmi_smi {
    bool in_bmc_register;
    struct mutex bmc_reg_mutex;
    struct device *si_dev;
    struct bmc_device *bmc;
    struct list_head bmc_link;
    int intf_num;
    char *my_dev_name;
    bool bmc_registered;
    struct bmc_device tmp_bmc;
};

extern struct device_type bmc_device_type;
extern struct {
    struct device_driver driver;
} ipmidriver;
extern struct mutex ipmidriver_mutex;
extern struct ida ipmi_bmc_ida;

void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
void mutex_init(struct mutex *lock);
void list_add_tail(struct list_head *new, struct list_head *head);
void list_del(struct list_head *entry);
void INIT_LIST_HEAD(struct list_head *list);
void INIT_WORK(struct work_struct *work, void (*func)(struct work_struct *));
void kref_init(struct kref *kref);
void kref_put(struct kref *kref, void (*release)(struct kref *));
void *kzalloc(size_t size, int flags);
void kfree(void *ptr);
char *kasprintf(int flags, const char *fmt, ...);
int ida_simple_get(struct ida *ida, unsigned int start, unsigned int end, int flags);
int platform_device_register(struct platform_device *);
void put_device(struct device *dev);
void dev_info(struct device *dev, const char *fmt, ...);
void dev_err(struct device *dev, const char *fmt, ...);
int sysfs_create_link(struct kobject *kobj, struct kobject *target, const char *name);
void sysfs_remove_link(struct kobject *kobj, const char *name);
struct bmc_device *ipmi_find_bmc_guid(struct device_driver *drv, guid_t *guid);
struct bmc_device *ipmi_find_bmc_prod_dev_id(struct device_driver *drv, int prod_id, int dev_id);
void cleanup_bmc_work(struct work_struct *work);
void cleanup_bmc_device(struct kref *kref);
void release_bmc_device(struct device *dev);