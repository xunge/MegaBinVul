#include <stdint.h>
#include <stdlib.h>

#define MLX5_CR_DUMP_CHUNK_SIZE 256
#define GFP_KERNEL 0
#define EPERM 1
#define ENOMEM 12

typedef uint32_t u32;

struct mlx5_core_dev {
    struct {
        struct {
            u32 crdump_size;
        } health;
    } priv;
};

struct devlink_health_reporter;
struct devlink_fmsg;
struct mlx5_fw_reporter_ctx;

void* kvmalloc(size_t size, int flags);
void kvfree(void* ptr);
int mlx5_core_is_pf(struct mlx5_core_dev* dev);
int mlx5_crdump_collect(struct mlx5_core_dev* dev, u32* cr_data);
int mlx5_fw_reporter_ctx_pairs_put(struct devlink_fmsg* fmsg, struct mlx5_fw_reporter_ctx* ctx);
int devlink_fmsg_arr_pair_nest_start(struct devlink_fmsg* fmsg, const char* name);
int devlink_fmsg_binary_put(struct devlink_fmsg* fmsg, const char* data, u32 size);
int devlink_fmsg_arr_pair_nest_end(struct devlink_fmsg* fmsg);
void* devlink_health_reporter_priv(struct devlink_health_reporter* reporter);