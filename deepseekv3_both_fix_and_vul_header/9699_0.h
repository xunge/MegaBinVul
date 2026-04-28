#include <stdint.h>

struct gfs2_dirent {
    uint16_t de_rec_len;
    uint16_t de_name_len;
};

struct qstr {
    unsigned int len;
};

#define GFS2_DIRENT_SIZE(len) ((len) + sizeof(struct gfs2_dirent))
#define be16_to_cpu(x) (x)
static inline int gfs2_dirent_sentinel(const struct gfs2_dirent *dent) { return 0; }