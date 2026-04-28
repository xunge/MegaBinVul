#include <stddef.h>
#include <stdint.h>

struct rock_ridge {
    int len;
    union {
        struct {
            unsigned char flags[1];
        } RR;
        struct {
            unsigned char len_id;
            unsigned char data[0];
        } ER;
        struct {
            unsigned int mode;
            unsigned int n_links;
            unsigned int uid;
            unsigned int gid;
        } PX;
        struct {
            unsigned int dev_high;
            unsigned int dev_low;
        } PN;
        struct {
            unsigned char flags;
            struct {
                unsigned char time[7];
            } times[4];
        } TF;
        struct {
            unsigned char flags;
            struct {
                unsigned char len;
                unsigned char flags;
                unsigned char text[0];
            } link;
        } SL;
        struct {
            unsigned int location;
        } CL;
        struct {
            unsigned int extent;
            unsigned int offset;
            unsigned int size;
        } CE;
        struct {
            unsigned char algorithm[2];
            unsigned char parms[2];
            unsigned int real_size;
        } ZF;
    } u;
};

struct SL_component {
    unsigned char flags;
    unsigned char len;
    unsigned char text[0];
};

struct rock_state {
    unsigned char *chr;
    int len;
    unsigned int cont_extent;
    unsigned int cont_offset;
    unsigned int cont_size;
    void *buffer;
};

struct iso_directory_record {
    unsigned char name_len;
    char name[0];
};

struct iso_super_block {
    unsigned char s_rock;
    unsigned char s_nocompress;
};

struct iso_inode_info {
    unsigned int i_iget5_block;
    unsigned int i_iget5_offset;
    unsigned int i_first_extent;
    unsigned int i_file_format;
    unsigned int i_format_parm[2];
};

struct inode {
    struct iso_super_block *i_sb;
    unsigned int i_mode;
    unsigned int i_nlink;
    unsigned int i_uid;
    unsigned int i_gid;
    unsigned int i_rdev;
    long i_size;
    unsigned long i_blocks;
    struct {
        long tv_sec;
        long tv_nsec;
    } i_atime, i_mtime, i_ctime;
    struct iso_inode_info *i_private;
};

#define ISOFS_SB(sb) ((struct iso_super_block *)(sb))
#define ISOFS_I(inode) ((struct iso_inode_info *)(inode->i_private))
#define SIG(a,b) ((a) | ((b) << 8))
#define RR_PX 1
#define RR_TF 2
#define RR_SL 4
#define RR_CL 8
#define TF_CREATE 1
#define TF_MODIFY 2
#define TF_ACCESS 4
#define TF_ATTRIBUTES 8
#define RR_REGARD_XA 1
#define RR_RELOC_DE 2
#define CONFIG_ZISOFS 0
#define EIO 5
#define isofs_file_compressed 1
#define KERN_DEBUG ""
#define KERN_WARNING ""
#define KERN_ERR ""
#define printk(...)
#define MKDEV(ma,mi) ((ma)<<8 | (mi))
#define PTR_ERR(ptr) ((long)(ptr))
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)(-1000))

static void kfree(void *ptr) { }
static void init_rock_state(struct rock_state *rs, struct inode *inode) {}
static void setup_rock_ridge(struct iso_directory_record *de, struct inode *inode, struct rock_state *rs) {}
static int isonum_721(unsigned char *p) { return 0; }
static int rock_check_overflow(struct rock_state *rs, int sig) { return 0; }
static int check_sp(struct rock_ridge *rr, struct inode *inode) { return 0; }
static int isonum_733(unsigned int n) { return n; }
static int isonum_711(unsigned char *p) { return *p; }
static long iso_date(unsigned char *p, int flag) { return 0; }
static void set_nlink(struct inode *inode, unsigned int nlink) {}
static void i_uid_write(struct inode *inode, unsigned int uid) {}
static void i_gid_write(struct inode *inode, unsigned int gid) {}
static int rock_continue(struct rock_state *rs) { return 0; }
static struct inode *isofs_iget_reloc(struct iso_super_block *sb, unsigned int block, int flag) { return NULL; }
static void iput(struct inode *inode) {}