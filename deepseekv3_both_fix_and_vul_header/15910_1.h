#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define LOG_ERR 0
#define LOG_NOTICE 0
#define LOG_INFO 0
#define IPMI_NETFN_STORAGE 0
#define GET_FRU_DATA 0
#define LIMIT_ALL_REQUEST_SIZE
#define FRU_BLOCK_SZ 0

struct ipmi_rs {
    int ccode;
    uint8_t *data;
    int data_len;
};

struct ipmi_rq {
    struct {
        int netfn;
        int cmd;
        uint8_t *data;
        int data_len;
    } msg;
};

struct fru_info {
    uint32_t size;
    int access;
};

struct ipmi_intf {
    struct ipmi_rs *(*sendrecv)(struct ipmi_intf *, struct ipmi_rq *);
};

int lprintf(int level, const char *format, ...);
int fru_cc_rq2big(int ccode);
const char *val2str(int val, const void *list);
extern const void *completion_code_vals;