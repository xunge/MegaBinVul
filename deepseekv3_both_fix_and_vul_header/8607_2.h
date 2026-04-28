#include <string.h>
#include <stdlib.h>

struct xc2028_ctrl {
    char *fname;
    int max_len;
};

struct xc2028_data {
    int lock;
    struct xc2028_ctrl ctrl;
    char *fname;
    int state;
    struct {
        struct {
            struct {
                void *parent;
            } dev;
        } *adap;
    } i2c_props;
};

struct dvb_frontend {
    struct xc2028_data *tuner_priv;
};

#define GFP_KERNEL 0
#define ENOMEM 12
#define THIS_MODULE 0
#define XC2028_NO_FIRMWARE 0
#define XC2028_NODEV 1
#define XC2028_WAITING_FIRMWARE 2

char firmware_name[256];

void tuner_dbg(const char *fmt, ...);
void tuner_err(const char *fmt, ...);
void free_firmware(struct xc2028_data *priv);
void load_firmware_cb(const void *fw, void *context);
int request_firmware_nowait(int module, int nowait, const char *name, void *device, int gfp, void *context, void (*callback)(const void *, void *));

static inline void mutex_lock(int *lock) { *lock = 1; }
static inline void mutex_unlock(int *lock) { *lock = 0; }
static inline void *kstrdup(const char *s, int gfp) { return strdup(s); }
static inline void kfree(void *p) { free(p); }