#include <stdint.h>
#include <stddef.h>

#define MAX_NAMELEN 255

enum grub_fshelp_filetype {
  GRUB_FSHELP_UNKNOWN,
  GRUB_FSHELP_DIR,
  GRUB_FSHELP_SYMLINK,
  GRUB_FSHELP_REG
};

#define FILETYPE_UNKNOWN 0
#define FILETYPE_DIRECTORY 2
#define FILETYPE_SYMLINK 7
#define FILETYPE_REG 1

#define FILETYPE_INO_MASK 0xf000
#define FILETYPE_INO_DIRECTORY 0x4000
#define FILETYPE_INO_SYMLINK 0xa000
#define FILETYPE_INO_REG 0x8000

struct ext2_dirent {
  uint32_t inode;
  uint16_t direntlen;
  uint8_t namelen;
  uint8_t filetype;
};

struct grub_fshelp_node {
  void *data;
  uint32_t ino;
  int inode_read;
  struct {
    uint32_t size;
    uint16_t mode;
  } inode;
};

typedef int (*grub_fshelp_iterate_dir_hook_t)(const char *filename,
                                             enum grub_fshelp_filetype filetype,
                                             struct grub_fshelp_node *node,
                                             void *data);

typedef struct grub_fshelp_node *grub_fshelp_node_t;

extern void *grub_malloc(size_t size);
extern void grub_free(void *ptr);
extern int grub_errno;
extern uint16_t grub_le_to_cpu16(uint16_t val);
extern uint32_t grub_le_to_cpu32(uint32_t val);
extern void grub_ext2_read_inode(void *data, uint32_t ino, void *inode);
extern void grub_ext2_read_file(struct grub_fshelp_node *node,
                              int read_symlink, int pos,
                              unsigned int offset, unsigned int len,
                              char *buf);