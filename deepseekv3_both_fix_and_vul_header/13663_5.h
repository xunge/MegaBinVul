#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

typedef unsigned int u32;

#define IR_SUBDEV_NAME "ir"
#define RX_S_PARAMETERS "rx_s_parameters"
#define TX_S_PARAMETERS "tx_s_parameters"

struct v4l2_subdev_ir_parameters {
    int dummy;
};

struct v4l2_subdev {
    char name[32];
    int grp_id;
    void *priv;
};

struct v4l2_subdev_ops {
    int dummy;
};

struct v4l2_device {
    struct v4l2_subdev *subdev;
};

struct cx23885_dev {
    char name[32];
    struct v4l2_device v4l2_dev;
};

struct cx23888_ir_state {
    pthread_mutex_t rx_kfifo_lock;
    pthread_mutex_t rx_params_lock;
    pthread_mutex_t tx_params_lock;
    struct cx23885_dev *dev;
    struct v4l2_subdev sd;
    int rx_kfifo;
};

#define GFP_KERNEL 0
#define ENOMEM 12
#define CX23888_IR_RX_KFIFO_SIZE 1024
#define CX23885_HW_888_IR 0x888
#define CX23888_IR_IRQEN_REG 0x00

static inline void spin_lock_init(pthread_mutex_t *lock) {
    pthread_mutex_init(lock, NULL);
}

static inline void mutex_init(pthread_mutex_t *lock) {
    pthread_mutex_init(lock, NULL);
}

static inline int v4l2_subdev_call(struct v4l2_subdev *sd, const char *ir, 
                                 const char *func, void *params) {
    (void)sd;
    (void)ir;
    (void)func;
    (void)params;
    return 0;
}

extern const struct v4l2_subdev_ops cx23888_ir_controller_ops;
extern struct v4l2_subdev_ir_parameters default_rx_params;
extern struct v4l2_subdev_ir_parameters default_tx_params;
extern int cx23888_ir_write4(struct cx23885_dev *dev, u32 reg, u32 value);
extern void *kzalloc(size_t size, int flags);
extern int kfifo_alloc(int *fifo, size_t size, int flags);
extern void kfifo_free(int *fifo);
extern void v4l2_subdev_init(struct v4l2_subdev *sd, const struct v4l2_subdev_ops *ops);
extern void v4l2_set_subdevdata(struct v4l2_subdev *sd, void *data);
extern int v4l2_device_register_subdev(struct v4l2_device *v4l2_dev, 
                                     struct v4l2_subdev *sd);

static const char ir[] = IR_SUBDEV_NAME;
static const char rx_s_parameters[] = RX_S_PARAMETERS;
static const char tx_s_parameters[] = TX_S_PARAMETERS;