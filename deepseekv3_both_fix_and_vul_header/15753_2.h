#include <stdio.h>
#include <stdint.h>

#define MLX5E_REPORTER_PER_Q_MAX_LEN 256
#define HZ 1000

typedef uint64_t jiffies_t;

extern jiffies_t jiffies;

static inline unsigned int jiffies_to_usecs(const jiffies_t j)
{
    return (j * 1000000) / HZ;
}

struct mlx5_cqe64 {
    uint32_t cqn;
};

struct mlx5e_txq {
    jiffies_t trans_start;
};

struct mlx5e_cq {
    struct mlx5_cqe64 mcq;
};

struct mlx5e_txqsq {
    struct mlx5e_priv *priv;
    int ch_ix;
    uint32_t sqn;
    struct mlx5e_cq cq;
    uint32_t cc;
    uint32_t pc;
    struct mlx5e_txq *txq;
};

struct mlx5e_priv {
    void *tx_reporter;
};

struct mlx5e_err_ctx {
    void *ctx;
    int (*recover)(void *ctx);
    int (*dump)(void *ctx, struct mlx5e_priv *priv, struct mlx5_cqe64 *cqe);
};

struct mlx5e_tx_timeout_ctx {
    struct mlx5e_txqsq *sq;
    int status;
};

int mlx5e_tx_reporter_timeout_recover(void *ctx);
int mlx5e_tx_reporter_timeout_dump(void *ctx, struct mlx5e_priv *priv, struct mlx5_cqe64 *cqe);
int mlx5e_tx_reporter_dump_sq(void *ctx, struct mlx5e_priv *priv, struct mlx5_cqe64 *cqe);
void mlx5e_health_report(struct mlx5e_priv *priv, void *reporter, const char *err_str, struct mlx5e_err_ctx *err_ctx);