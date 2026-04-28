#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define GFP_KERNEL 0
#define EIO 5
#define ENOMEM 12
#define ENODEV 19
#define SI_NUM_STATS 10
#define SI_KCS 0
#define SI_SMIC 1
#define SI_BT 2

typedef struct {
    int counter;
} atomic_t;

struct device {
    void *driver;
    char *init_name;
};

struct platform_device {
    struct device dev;
};

struct platform_driver {
    struct device driver;
};

struct attribute_group {
    const char *name;
};

struct ipmi_smi_handlers {
    size_t (*size)(void);
    int (*init_data)(void *, void *);
    int (*detect)(void *);
};

struct smi_info {
    struct {
        int addr_source;
        int si_type;
        int addr_type;
        unsigned long addr_data;
        unsigned int slave_addr;
        int irq;
        struct device *dev;
        size_t io_size;
        int (*io_setup)(void *);
        void (*io_cleanup)(void *);
    } io;
    struct ipmi_smi_handlers *handlers;
    int si_num;
    struct platform_device *pdev;
    bool pdev_registered;
    void *si_sm;
    void *waiting_msg;
    void *curr_msg;
    atomic_t req_events;
    bool run_to_completion;
    atomic_t stats[SI_NUM_STATS];
    bool interrupt_disabled;
    atomic_t need_watch;
    bool has_event_buffer;
    bool dev_group_added;
};

static const char *si_to_str[] = {"KCS", "SMIC", "BT"};
static const char *addr_space_to_str[] = {"I/O", "Memory"};
static const char *ipmi_addr_src_to_str(int addr_source) { return ""; }

static struct ipmi_smi_handlers kcs_smi_handlers;
static struct ipmi_smi_handlers smic_smi_handlers;
static struct ipmi_smi_handlers bt_smi_handlers;

static int smi_num;
static struct ipmi_smi_handlers handlers;
static struct platform_driver ipmi_platform_driver;
static struct attribute_group ipmi_si_dev_attr_group;

static int try_get_dev_id(struct smi_info *smi) { return 0; }
static void setup_oem_data_handler(struct smi_info *smi) {}
static void setup_xaction_handlers(struct smi_info *smi) {}
static void check_for_broken_irqs(struct smi_info *smi) {}
static int try_enable_event_buffer(struct smi_info *smi) { return 0; }
static void start_clear_flags(struct smi_info *smi) {}

static char *kasprintf(int flags, const char *fmt, int num) { return NULL; }
static void *kmalloc(size_t size, int flags) { return NULL; }
static void kfree(void *ptr) {}
static void dev_err(struct device *dev, const char *fmt, ...) {}
static void dev_info(struct device *dev, const char *fmt, ...) {}
static void pr_info(const char *fmt, ...) {}
static void pr_err(const char *fmt, ...) {}
static void WARN_ON(bool condition) {}
static struct platform_device *platform_device_alloc(const char *name, int id) { return NULL; }
static int platform_device_add(struct platform_device *pdev) { return 0; }
static void dev_set_drvdata(struct device *dev, void *data) {}
static int device_add_group(struct device *dev, struct attribute_group *grp) { return 0; }
static int ipmi_register_smi(struct ipmi_smi_handlers *handlers, struct smi_info *smi, struct device *dev, unsigned int slave_addr) { return 0; }

#define atomic_set(v, i) ((v)->counter = (i))