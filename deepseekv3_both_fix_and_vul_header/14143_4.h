#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#define LANE_COUNT_ONE 1
#define LANE_COUNT_TWO 2
#define LANE_COUNT_FOUR 4

#define LINK_RATE_LOW 0
#define LINK_RATE_HIGH 1
#define LINK_RATE_RBR2 2
#define LINK_RATE_HIGH2 3
#define LINK_RATE_HIGH3 4

#define GFP_KERNEL 0
#define EINVAL 22
#define ENOSPC 28

typedef long ssize_t;
#define __user

struct file {
    struct inode *f_inode;
};

struct inode {
    void *i_private;
};

struct dc_link_settings {
    int link_spread;
    bool use_link_rate_set;
    int lane_count;
    int link_rate;
};

struct amdgpu_dm_connector {
    struct dc_link *dc_link;
};

struct dc_link {
    void *dc;
    struct dc_link_settings cur_link_settings;
};

struct dc {
    // DC core structure
};

void* kcalloc(size_t n, size_t size, int flags);
void kfree(const void *objp);
int parse_write_buffer_into_params(char *wr_buf, size_t size, long *param, const char *buf, int max_param_num, uint8_t *param_nums);
void dc_link_set_preferred_training_settings(struct dc *dc, struct dc_link_settings *prefer_link_settings, void *dsc_config, struct dc_link *link, bool skip_immediate_retrain);

static inline struct inode *file_inode(struct file *f) {
    return f->f_inode;
}

#define DRM_DEBUG_DRIVER(fmt, ...)