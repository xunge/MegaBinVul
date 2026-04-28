#include <stddef.h>
#include <stdatomic.h>

#define SB_FREEZE_LEVELS 2
#define MAX_NON_LFS ((long long)0x7fffffffffffffffLL)
#define DEFAULT_SEEKS 2
#define SINGLE_DEPTH_NESTING 1
#define GFP_USER 0
#define CONFIG_SMP 1
#define SHRINKER_NUMA_AWARE (1 << 0)

struct list_head {
    struct list_head *next, *prev;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_bl_head {
    struct hlist_bl_node *first;
};

struct hlist_bl_node {
    struct hlist_bl_node *next, **pprev;
};

struct rw_semaphore {
    long count;
};

struct mutex {
    long count;
};

struct wait_queue_head {
    int dummy;
};

struct percpu_counter {
    long count;
};

struct lockdep_map {
    const char *name;
};

struct shrinker {
    int seeks;
    int (*scan_objects)(struct shrinker *, void *);
    unsigned long (*count_objects)(struct shrinker *, void *);
    long batch;
    unsigned long flags;
};

struct list_lru {
    int dummy;
};

struct backing_dev_info {
    int dummy;
};

struct super_block;
struct file_system_type;
struct super_operations {
    int (*super_cache_scan)(struct shrinker *, void *);
    unsigned long (*super_cache_count)(struct shrinker *, void *);
};

static const struct super_operations default_op;
struct backing_dev_info default_backing_dev_info;
const char *sb_writers_name[SB_FREEZE_LEVELS];

static int super_cache_scan(struct shrinker *shrink, void *sc) { return 0; }
static unsigned long super_cache_count(struct shrinker *shrink, void *sc) { return 0; }

struct super_block {
    struct list_head s_list;
    unsigned long s_flags;
    const struct super_operations *s_op;
    struct backing_dev_info *s_bdi;
    struct hlist_node s_instances;
    struct hlist_bl_head s_anon;
    struct list_head s_inodes;
    struct list_head s_mounts;
    struct rw_semaphore s_umount;
    int s_count;
    atomic_int s_active;
    struct mutex s_vfs_rename_mutex;
    struct {
        struct mutex dqio_mutex;
        struct mutex dqonoff_mutex;
        struct rw_semaphore dqptr_sem;
    } s_dquot;
    long long s_maxbytes;
    unsigned long s_time_gran;
    int cleancache_poolid;
    struct shrinker s_shrink;
    struct {
        struct percpu_counter counter[SB_FREEZE_LEVELS];
        struct lockdep_map lock_map[SB_FREEZE_LEVELS];
        struct wait_queue_head wait;
        struct wait_queue_head wait_unfrozen;
    } s_writers;
#ifdef CONFIG_SMP
    struct list_head *s_files;
#else
    struct list_head s_files;
#endif
    struct list_lru s_dentry_lru;
    struct list_lru s_inode_lru;
};

struct file_system_type {
    struct lockdep_map s_umount_key;
    struct lockdep_map s_vfs_rename_key;
    struct lockdep_map s_writers_key[SB_FREEZE_LEVELS];
};

static void *kzalloc(size_t size, int flags) { return NULL; }
static int security_sb_alloc(struct super_block *sb) { return 0; }
static int percpu_counter_init(struct percpu_counter *fbc, long long amount) { return 0; }
static void lockdep_init_map(struct lockdep_map *lock, const char *name, struct lockdep_map *key, int subclass) {}
static void init_waitqueue_head(struct wait_queue_head *q) {}
static void INIT_HLIST_NODE(struct hlist_node *h) {}
static void INIT_HLIST_BL_HEAD(struct hlist_bl_head *h) {}
static void INIT_LIST_HEAD(struct list_head *list) {}
static int list_lru_init(struct list_lru *lru) { return 0; }
static void init_rwsem(struct rw_semaphore *sem) {}
static void down_write_nested(struct rw_semaphore *sem, int subclass) {}
static void mutex_init(struct mutex *lock) {}
static void lockdep_set_class_rwsem(struct rw_semaphore *sem, struct lockdep_map *key) {}
static void lockdep_set_class_mutex(struct mutex *lock, struct lockdep_map *key) {}
static void atomic_set(atomic_int *v, int i) { *v = i; }
static void destroy_super(struct super_block *s) {}
static void *alloc_percpu(size_t size) { return NULL; }
static void *per_cpu_ptr(void *ptr, int cpu) { return NULL; }
#define for_each_possible_cpu(i) for (i = 0; i < 1; i++)
#define alloc_percpu(type) ((type *)alloc_percpu(sizeof(type)))