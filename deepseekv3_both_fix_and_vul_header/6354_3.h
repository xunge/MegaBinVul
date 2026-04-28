#include <stdlib.h>
#include <string.h>

#define SQUASHFS_NAME_LEN 256
#define SQUASHFS_DIR_COUNT 256
#define TRUE 1
#define FALSE 0
#define TRACE(fmt, ...)
#define ERROR(fmt, ...)
#define MEM_ERROR() exit(1)

struct super_block {
    struct {
        long long directory_table_start;
    } s;
} sBlk;

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

struct dir_ent {
    char *name;
    unsigned int start_block;
    unsigned int offset;
    unsigned int type;
    struct dir_ent *next;
};

struct dir {
    unsigned int dir_count;
    struct dir_ent *cur_entry;
    struct dir_ent *dirs;
    unsigned int mode;
    unsigned int uid;
    unsigned int guid;
    unsigned int mtime;
    unsigned int xattr;
};

typedef struct squashfs_dir_header_2 {
    unsigned int count;
    unsigned int start_block;
    unsigned int inode_number;
} squashfs_dir_header_2;

typedef struct squashfs_dir_entry_2 {
    unsigned int offset;
    unsigned int type;
    unsigned int size;
    char name[SQUASHFS_NAME_LEN];
} squashfs_dir_entry_2;

int swap;

static int read_directory_data(void *buf, long long *start, unsigned int *offset, int count);
static struct inode *read_inode(unsigned int block_start, unsigned int offset);
static void squashfs_closedir(struct dir *dir);
static int check_name(char *name, int size);
static void sort_directory(struct dir *dir);
static int check_directory(struct dir *dir);
static void SQUASHFS_SWAP_DIR_HEADER_2(squashfs_dir_header_2 *dirh, squashfs_dir_header_2 *sdirh);
static void SQUASHFS_SWAP_DIR_ENTRY_2(squashfs_dir_entry_2 *dire, squashfs_dir_entry_2 *sdire);