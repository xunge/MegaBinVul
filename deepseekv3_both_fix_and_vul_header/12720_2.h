#include <stdbool.h>
#include <stdint.h>

typedef uint32_t u32;
typedef uint8_t u8;

#define MAX_BPF_STACK 0
#define REASON_BOUNDS 0
#define REASON_TYPE 0
#define REASON_LIMIT 0

struct tnum {
    u32 value;
};

int tnum_is_const(struct tnum var_off);

struct bpf_reg_state {
    long smin_value;
    long smax_value;
    struct tnum var_off;
    int off;
    int type;
    u32 umax_value;
    struct {
        u32 value_size;
    } *map_ptr;
};

#define BPF_ADD 0
#define BPF_SUB 1

#define PTR_TO_STACK 1
#define PTR_TO_MAP_VALUE 2