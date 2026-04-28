#include <linux/types.h>
#include <linux/fs.h>
#include <linux/string.h>
#include <linux/errno.h>

struct file {
    void *private_data;
};

struct dvb_device {
    void *priv;
};

struct av7110 {
    void *ci_wbuffer;
    struct {
        int num;
        int type;
    } ci_slot[2];
    int arm_app;
};

typedef struct {
    int slot_num;
    int slot_type;
    int descr_num;
    int descr_type;
} ca_caps_t;

typedef struct {
    int num;
    int type;
} ca_slot_info_t;

typedef struct {
    int num;
    int type;
} ca_descr_info_t;

typedef struct {
    unsigned int index;
    unsigned int parity;
    unsigned char cw[8];
} ca_descr_t;

#define COMTYPE_PIDFILTER 1
#define SetDescr 2
#define FW_CI_LL_SUPPORT(x) (x)
#define CA_RESET 100
#define CA_GET_CAP 101
#define CA_GET_SLOT_INFO 102
#define CA_GET_MSG 103
#define CA_SEND_MSG 104
#define CA_GET_DESCR_INFO 105
#define CA_SET_DESCR 106
#define CA_CI_LINK 1
#define CA_CI 2
#define CA_DESCR 4
#define CA_ECD 8

#define dprintk(level, fmt, arg...) do {} while (0)

int ci_ll_reset(void *wbuffer, struct file *file, unsigned long arg, void *slot);
int av7110_fw_cmd(struct av7110 *av7110, int comtype, int command, int length, ...);