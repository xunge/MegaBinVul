#include <stdbool.h>
#include <stddef.h>

typedef struct { unsigned long bits[1]; } cpumask_t;
#define for_each_cpu(cpu, mask) for ((cpu) = 0; (cpu) < 1; (cpu)++)

struct coresight_device;

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct work_struct {
    unsigned long data;
    struct list_head entry;
    void (*func)(struct work_struct *work);
};

struct etm_event_data {
    struct work_struct work;
    cpumask_t mask;
    void *path[1];
    void *snk_config;
};

struct sink_ops {
    void *(*alloc_buffer)(struct coresight_device *, int, void **, int, bool);
};

extern struct coresight_device *coresight_get_enabled_sink(bool);
extern void INIT_WORK(struct work_struct *work, void (*func)(struct work_struct *));
extern struct coresight_device *per_cpu(struct coresight_device *, int);
extern void *coresight_build_path(struct coresight_device *, struct coresight_device *);
extern bool IS_ERR(const void *);
extern struct etm_event_data *alloc_event_data(int cpu);
extern void free_event_data(struct work_struct *work);
extern void etm_free_aux(struct etm_event_data *event_data);
extern struct sink_ops *sink_ops(struct coresight_device *);
extern struct coresight_device *csdev_src;