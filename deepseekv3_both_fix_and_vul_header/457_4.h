#include <stdint.h>
#include <pthread.h>
#include <byteswap.h>

typedef uint8_t u8;
typedef uint64_t u64;

struct mlx4_mac_table {
    u64 entries[128];
    int refs[128];
    int total;
    int max;
    pthread_mutex_t mutex;
};

struct mlx4_dev;
struct mlx4_priv {
    struct {
        struct mlx4_mac_table mac_table;
    } port[8];
};

#define mutex_lock pthread_mutex_lock
#define mutex_unlock pthread_mutex_unlock
#define unlikely(x) (x)

#define MLX4_MAX_MAC_NUM 128
#define MLX4_MAC_MASK 0xffffffffffffULL
#define MLX4_MAC_VALID 0x1000000000000ULL
#define ENOMEM (-12)
#define ENOSPC (-28)

#define be64_to_cpu bswap_64
#define cpu_to_be64 bswap_64

static inline struct mlx4_priv *mlx4_priv(struct mlx4_dev *dev) { return (struct mlx4_priv *)dev; }

void mlx4_dbg(struct mlx4_dev *dev, const char *fmt, ...);
void mlx4_err(struct mlx4_dev *dev, const char *fmt, ...);
int mlx4_set_port_mac_table(struct mlx4_dev *dev, u8 port, u64 *entries);