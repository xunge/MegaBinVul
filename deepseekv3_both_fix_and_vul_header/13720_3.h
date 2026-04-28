#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

#define CON_BUF_SIZE 4096
#define HEADER_SIZE 4
#define GFP_KERNEL 0
#define EOPNOTSUPP 95
#define ENOMEM 12  
#define ENXIO 6
#define EINVAL 22
#define EFAULT 14

typedef int16_t loff_t;
typedef uint16_t u16;

struct file {
    void *f_inode;
};
struct inode;
struct vc_data {
    int vc_cols;
};

#define __user

static inline struct inode *file_inode(struct file *file) { return file->f_inode; }
static inline int use_unicode(struct inode *inode) { return 0; }
static inline void *__get_free_page(int flags) { return NULL; }
static inline void console_lock(void) {}
static inline void console_unlock(void) {}
static inline long use_attributes(struct inode *inode) { return 0; }
static inline struct vc_data *vcs_vc(struct inode *inode, int *viewed) { return NULL; }
static inline long vcs_size(struct inode *inode) { return 0; }
static inline size_t copy_from_user(void *to, const void *from, size_t n) { return 0; }
static inline uint16_t vcs_scr_readw(struct vc_data *vc, uint16_t *org) { return 0; }
static inline void vcs_scr_writew(struct vc_data *vc, uint16_t val, uint16_t *org) {}
static inline uint16_t *screen_pos(struct vc_data *vc, long p, int viewed) { return NULL; }
static inline void getconsxy(struct vc_data *vc, char *xy) {}
static inline void putconsxy(struct vc_data *vc, char *xy) {}
static inline void update_region(struct vc_data *vc, unsigned long org, size_t n) {}
static inline void vcs_scr_updated(struct vc_data *vc) {}
static inline void free_page(unsigned long addr) {}

static inline unsigned short get_unaligned(const unsigned short *p) {
    unsigned short val;
    memcpy(&val, p, sizeof(val));
    return val;
}