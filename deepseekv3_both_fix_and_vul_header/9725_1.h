#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#define XATTR_OS2_PREFIX "os2."
#define XATTR_OS2_PREFIX_LEN (sizeof(XATTR_OS2_PREFIX) - 1)

struct inode;
struct jfs_ea_list {
    unsigned int size;
    char list[0];
};
struct jfs_ea {
    unsigned short namelen;
    unsigned short valuelen;
    unsigned short size;
    char name[0];
};
struct ea_buffer {
    void *xattr;
};

#define FIRST_EA(ealist) ((struct jfs_ea *)&(ealist)->list)
#define END_EALIST(ealist) \
    ((struct jfs_ea *)((char *)(ealist) + (ealist)->size))
#define NEXT_EA(ea) ((struct jfs_ea *)((char *)(ea) + (ea)->size))

#define JFS_IP(inode) ((struct jfs_inode_info *)(inode))

struct jfs_inode_info {
    struct {
        int count;
    } xattr_sem;
};

#define GFP_KERNEL 0
#define ENOMEM 12
#define ENODATA 61
#define ERANGE 34

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void down_read(void *sem) { ((struct jfs_inode_info *)sem)->xattr_sem.count++; }
static inline void up_read(void *sem) { ((struct jfs_inode_info *)sem)->xattr_sem.count--; }
static inline unsigned short le16_to_cpu(unsigned short val) { return val; }

extern int ea_get(struct inode *inode, struct ea_buffer *ea_buf, int);
extern void ea_release(struct inode *inode, struct ea_buffer *ea_buf);