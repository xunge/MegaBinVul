#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/fs.h>
#include <linux/iso_fs.h>

struct inode {
    struct super_block *i_sb;
};

struct super_block {
    void *s_fs_info;
};

struct rock_state {
    unsigned char *chr;
    int len;
    int cont_size;
    int cont_offset;
    int cont_extent;
    void *buffer;
};

struct rock_ridge {
    __u8 len;
    __u8 version;
    union {
        struct {
            __u8 flags;
            char name[0];
        } NM;
        struct {
            __u8 flags[1];
        } RR;
        struct {
            __u32 extent;
            __u32 offset;
            __u32 size;
        } CE;
    } u;
};

#define SIG(a,b) ((a) | ((b) << 8))
#define RR_NM 1
#define EIO 5

struct iso_sb_info {
    unsigned char s_rock;
};

#define ISOFS_SB(sb) ((struct iso_sb_info *)(sb)->s_fs_info)

static inline int isonum_721(unsigned char *p) { return p[0] | (p[1] << 8); }
static inline int isonum_733(unsigned char *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24); }
static inline void init_rock_state(struct rock_state *rs, struct inode *inode) {}
static inline void setup_rock_ridge(struct iso_directory_record *de, struct inode *inode, struct rock_state *rs) {}
static inline int rock_check_overflow(struct rock_state *rs, int sig) { return 0; }
static inline int check_sp(struct rock_ridge *rr, struct inode *inode) { return 0; }
static inline int rock_continue(struct rock_state *rs) { return 0; }
static inline void kfree(void *p) {}