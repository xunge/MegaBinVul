#include <stddef.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>

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
#define MAX_USED_MAPS 64
#define EINVAL 22
#define E2BIG 7

typedef uint32_t u32;
typedef uint64_t u64;

struct bpf_insn {
    unsigned char code;
    unsigned char dst_reg;
    unsigned char src_reg;
    short off;
    int imm;
};

struct bpf_map;
struct verifier_env {
    struct bpf_prog *prog;
    struct bpf_map **used_maps;
    int used_map_cnt;
};

struct bpf_prog {
    struct bpf_insn *insnsi;
    int len;
};

struct fd {
    int fd;
};

struct fd fdget(int fd);
void fdput(struct fd f);
struct bpf_map *__bpf_map_get(struct fd f);
int PTR_ERR(const void *ptr);
int IS_ERR(const void *ptr);
void bpf_map_inc(struct bpf_map *map, bool flag);
void verbose(const char *fmt, ...);