#include <linux/errno.h>
#include <linux/types.h>

struct mlx5_core_dev;

struct mlx5dr_caps {
    unsigned int sw_format_ver;
};

struct mlx5dr_domain {
    struct {
        struct mlx5dr_caps caps;
    } info;
    struct mlx5_core_dev *mdev;
    void *ste_ctx;
    unsigned int pdn;
    void *uar;
    void *ste_icm_pool;
    void *action_icm_pool;
};

enum {
    DR_ICM_TYPE_STE,
    DR_ICM_TYPE_MODIFY_ACTION
};

int mlx5_core_alloc_pd(struct mlx5_core_dev *dev, unsigned int *pdn);
void mlx5_core_dealloc_pd(struct mlx5_core_dev *dev, unsigned int pdn);
void *mlx5_get_uars_page(struct mlx5_core_dev *dev);
void mlx5_put_uars_page(struct mlx5_core_dev *dev, void *uar);
void *mlx5dr_ste_get_ctx(unsigned int sw_format_ver);
void *mlx5dr_icm_pool_create(struct mlx5dr_domain *dmn, int type);
void mlx5dr_icm_pool_destroy(void *pool);
int mlx5dr_send_ring_alloc(struct mlx5dr_domain *dmn);
void mlx5dr_err(struct mlx5dr_domain *dmn, const char *fmt, ...);