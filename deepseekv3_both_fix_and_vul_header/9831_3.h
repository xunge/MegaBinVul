#include <stdint.h>
#include <stddef.h>
#include <limits.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

#define BPF_S_ALU_ADD_X   0x00
#define BPF_S_ALU_ADD_K   0x01
#define BPF_S_ALU_SUB_X   0x02
#define BPF_S_ALU_SUB_K   0x03
#define BPF_S_ALU_MUL_X   0x04
#define BPF_S_ALU_MUL_K   0x05
#define BPF_S_ALU_DIV_X   0x06
#define BPF_S_ALU_DIV_K   0x07
#define BPF_S_ALU_AND_X   0x08
#define BPF_S_ALU_AND_K   0x09
#define BPF_S_ALU_OR_X    0x0A
#define BPF_S_ALU_OR_K    0x0B
#define BPF_S_ALU_LSH_X   0x0C
#define BPF_S_ALU_LSH_K   0x0D
#define BPF_S_ALU_RSH_X   0x0E
#define BPF_S_ALU_RSH_K   0x0F
#define BPF_S_ALU_NEG     0x10
#define BPF_S_JMP_JA      0x11
#define BPF_S_JMP_JGT_K   0x12
#define BPF_S_JMP_JGE_K   0x13
#define BPF_S_JMP_JEQ_K   0x14
#define BPF_S_JMP_JSET_K  0x15
#define BPF_S_JMP_JGT_X   0x16
#define BPF_S_JMP_JGE_X   0x17
#define BPF_S_JMP_JEQ_X   0x18
#define BPF_S_JMP_JSET_X  0x19
#define BPF_S_LD_W_ABS    0x20
#define BPF_S_LD_H_ABS    0x21
#define BPF_S_LD_B_ABS    0x22
#define BPF_S_LD_W_LEN    0x23
#define BPF_S_LDX_W_LEN   0x24
#define BPF_S_LD_W_IND    0x25
#define BPF_S_LD_H_IND    0x26
#define BPF_S_LD_B_IND    0x27
#define BPF_S_LDX_B_MSH   0x28
#define BPF_S_LD_IMM      0x29
#define BPF_S_LDX_IMM     0x2A
#define BPF_S_LD_MEM      0x2B
#define BPF_S_LDX_MEM     0x2C
#define BPF_S_MISC_TAX    0x2D
#define BPF_S_MISC_TXA    0x2E
#define BPF_S_RET_K       0x30
#define BPF_S_RET_A       0x31
#define BPF_S_ST          0x32
#define BPF_S_STX         0x33

struct sock_filter {
    u16 code;
    u8 jt;
    u8 jf;
    u32 k;
};

struct net_device {
    int ifindex;
    unsigned short type;
};

struct sk_buff {
    unsigned int len;
    u16 protocol;
    u8 pkt_type;
    struct net_device *dev;
    unsigned int mark;
    unsigned int queue_mapping;
    unsigned char *data;
    int nonlinear;
};

struct nlattr {
    u16 nla_len;
    u16 nla_type;
};

#define BPF_MEMWORDS 16
#define BITS_PER_LONG (CHAR_BIT * sizeof(long))
#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))

#define SKF_AD_OFF (-0x1000)
#define SKF_AD_PROTOCOL 0
#define SKF_AD_PKTTYPE 4
#define SKF_AD_IFINDEX 8
#define SKF_AD_MARK 16
#define SKF_AD_QUEUE 20
#define SKF_AD_HATYPE 28
#define SKF_AD_NLATTR 24
#define SKF_AD_NLATTR_NEST 32

static inline void *load_pointer(struct sk_buff *skb, int k, int size, u32 *tmp) {
    return NULL;
}

static inline u32 get_unaligned_be32(void *ptr) {
    return 0;
}

static inline u16 get_unaligned_be16(void *ptr) {
    return 0;
}

static inline int skb_is_nonlinear(struct sk_buff *skb) {
    return 0;
}

static inline struct nlattr *nla_find(struct nlattr *nla, int len, int attrtype) {
    return NULL;
}

static inline struct nlattr *nla_find_nested(struct nlattr *nla, int attrtype) {
    return NULL;
}

static inline u16 ntohs(u16 val) {
    return ((val & 0xFF) << 8) | ((val >> 8) & 0xFF);
}

#define WARN_ON(condition) ((void)0)