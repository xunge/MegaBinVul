#include <stdlib.h>

enum grub_fshelp_filetype {
    GRUB_FSHELP_UNKNOWN,
    GRUB_FSHELP_DIR,
    GRUB_FSHELP_SYMLINK,
    GRUB_FSHELP_REG
};

#define FILETYPE_UNKNOWN 0
#define FILETYPE_DIRECTORY 1
#define FILETYPE_SYMLINK 2
#define FILETYPE_REG 3

#define FILETYPE_INO_MASK 0xF000
#define FILETYPE_INO_DIRECTORY 0x4000
#define FILETYPE_INO_SYMLINK 0xA000
#define FILETYPE_INO_REG 0x8000

struct ext2_dirent {
    unsigned int inode;
    unsigned short direntlen;
    unsigned char namelen;
    unsigned char filetype;
};

struct grub_fshelp_node {
    void *data;
    unsigned int ino;
    int inode_read;
    struct {
        unsigned int size;
        unsigned short mode;
    } inode;
};

typedef struct grub_fshelp_node *grub_fshelp_node_t;

extern int grub_errno;
extern void *grub_malloc(size_t size);
extern void grub_free(void *ptr);
extern unsigned int grub_le_to_cpu32(unsigned int x);
extern unsigned short grub_le_to_cpu16(unsigned short x);
extern void grub_ext2_read_inode(void *data, unsigned int ino, void *inode);
extern void grub_ext2_read_file(grub_fshelp_node_t node, void *read_hook,
                               void *read_hook_data, int flags,
                               unsigned int pos, unsigned int len, char *buf);