#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef int16_t s16;
typedef int32_t s32;
typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;

#define BPF_CAST_CALL(x) ((unsigned long)(x))
#define __bpf_call_base 0
#define BPF_REG_AX 0
#define BPF_REG_3 3
#define BPF_PSEUDO_CALL 1
#define BPF_FUNC_get_route_realm 0
#define BPF_FUNC_get_prandom_u32 0
#define BPF_FUNC_override_return 0
#define BPF_FUNC_tail_call 0
#define BPF_FUNC_map_lookup_elem 0
#define BPF_FUNC_map_update_elem 1
#define BPF_FUNC_map_delete_elem 2
#define BPF_FUNC_map_push_elem 3
#define BPF_FUNC_map_pop_elem 4
#define BPF_FUNC_map_peek_elem 5
#define MAX_BPF_STACK 0
#define MAX_PACKET_OFF 0
#define BPF_ALU_NEG_VALUE 0
#define BPF_ALU_SANITIZE_SRC 0
#define BPF_ALU_SANITIZE 0
#define BPF_TAIL_CALL 0
#define BPF_JNE 0
#define BPF_JEQ 0
#define BPF_JA 0
#define BPF_JGE 0
#define BPF_ALU64 0
#define BPF_ALU 0
#define BPF_MOD 0
#define BPF_DIV 0
#define BPF_ADD 0
#define BPF_SUB 0
#define BPF_MUL 0
#define BPF_OR 0
#define BPF_AND 0
#define BPF_XOR 0
#define BPF_NEG 0
#define BPF_ARSH 0
#define BPF_LD 0
#define BPF_ABS 0
#define BPF_IND 0
#define BPF_JMP 0
#define BPF_CALL 0
#define BPF_X 0
#define BPF_CLASS(x) 0
#define BPF_MODE(x) 0
#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))
#define BUILD_BUG_ON(x)
#define __same_type(a, b) 1
#define BITS_PER_LONG 64
#define EINVAL 1
#define ENOMEM 2
#define EFAULT 3

struct bpf_insn {
    u8 code;
    u8 dst_reg;
    u8 src_reg;
    s16 off;
    s32 imm;
};

struct bpf_verifier_env {
    struct bpf_prog *prog;
    struct bpf_verifier_ops *ops;
    struct bpf_insn_aux_data *insn_aux_data;
};

struct bpf_prog {
    struct bpf_insn *insnsi;
    unsigned int len;
    bool dst_needed;
    bool kprobe_override;
    bool cb_access;
    bool jit_requested;
    struct bpf_prog_aux *aux;
};

struct bpf_func_proto {
    void *func;
};

struct bpf_map;
struct bpf_map_ops {
    int (*map_gen_lookup)(struct bpf_map *map, struct bpf_insn *insn_buf);
    void *(*map_lookup_elem)(struct bpf_map *map, void *key);
    int (*map_update_elem)(struct bpf_map *map, void *key, void *value, u64 flags);
    int (*map_delete_elem)(struct bpf_map *map, void *key);
    int (*map_push_elem)(struct bpf_map *map, void *value, u64 flags);
    int (*map_pop_elem)(struct bpf_map *map, void *value);
    int (*map_peek_elem)(struct bpf_map *map, void *value);
};

struct bpf_insn_aux_data {
    u32 alu_state;
    u32 alu_limit;
    void *map_state;
};

struct bpf_map {
    struct bpf_map_ops *ops;
    unsigned int max_entries;
};

struct bpf_array {
    struct bpf_map map;
    unsigned int index_mask;
};

struct bpf_prog_aux {
    unsigned int stack_depth;
    unsigned int max_pkt_offset;
};

struct bpf_verifier_ops {
    int (*gen_ld_abs)(const struct bpf_insn *insn, struct bpf_insn *insn_buf);
    const struct bpf_func_proto *(*get_func_proto)(int func_id, struct bpf_prog *prog);
};

#define BPF_MAP_PTR(x) ((struct bpf_map *)(x))
#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

static inline struct bpf_insn BPF_MOV32_REG(u8 dst, u8 src) {
    return (struct bpf_insn){.code = 0, .dst_reg = dst, .src_reg = src};
}
static inline struct bpf_insn BPF_ALU32_REG(u8 op, u8 dst, u8 src) {
    return (struct bpf_insn){.code = 0, .dst_reg = dst, .src_reg = src};
}
static inline struct bpf_insn BPF_JMP_IMM(u8 op, u8 dst, s32 imm, s16 off) {
    return (struct bpf_insn){.code = 0, .dst_reg = dst, .imm = imm, .off = off};
}
static inline struct bpf_insn BPF_ALU64_IMM(u8 op, u8 dst, s32 imm) {
    return (struct bpf_insn){.code = 0, .dst_reg = dst, .imm = imm};
}
static inline struct bpf_insn BPF_MOV32_IMM(u8 dst, s32 imm) {
    return (struct bpf_insn){.code = 0, .dst_reg = dst, .imm = imm};
}
static inline struct bpf_insn BPF_ALU64_REG(u8 op, u8 dst, u8 src) {
    return (struct bpf_insn){.code = 0, .dst_reg = dst, .src_reg = src};
}
static inline struct bpf_insn BPF_ALU32_IMM(u8 op, u8 dst, s32 imm) {
    return (struct bpf_insn){.code = 0, .dst_reg = dst, .imm = imm};
}

static inline int bpf_map_ptr_unpriv(struct bpf_insn_aux_data *aux) { return 0; }
static inline int bpf_map_ptr_poisoned(struct bpf_insn_aux_data *aux) { return 0; }
static inline void bpf_user_rnd_init_once(void) {}
static inline void verbose(struct bpf_verifier_env *env, const char *fmt, ...) {}
static inline const char *func_id_name(int id) { return ""; }
static inline struct bpf_prog *bpf_patch_insn_data(struct bpf_verifier_env *env, int i, struct bpf_insn *patchlet, int cnt) { return NULL; }