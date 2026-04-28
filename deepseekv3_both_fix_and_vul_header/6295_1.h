#include <stdlib.h>
#include <string.h>

#define SQUASHFS_NAME_LEN 256
#define SQUASHFS_DIR_COUNT 256
#define DIR_ENT_SIZE 16
#define FALSE 0
#define TRUE 1

#define TRACE(fmt, ...)
#define ERROR(fmt, ...)
#define EXIT_UNSQUASH(fmt, ...) exit(1)

struct inode {
    unsigned int mode;
    unsigned int uid;
    unsigned int gid;
    unsigned int time;
    unsigned int xattr;
    unsigned int data;
    unsigned int start;
    unsigned int offset;
};

struct dir {
    unsigned int dir_count;
    unsigned int cur_entry;
    unsigned int mode;
    unsigned int uid;
    unsigned int guid;
    unsigned int mtime;
    unsigned int xattr;
    struct dir_ent *dirs;
};

struct dir_ent {
    char name[SQUASHFS_NAME_LEN + 1];
    unsigned int start_block;
    unsigned int offset;
    unsigned int type;
};

struct squashfs_dir_header {
    unsigned int count;
    unsigned int start_block;
    unsigned int inode_number;
};

struct squashfs_dir_entry {
    unsigned int offset;
    unsigned int type;
    unsigned int size;
    char name[SQUASHFS_NAME_LEN + 1];
};

struct squashfs_super_block {
    struct {
        long long directory_table_start;
    } s;
};

extern struct squashfs_super_block sBlk;
extern unsigned char *directory_table;
extern void *directory_table_hash;

static struct inode *read_inode(unsigned int block_start, unsigned int offset);
static long long lookup_entry(void *hash, long long start);
static int check_name(char *name, int size);
#define SQUASHFS_SWAP_DIR_HEADER(a, b)
#define SQUASHFS_SWAP_DIR_ENTRY(a, b)