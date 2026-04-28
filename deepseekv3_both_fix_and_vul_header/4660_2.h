#include <stddef.h>
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_USED_MAPS 64
#define BPF_CLASS(code) ((code) & 0x07)
#define BPF_MODE(code) ((code) & 0xe0)
#define BPF_LD 0x00
#define BPF_IMM 0x00
#define BPF_DW 0x18
#define BPF_LDX 0x01
#define BPF_MEM 0x60
#define BPF_STX 0x02
#define BPF_XADD 0xc0
#define BPF_PSEUDO_MAP_FD 1
#define EINVAL 22
#define E2BIG 7

typedef uint32_t u32;
typedef uint64_t u64;

struct verifier_env {
    struct bpf_prog *prog;
    struct bpf_map *used_maps[MAX_USED_MAPS];
    unsigned int used_map_cnt;
};

struct bpf_prog {
    struct bpf_insn *insnsi;
    unsigned int len;
};

struct bpf_insn {
    uint8_t code;
    uint8_t dst_reg;
    uint8_t src_reg;
    int16_t off;
    int32_t imm;
};

struct bpf_map;
struct fd {
    int fd;
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

static inline struct bpf_map *__bpf_map_get(struct fd f) { return NULL; }
static inline struct bpf_map *bpf_map_inc(struct bpf_map *map, bool uref) { return map; }
static inline void fdput(struct fd f) {}
static inline struct fd fdget(int fd) { struct fd f = {fd}; return f; }
static inline void verbose(const char *fmt, ...) {}