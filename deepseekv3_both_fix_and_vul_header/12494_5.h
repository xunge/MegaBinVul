#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <linux/types.h>
#include <linux/bpf.h>
#include <linux/filter.h>
#include <linux/errno.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;

#define BPF_CAST_CALL(x) ((void *)(x))
#define __bpf_call_base ((void *)0)
#define BPF_POKE_REASON_TAIL_CALL 0
#define BPF_PSEUDO_CALL 1
#define BPF_PSEUDO_KFUNC_CALL 2
#define MAX_BPF_STACK 512
#define MAX_PACKET_OFF 0xffff
#define BPF_REG_AX MAX_BPF_REG
#define BPF_ALU_NON_POINTER 0
#define BPF_ALU_NEG_VALUE (1 << 0)
#define BPF_ALU_SANITIZE (1 << 1)
#define BPF_ALU_SANITIZE_SRC (BPF_ALU_SANITIZE | 0x2)
#define BPF_ALU_IMMEDIATE (1 << 2)
#define BPF_TAIL_CALL 0x20
#define BITS_PER_LONG (__SIZEOF_LONG__ * 8)

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#define __same_type(a, b) __builtin_types_compatible_p(typeof(a), typeof(b))

struct bpf_verifier_env {
    struct bpf_prog *prog;
    const struct bpf_verifier_ops *ops;
    struct bpf_insn_aux_data *insn_aux_data;
    bool bpf_capable;
};

struct bpf_prog {
    struct bpf_insn *insnsi;
    unsigned int len;
    struct bpf_prog_aux *aux;
    bool jit_requested;
    bool dst_needed;
    bool kprobe_override;
    bool cb_access;
};

struct bpf_prog_aux {
    unsigned int stack_depth;
    unsigned int max_pkt_offset;
    struct bpf_jit_poke_descriptor *poke_tab;
    unsigned int size_poke_tab;
};

struct bpf_map {
    const struct bpf_map_ops *ops;
    unsigned int max_entries;
};

struct bpf_array {
    struct bpf_map map;
    unsigned int index_mask;
};

struct bpf_func_proto {
    void *func;
};

struct bpf_map_ops {
    int (*map_gen_lookup)(struct bpf_map *map, struct bpf_insn *insn_buf);
    void *(*map_lookup_elem)(struct bpf_map *map, void *key);
    int (*map_update_elem)(struct bpf_map *map, void *key, void *value, u64 flags);
    int (*map_delete_elem)(struct bpf_map *map, void *key);
    int (*map_push_elem)(struct bpf_map *map, void *value, u64 flags);
    int (*map_pop_elem)(struct bpf_map *map, void *value);
    int (*map_peek_elem)(struct bpf_map *map, void *value);
    int (*map_redirect)(struct bpf_map *map, u32 ifindex, u64 flags);
    int (*map_poke_track)(struct bpf_map *map, struct bpf_prog_aux *aux);
    int (*map_poke_untrack)(struct bpf_map *map, struct bpf_prog_aux *aux);
    int (*map_poke_run)(struct bpf_map *map, struct bpf_prog_aux *aux);
};

struct bpf_insn_aux_data {
    unsigned long map_ptr_state;
    unsigned long alu_state;
    unsigned long alu_limit;
};

struct bpf_jit_poke_descriptor {
    int reason;
    struct {
        void *map;
        unsigned long key;
    } tail_call;
    unsigned int insn_idx;
};

struct bpf_verifier_ops {
    int (*gen_ld_abs)(const struct bpf_insn *insn, struct bpf_insn *insn_buf);
    const struct bpf_func_proto *(*get_func_proto)(int func_id, struct bpf_prog *prog);
};

extern unsigned long jiffies;
extern bool bpf_jit_blinding_enabled(struct bpf_prog *prog);
extern struct bpf_prog *bpf_patch_insn_data(struct bpf_verifier_env *env, int off,
                              struct bpf_insn *patch, int len);
extern void bpf_user_rnd_init_once(void);
extern int bpf_jit_add_poke_descriptor(struct bpf_prog *prog,
                                      struct bpf_jit_poke_descriptor *desc);
extern bool bpf_map_key_poisoned(struct bpf_insn_aux_data *aux);
extern bool bpf_map_ptr_poisoned(struct bpf_insn_aux_data *aux);
extern bool bpf_map_ptr_unpriv(struct bpf_insn_aux_data *aux);
extern void *BPF_MAP_PTR(unsigned long ptr_state);
extern unsigned long bpf_map_key_immediate(struct bpf_insn_aux_data *aux);
extern bool allow_tail_call_in_subprogs(struct bpf_verifier_env *env);
extern const char *func_id_name(int id);
extern int fixup_kfunc_call(struct bpf_verifier_env *env, struct bpf_insn *insn);
extern void sort_kfunc_descs_by_imm(struct bpf_prog *prog);
extern void verbose(struct bpf_verifier_env *env, const char *fmt, ...);

#define BPF_RAW_INSN(code, dst, src, off, imm) \
    ((struct bpf_insn) { code, dst, src, off, imm })
#define BPF_ALU32_REG(op, dst, src) \
    BPF_RAW_INSN(BPF_ALU | BPF_OP(op) | BPF_X, dst, src, 0, 0)
#define BPF_JMP_IMM(op, dst, src, off) \
    BPF_RAW_INSN(BPF_JMP | BPF_OP(op) | BPF_K, dst, src, off, 0)
#define BPF_MOV32_REG(dst, src) \
    BPF_RAW_INSN(BPF_ALU | BPF_MOV | BPF_X, dst, src, 0, 0)
#define BPF_MOV32_IMM(dst, imm) \
    BPF_RAW_INSN(BPF_ALU | BPF_MOV | BPF_K, dst, 0, 0, imm)
#define BPF_ALU64_IMM(op, dst, imm) \
    BPF_RAW_INSN(BPF_ALU64 | BPF_OP(op) | BPF_K, dst, 0, 0, imm)
#define BPF_ALU64_REG(op, dst, src) \
    BPF_RAW_INSN(BPF_ALU64 | BPF_OP(op) | BPF_X, dst, src, 0, 0)
#define BPF_MOV64_REG(dst, src) \
    BPF_RAW_INSN(BPF_ALU64 | BPF_MOV | BPF_X, dst, src, 0, 0)
#define BPF_ALU32_IMM(op, dst, imm) \
    BPF_RAW_INSN(BPF_ALU | BPF_OP(op) | BPF_K, dst, 0, 0, imm)
#define BPF_LD_IMM64(dst, imm) \
    BPF_RAW_INSN(BPF_LD | BPF_DW | BPF_IMM, dst, 0, 0, (imm) >> 32), \
    BPF_RAW_INSN(0, 0, 0, 0, (imm) & 0xFFFFFFFF)
#define BPF_LDX_MEM(size, dst, src, off) \
    BPF_RAW_INSN(BPF_LDX | BPF_SIZE(size) | BPF_MEM, dst, src, off, 0)