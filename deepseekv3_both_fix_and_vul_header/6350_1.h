#include <stdlib.h>
#include <string.h>

#define SQUASHFS_NAME_LEN 256
#define SQUASHFS_DIR_COUNT 256
#define FALSE 0
#define TRUE 1

struct inode {
    unsigned int start;
    unsigned int offset;
    unsigned int data;
    unsigned int mode;
    unsigned int uid;
    unsigned int gid;
    unsigned int time;
    unsigned int xattr;
};

struct dir {
    int dir_count;
    struct dir_ent *cur_entry;
    unsigned int mode;
    unsigned int uid;
    unsigned int guid;
    unsigned int mtime;
    unsigned int xattr;
    struct dir_ent *dirs;
};

struct dir_ent {
    char *name;
    unsigned int start_block;
    unsigned int offset;
    unsigned int type;
    struct dir_ent *next;
};

struct squashfs_dir_header {
    unsigned int count;
    unsigned int start_block;
    unsigned int inode_number;
};

struct squashfs_dir_entry {
    unsigned short offset;
    unsigned short type;
    unsigned int size;
    char name[SQUASHFS_NAME_LEN + 1];
};

struct squashfs_super_block {
    struct {
        long long directory_table_start;
    } s;
};

#define TRACE(fmt, ...)
#define ERROR(fmt, ...)
#define MEM_ERROR() exit(1)

static struct squashfs_super_block sBlk;

static int read_directory_data(void *buf, long long *start, unsigned int *offset, int len);
static struct inode *read_inode(unsigned int block_start, unsigned int offset);
static void squashfs_closedir(struct dir *dir);
static int check_name(char *name, int size);
#define SQUASHFS_INSWAP_DIR_HEADER(hdr)
#define SQUASHFS_INSWAP_DIR_ENTRY(dire)