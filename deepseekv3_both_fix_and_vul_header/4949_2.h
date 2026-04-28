#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define EIO 5
#define RR_REGARD_XA 1
#define RR_RELOC_DE 2
#define isofs_file_compressed 2

#define KERN_EMERG   ""
#define KERN_ALERT   ""
#define KERN_CRIT    ""
#define KERN_ERR     ""
#define KERN_WARNING ""
#define KERN_NOTICE  ""
#define KERN_INFO    ""
#define KERN_DEBUG   ""

struct iso_directory_record {
    char dummy;
};

struct inode {
    struct super_block *i_sb;
    unsigned int i_mode;
    unsigned int i_nlink;
    unsigned int i_uid;
    unsigned int i_gid;
    unsigned int i_rdev;
    unsigned long i_size;
    unsigned long i_blocks;
    struct timespec i_atime;
    struct timespec i_ctime;
    struct timespec i_mtime;
    void *i_private;
};

struct super_block {
    void *s_fs_info;
};

struct iso_sb_info {
    int s_rock;
    int s_nocompress;
};

struct iso_inode_info {
    unsigned int i_first_extent;
    int i_file_format;
    int i_format_parm[2];
    unsigned int i_iget5_block;
    int i_iget5_offset;
};

struct rock_ridge {
    int len;
    union {
        struct {
            unsigned char flags[1];
        } RR;
        struct {
            unsigned char len_id;
            unsigned char data[1];
        } ER;
        struct {
            unsigned char mode[4];
            unsigned char n_links[4];
            unsigned char uid[4];
            unsigned char gid[4];
        } PX;
        struct {
            unsigned char dev_high[4];
            unsigned char dev_low[4];
        } PN;
        struct {
            unsigned char flags;
            struct {
                unsigned char time[1];
            } times[1];
        } TF;
        struct {
            unsigned char flags;
            struct SL_component {
                unsigned char flags;
                unsigned char len;
                unsigned char text[1];
            } link;
        } SL;
        struct {
            unsigned char location[4];
        } CL;
        struct {
            unsigned char extent[4];
            unsigned char offset[4];
            unsigned char size[4];
        } CE;
        struct {
            unsigned char algorithm[2];
            unsigned char parms[2];
            unsigned char real_size[4];
        } ZF;
    } u;
};

struct rock_state {
    unsigned char *chr;
    int len;
    void *buffer;
    unsigned int cont_extent;
    unsigned int cont_offset;
    unsigned int cont_size;
};

#define ISOFS_SB(sb) ((struct iso_sb_info *)(sb)->s_fs_info)
#define ISOFS_I(inode) ((struct iso_inode_info *)(inode)->i_private)

#define SIG(a,b) ((a) | ((b) << 8))

#define RR_PX 1
#define RR_TF 2
#define RR_SL 4
#define RR_CL 8

#define TF_CREATE 1
#define TF_MODIFY 2
#define TF_ACCESS 4
#define TF_ATTRIBUTES 8

#define MKDEV(ma,mi) ((ma)<<8 | (mi))

#define PTR_ERR(ptr) ((long)(ptr))
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)(-1000))

#define printk printf

static int isonum_721(const unsigned char *p) { return p[0] | (p[1] << 8); }
static int isonum_733(const unsigned char *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24); }
static int isonum_711(const unsigned char *p) { return p[0]; }
static void init_rock_state(struct rock_state *rs, struct inode *inode) {}
static void setup_rock_ridge(struct iso_directory_record *de, struct inode *inode, struct rock_state *rs) {}
static int rock_check_overflow(struct rock_state *rs, int sig) { return 0; }
static int check_sp(struct rock_ridge *rr, struct inode *inode) { return 0; }
static int rock_continue(struct rock_state *rs) { return 0; }
static long iso_date(const unsigned char *p, int flag) { return 0; }
static void set_nlink(struct inode *inode, int nlink) {}
static void i_uid_write(struct inode *inode, int uid) {}
static void i_gid_write(struct inode *inode, int gid) {}
static void iput(struct inode *inode) {}
static void kfree(void *ptr) { free(ptr); }
static struct inode *isofs_iget(struct super_block *sb, unsigned int block, int offset) { return NULL; }
static struct inode *isofs_iget_reloc(struct super_block *sb, unsigned int block, int offset) { return NULL; }