#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SQUASHFS_NAME_LEN 256
#define SQUASHFS_DIR_COUNT 256
#define DIR_ENT_SIZE 16
#define FALSE 0
#define TRUE 1

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
    char name[SQUASHFS_NAME_LEN + 1];
    unsigned int start_block;
    unsigned int offset;
    unsigned int type;
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

struct squashfs_dir_header_2 {
    unsigned int count;
    unsigned int start_block;
};

struct squashfs_dir_entry_2 {
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
extern char *directory_table;
extern int swap;
extern int directory_table_hash[];

#define TRACE(fmt, ...)
#define ERROR(fmt, ...)
#define EXIT_UNSQUASH(fmt, ...) exit(1)

long long lookup_entry(int *hash, long long start);
struct inode *read_inode(unsigned int block_start, unsigned int offset);
void SQUASHFS_SWAP_DIR_HEADER_2(struct squashfs_dir_header_2 *a, struct squashfs_dir_header_2 *b);
void SQUASHFS_SWAP_DIR_ENTRY_2(struct squashfs_dir_entry_2 *a, struct squashfs_dir_entry_2 *b);
bool check_name(const char *name, int size);

typedef struct squashfs_dir_header_2 squashfs_dir_header_2;
typedef struct squashfs_dir_entry_2 squashfs_dir_entry_2;