#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

#define CAP_SYS_ADMIN 1
#define EPERM 1
#define ENODEV 19
#define ENOENT 2
#define ENOMEM 12
#define GFP_KERNEL 0
#define RBD_SNAP_HEAD_NAME "head"
#define RBD_DEV_FLAG_READONLY 0
#define SECTOR_SHIFT 9

typedef uint64_t u64;
typedef struct { int lock; } spinlock_t;

struct device;
struct gendisk {
    void *queue;
    char *disk_name;
};
struct list_head {
    struct list_head *next, *prev;
};
struct bus_type;
struct module;
struct rbd_device {
    struct rbd_options *opts;
    struct rbd_spec *spec;
    unsigned long flags;
    char *config_info;
    struct device *dev;
    struct gendisk *disk;
    struct {
        unsigned int object_size;
    } layout;
    struct {
        u64 features;
    } header;
    struct list_head node;
};
struct ceph_options;
struct rbd_options {
    int read_only;
    unsigned int alloc_size;
};
struct rbd_spec {
    char *pool_name;
    u64 pool_id;
    char *snap_name;
};
struct rbd_client {
    struct {
        struct {
            struct {
                void *osdmap;
            } osdc;
        } *client;
    };
};

extern spinlock_t rbd_dev_list_lock;
extern struct list_head rbd_dev_list;
extern struct bus_type *bus;
extern struct module *THIS_MODULE;
extern int capable(int cap);
extern int try_module_get(struct module *module);
extern void module_put(struct module *module);
extern void *kstrdup(const char *s, int gfp);
extern void kfree(void *ptr);
extern void pr_info(const char *fmt, ...);
extern int rbd_add_parse_args(const char *buf, struct ceph_options **opts, struct rbd_options **rbd_opts, struct rbd_spec **spec);
extern struct rbd_client *rbd_get_client(struct ceph_options *opts);
extern int IS_ERR(const void *ptr);
extern long PTR_ERR(const void *ptr);
extern int ceph_pg_poolid_by_name(void *osdmap, const char *pool_name);
extern struct rbd_device *rbd_dev_create(struct rbd_client *rbdc, struct rbd_spec *spec, struct rbd_options *opts);
extern void __set_bit(int nr, volatile unsigned long *addr);
extern int rbd_dev_image_probe(struct rbd_device *rbd_dev, int flags);
extern void rbd_warn(struct rbd_device *rbd_dev, const char *fmt, ...);
extern int rbd_dev_device_setup(struct rbd_device *rbd_dev);
extern int rbd_add_acquire_lock(struct rbd_device *rbd_dev);
extern int device_add(struct device *dev);
extern void device_add_disk(struct device *dev, struct gendisk *disk, void *arg);
extern void blk_put_queue(void *queue);
extern void spin_lock(spinlock_t *lock);
extern void spin_unlock(spinlock_t *lock);
extern void list_add_tail(struct list_head *new, struct list_head *head);
extern unsigned long long get_capacity(struct gendisk *disk);
extern void rbd_dev_image_unlock(struct rbd_device *rbd_dev);
extern void rbd_dev_device_release(struct rbd_device *rbd_dev);
extern void rbd_dev_image_release(struct rbd_device *rbd_dev);
extern void rbd_dev_destroy(struct rbd_device *rbd_dev);
extern void rbd_put_client(struct rbd_client *rbdc);
extern void rbd_spec_put(struct rbd_spec *spec);