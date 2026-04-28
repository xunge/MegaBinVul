#include <stdint.h>
#include <pthread.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

struct mlx4_vlan_table {
    u32 entries[128];
    int refs[128];
    int total;
    int max;
    pthread_mutex_t mutex;
};

struct mlx4_priv {
    struct {
        struct mlx4_vlan_table vlan_table;
    } port[1];
};

struct mlx4_dev;

#define MLX4_VLAN_REGULAR 0
#define MLX4_MAX_VLAN_NUM 128
#define MLX4_VLAN_MASK 0xfff
#define MLX4_VLAN_VALID (1 << 31)

#define ENOMEM 12
#define ENOSPC 28

static inline struct mlx4_priv *mlx4_priv(struct mlx4_dev *dev) { return (struct mlx4_priv *)dev; }
static inline u32 cpu_to_be32(u32 x) { return x; }
static inline u32 be32_to_cpu(u32 x) { return x; }

int mlx4_set_port_vlan_table(struct mlx4_dev *dev, u8 port, u32 *entries);
void mlx4_warn(struct mlx4_dev *dev, const char *fmt, ...);