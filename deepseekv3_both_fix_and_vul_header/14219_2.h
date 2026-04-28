#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;
typedef uint8_t u8;

struct hw_atl_utils_fw_rpc {
    u32 len;
};

struct aq_hw_s {
    unsigned int rpc_tid;
    unsigned int rpc_addr;
    struct hw_atl_utils_fw_rpc rpc;
};

struct aq_hw_atl_utils_fw_rpc_tid_s {
    union {
        struct {
            uint16_t tid;
            uint16_t len;
        };
        uint32_t val;
    };
};

#define HW_ATL_RPC_CONTROL_ADR 0
#define EINVAL 22
#define KERN_INFO ""

#define printk printf

static inline uint32_t aq_hw_read_reg(struct aq_hw_s *self, unsigned int addr);
static inline uint32_t hw_atl_utils_rpc_state_get(struct aq_hw_s *self);
static inline int aq_hw_err_from_flags(struct aq_hw_s *self);
static inline int hw_atl_utils_fw_rpc_call(struct aq_hw_s *self, unsigned int len);
static inline int hw_atl_utils_fw_downld_dwords(struct aq_hw_s *self, unsigned int addr, u32 *data, unsigned int len);

#define readx_poll_timeout_atomic(func, arg, val, cond, delay_us, timeout_us) \
({ \
    int __ret = 0; \
    for (unsigned int __i = 0; __i < (timeout_us)/(delay_us); __i++) { \
        (val) = (func)((arg)); \
        if (cond) \
            break; \
        for (volatile unsigned int __j = 0; __j < (delay_us); __j++); \
    } \
    __ret; \
})

static inline uint32_t hw_atl_utils_rpc_state_get(struct aq_hw_s *self)
{
    return aq_hw_read_reg(self, HW_ATL_RPC_CONTROL_ADR);
}

static inline uint32_t aq_hw_read_reg(struct aq_hw_s *self, unsigned int addr)
{
    return 0;
}

static inline int aq_hw_err_from_flags(struct aq_hw_s *self)
{
    return 0;
}

static inline int hw_atl_utils_fw_rpc_call(struct aq_hw_s *self, unsigned int len)
{
    return 0;
}

static inline int hw_atl_utils_fw_downld_dwords(struct aq_hw_s *self, unsigned int addr, u32 *data, unsigned int len)
{
    return 0;
}