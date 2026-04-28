#include <stdint.h>
#include <stdlib.h>

#define ENODEV 19
#define EINVAL 22
#define ENOMEM 12
#define EOPNOTSUPP 95

#define SENSOR_DISABLED 0
#define SENSOR_ENABLED 1
#define AMD_SFH_IDLE_LOOP 0
#define GFP_KERNEL 0
#define descr_size 0
#define feature_size 1
#define input_size 2

typedef uint32_t u32;
typedef uint8_t u8;

struct device {
    int dummy;
};

struct list_head {
    struct list_head *next, *prev;
};

struct request_list {
    struct list_head list;
};

struct amd_input_data {
    void *sensor_virt_addr[10];
    void *input_report[10];
};

struct amdtp_cl_data {
    struct request_list req_list;
    struct amd_input_data *in_data;
    u32 num_hid_devices;
    u8 sensor_idx[10];
    u8 sensor_sts[10];
    u32 sensor_requested_cnt[10];
    u8 cur_hid_dev;
    u32 report_descr_sz[10];
    void *feature_report[10];
    void *report_descr[10];
    uintptr_t sensor_dma_addr[10];
    struct {
        int dummy;
    } work;
    struct {
        int dummy;
    } work_buffer;
};

struct amd_mp2_sensor_info {
    u32 period;
    u8 sensor_idx;
    uintptr_t dma_address;
};

struct amd_mp2_ops {
    int (*suspend)(void);
    int (*resume)(void);
    u32 (*get_desc_sz)(u8, int);
    int (*get_rep_desc)(u8, void*);
    int (*start)(struct amd_mp2_dev*, struct amd_mp2_sensor_info);
    int (*stop)(struct amd_mp2_dev*, u8);
    int (*discovery_status)(struct amd_mp2_dev*);
};

struct amd_mp2_dev {
    struct amd_input_data in_data;
    struct amdtp_cl_data *cl_data;
    struct amd_mp2_ops *mp2_ops;
    struct {
        struct device dev;
    } *pdev;
};

#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

#define INIT_DELAYED_WORK(work, func) (void)0
#define dev_dbg(dev, fmt, ...) (void)0
#define dev_warn(dev, fmt, ...) (void)0
#define devm_kzalloc(dev, size, flags) malloc(size)
#define devm_kfree(dev, ptr) free(ptr)
#define dma_alloc_coherent(dev, size, dma_handle, flags) malloc(size)
#define dma_free_coherent(dev, size, cpu_addr, dma_handle) free(cpu_addr)
#define schedule_delayed_work(work, delay) (void)0
#define msecs_to_jiffies(msec) (msec)

static int amd_sfh_suspend(void) { return 0; }
static int amd_sfh_resume(void) { return 0; }
static void amd_sfh_set_desc_ops(struct amd_mp2_ops *ops) {}
static u32 amd_mp2_get_sensor_num(struct amd_mp2_dev *dev, u8 *idx) { return 0; }
static int amd_sfh_wait_for_response(struct amd_mp2_dev *dev, u8 idx, int status) { return 0; }
static int amdtp_hid_probe(u8 idx, struct amdtp_cl_data *cl_data) { return 0; }
static void amd_sfh_hid_client_deinit(struct amd_mp2_dev *dev) {}
static const char *get_sensor_name(u8 idx) { return ""; }