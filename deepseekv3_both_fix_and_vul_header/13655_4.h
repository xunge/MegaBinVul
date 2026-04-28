#include <stdint.h>
#include <stddef.h>
#include <math.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uint64_t dma_addr_t;
typedef uint64_t __be64;

struct mlx5_cqe64 {
    u8 op_own;
};

struct mlx5_uar {
    u32 index;
};

struct mlx5_cq {
    u32 cqn;
    int cqe_sz;
    u32 *set_ci_db;
    u32 *arm_db;
    int vector;
    void (*comp)(struct mlx5_cq *);
    void (*event)(struct mlx5_cq *, int);
    unsigned int irqn;
    struct mlx5_uar *uar;
};

struct mlx5_cqwq_ctrl {
    struct {
        int npages;
        int page_shift;
        dma_addr_t dma;
    } buf;
    struct {
        dma_addr_t dma;
        u32 *db;
    } db;
};

struct mlx5_cqwq {
    int size;
};

struct mlx5_wq_param {
    int buf_numa_node;
    int db_numa_node;
};

struct mlx5_fpga_conn_res {
    struct mlx5_uar *uar;
};

struct mlx5_fpga_conn {
    struct mlx5_fpga_device *fdev;
    struct {
        struct mlx5_cqwq wq;
        struct mlx5_cqwq_ctrl wq_ctrl;
        struct mlx5_cq mcq;
        struct {
            void (*func)(unsigned long);
            unsigned long data;
        } tasklet;
    } cq;
    struct mlx5_fpga_conn_res conn_res;
};

struct mlx5_fpga_device {
    struct mlx5_core_dev *mdev;
    struct mlx5_fpga_conn_res conn_res;
};

struct mlx5_core_dev {
    struct {
        int numa_node;
    } priv;
};

struct cqc {
    u32 log_cq_size;
    u32 c_eqn;
    u32 uar_page;
    u32 log_page_size;
    u64 dbr_addr;
};

struct create_cq_in {
    struct cqc cq_context;
    u64 pas[0];
};

struct create_cq_out {
    u32 cqn;
};

#define MLX5_ST_SZ_DW(t) (sizeof(struct t)/sizeof(uint32_t))
#define MLX5_ST_SZ_BYTES(t) sizeof(struct t)
#define MLX5_ADDR_OF(t, f, m) ((void *)(f) + offsetof(struct t, m))
#define MLX5_SET(t, f, m, v) do { *(uint32_t *)(MLX5_ADDR_OF(t, f, m)) = (v); } while (0)
#define MLX5_SET64(t, f, m, v) do { *(uint64_t *)(MLX5_ADDR_OF(t, f, m)) = (v); } while (0)

#define MLX5_CQE_INVALID 0x0
#define MLX5_CQE_OWNER_MASK 0x1
#define MLX5_ADAPTER_PAGE_SHIFT 12
#define ENOMEM 12
#define GFP_KERNEL 0

static inline int ilog2(int n) {
    return (int)log2(n);
}

static inline int roundup_pow_of_two(int n) {
    return 1 << (ilog2(n - 1) + 1);
}

static inline void *kvzalloc(size_t size, int flags) {
    return NULL;
}

static inline void kvfree(void *addr) {}

static inline int mlx5_cqwq_create(struct mlx5_core_dev *mdev, struct mlx5_wq_param *wqp,
                                  u32 *temp_cqc, struct mlx5_cqwq *wq,
                                  struct mlx5_cqwq_ctrl *wq_ctrl) {
    return 0;
}

static inline int mlx5_cqwq_get_size(struct mlx5_cqwq *wq) {
    return 0;
}

static inline struct mlx5_cqe64 *mlx5_cqwq_get_wqe(struct mlx5_cqwq *wq, int i) {
    return NULL;
}

static inline int mlx5_vector2eqn(struct mlx5_core_dev *mdev, int cpu, int *eqn, unsigned int *irqn) {
    return 0;
}

static inline void mlx5_fill_page_frag_array(struct mlx5_cqwq_ctrl *wq_ctrl, __be64 *pas) {}

static inline int mlx5_core_create_cq(struct mlx5_core_dev *mdev, struct mlx5_cq *mcq,
                                     void *in, int inlen, u32 *out, int outlen) {
    return 0;
}

static inline void tasklet_init(void *tasklet, void *func, unsigned long data) {}

static inline void mlx5_fpga_dbg(struct mlx5_fpga_device *fdev, const char *fmt, ...) {}

static inline void mlx5_wq_destroy(struct mlx5_cqwq_ctrl *wq_ctrl) {}

static inline int smp_processor_id() {
    return 0;
}

static void mlx5_fpga_conn_cq_complete(struct mlx5_cq *mcq) {}
static void mlx5_fpga_conn_cq_event(struct mlx5_cq *mcq, int event) {}
static void mlx5_fpga_conn_cq_tasklet(unsigned long data) {}