#include <stddef.h>
#include <sys/types.h>

#define OZ_APPID_SERIAL 0
#define OZ_APPID_USB 0
#define OZ_PD_S_CONNECTED 0
#define OZ_ELT_APP_DATA 0
#define EINVAL 22
#define ENXIO 6
#define EAGAIN 11

struct oz_elt_buf {
    int lock;
};

struct oz_elt_info {
    char data[256];
    size_t length;
    int app_id;
};

struct oz_elt {
    size_t length;
    int type;
};

struct oz_app_hdr {
    int app_id;
    int elt_seq_num;
};

struct oz_serial_ctx {
    int tx_seq_num;
};

struct oz_pd {
    unsigned int state;
    struct oz_elt_buf elt_buff;
    int app_lock[1];
    void *app_ctx[1];
};

struct file {
    int dummy;
};

typedef long ssize_t;
typedef long loff_t;
#define __user

struct g_cdev {
    int lock;
    struct oz_pd *active_pd;
} g_cdev;

static void spin_lock_bh(int *lock) {}
static void spin_unlock_bh(int *lock) {}
static void spin_lock(int *lock) {}
static void spin_unlock(int *lock) {}
static void oz_pd_get(struct oz_pd *pd) {}
static void oz_pd_put(struct oz_pd *pd) {}
static struct oz_elt_info *oz_elt_info_alloc(struct oz_elt_buf *eb) { return NULL; }
static int oz_queue_elt_info(struct oz_elt_buf *eb, int a, int b, struct oz_elt_info *ei) { return 0; }
static void oz_elt_info_free(struct oz_elt_buf *eb, struct oz_elt_info *ei) {}
static int copy_from_user(void *dst, const void *src, size_t count) { return 0; }