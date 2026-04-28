#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define LOG_ERR 0
#define LOG_NOTICE 0
#define LOG_ERROR 0
#define LOG_INFO 0

#define IPMI_NETFN_STORAGE 0
#define GET_FRU_DATA 0
#define FRU_BLOCK_SZ 0
#define FRU_AREA_MAXIMUM_BLOCK_SZ 0

struct ipmi_rs {
    uint8_t ccode;
    uint8_t *data;
    uint16_t data_len;
};

struct ipmi_rq {
    struct {
        uint8_t netfn;
        uint8_t cmd;
        uint8_t *data;
        uint16_t data_len;
    } msg;
};

struct ipmi_intf {
    struct ipmi_rs *(*sendrecv)(struct ipmi_intf *intf, struct ipmi_rq *req);
};

struct fru_info {
    uint32_t size;
    uint32_t max_read_size;
    int access;
};

static const char *completion_code_vals[] = {NULL};

void lprintf(int level, const char *fmt, ...);
int fru_cc_rq2big(uint8_t ccode);
const char *val2str(uint8_t val, const void *list);
uint16_t ipmi_intf_get_max_response_data_size(struct ipmi_intf *intf);