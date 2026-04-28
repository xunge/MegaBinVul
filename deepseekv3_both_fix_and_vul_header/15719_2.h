#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef uint32_t u32;
typedef uint64_t u64;

enum bpf_access_type {
    BPF_READ,
    BPF_WRITE
};

enum bpf_reg_type {
    PTR_TO_MAP_KEY,
    PTR_TO_MAP_VALUE,
    PTR_TO_MEM,
    PTR_TO_CTX,
    PTR_TO_STACK,
    PTR_TO_FLOW_KEYS,
    PTR_TO_TP_BUFFER,
    CONST_PTR_TO_MAP,
    PTR_TO_BTF_ID,
    PTR_TO_BUF,
    SCALAR_VALUE,
    NOT_INIT
};

#define EACCES 13
#define BPF_KPTR 1
#define DEF_NOT_SUBREG 0
#define BPF_REG_SIZE 8
#define ACCESS_DIRECT 1

struct tnum {
    u64 value;
    u64 mask;
};

struct bpf_verifier_env {
    struct bpf_prog *prog;
    unsigned int id_gen;
};

struct bpf_prog {
    struct bpf_prog_aux *aux;
};

struct bpf_prog_aux {
    u32 max_rdonly_access;
    u32 max_rdwr_access;
};

struct bpf_reg_state {
    enum bpf_reg_type type;
    int off;
    struct bpf_map *map_ptr;
    int mem_size;
    struct btf_record *record;
    struct tnum var_off;
    int id;
    int subreg_def;
    struct btf *btf;
    u32 btf_id;
};

struct bpf_map {
    u32 key_size;
    struct btf_record *record;
    bool is_rdonly;
    struct bpf_map_ops *ops;
};

struct btf_record {
    // placeholder
};

struct btf {
    // placeholder
};

struct bpf_map_ops {
    bool (*map_direct_value_addr)(struct bpf_map *map);
    int (*map_direct_read)(struct bpf_map *map, int map_off, int size, u64 *val, bool is_ldsx);
};

struct bpf_func_state {
    // placeholder
};

struct btf_field {
    // placeholder
};

static struct bpf_reg_state *cur_regs(struct bpf_verifier_env *env);
static void verbose(struct bpf_verifier_env *env, const char *fmt, ...);
static int check_mem_region_access(struct bpf_verifier_env *env, int regno, int off, int size, int key_size, bool zero);
static void mark_reg_unknown(struct bpf_verifier_env *env, struct bpf_reg_state *regs, int value_regno);
static int check_ptr_alignment(struct bpf_verifier_env *env, struct bpf_reg_state *reg, int off, int size, bool strict_alignment_once);
static bool is_pointer_value(struct bpf_verifier_env *env, int value_regno);
static int check_map_access_type(struct bpf_verifier_env *env, int regno, int off, int size, enum bpf_access_type t);
static int check_map_access(struct bpf_verifier_env *env, int regno, int off, int size, bool zero, int access_type);
static bool tnum_is_const(struct tnum var_off);
static struct btf_field *btf_record_find(struct btf_record *record, int value, int type);
static int check_map_kptr_access(struct bpf_verifier_env *env, int regno, int value_regno, int insn_idx, struct btf_field *kptr_field);
static bool bpf_map_is_rdonly(struct bpf_map *map);
static int bpf_map_direct_read(struct bpf_map *map, int map_off, int size, u64 *val, bool is_ldsx);
static void __mark_reg_known(struct bpf_reg_state *reg, u64 val);
static bool type_is_rdonly_mem(enum bpf_reg_type type);
static bool type_may_be_null(enum bpf_reg_type type);
static const char *reg_type_str(struct bpf_verifier_env *env, enum bpf_reg_type type);
static int check_ptr_off_reg(struct bpf_verifier_env *env, struct bpf_reg_state *reg, int regno);
static int check_ctx_access(struct bpf_verifier_env *env, int insn_idx, int off, int size, enum bpf_access_type t, enum bpf_reg_type *reg_type, struct btf **btf, u32 *btf_id);
static void verbose_linfo(struct bpf_verifier_env *env, int insn_idx, const char *str);
static void mark_reg_known_zero(struct bpf_verifier_env *env, struct bpf_reg_state *regs, int value_regno);
static int check_stack_access_within_bounds(struct bpf_verifier_env *env, int regno, int off, int size, int access_type, enum bpf_access_type t);
static struct bpf_func_state *func(struct bpf_verifier_env *env, struct bpf_reg_state *reg);
static int update_stack_depth(struct bpf_verifier_env *env, struct bpf_func_state *state, int off);
static int check_stack_read(struct bpf_verifier_env *env, int regno, int off, int size, int value_regno);
static int check_stack_write(struct bpf_verifier_env *env, int regno, int off, int size, int value_regno, int insn_idx);
static bool reg_is_pkt_pointer(struct bpf_reg_state *reg);
static bool may_access_direct_pkt_data(struct bpf_verifier_env *env, void *null, enum bpf_access_type t);
static int check_packet_access(struct bpf_verifier_env *env, int regno, int off, int size, bool zero);
static int check_flow_keys_access(struct bpf_verifier_env *env, int off, int size);
static bool type_is_sk_pointer(enum bpf_reg_type type);
static int check_sock_access(struct bpf_verifier_env *env, int insn_idx, int regno, int off, int size, enum bpf_access_type t);
static int check_tp_buffer_access(struct bpf_verifier_env *env, struct bpf_reg_state *reg, int regno, int off, int size);
static int check_ptr_to_btf_access(struct bpf_verifier_env *env, struct bpf_reg_state *regs, int regno, int off, int size, enum bpf_access_type t, int value_regno);
static int check_ptr_to_map_access(struct bpf_verifier_env *env, struct bpf_reg_state *regs, int regno, int off, int size, enum bpf_access_type t, int value_regno);
static int check_buffer_access(struct bpf_verifier_env *env, struct bpf_reg_state *reg, int regno, int off, int size, bool zero, u32 *max_access);
static void coerce_reg_to_size(struct bpf_reg_state *reg, int size);
static void coerce_reg_to_size_sx(struct bpf_reg_state *reg, int size);
static int bpf_size_to_bytes(int bpf_size);
static enum bpf_reg_type base_type(enum bpf_reg_type type);