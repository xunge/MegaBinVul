#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define SQUASHFS_METADATA_SIZE 8192
#define SQUASHFS_FRAGMENT_BYTES(fragments) ((fragments) * sizeof(struct squashfs_fragment_entry))
#define SQUASHFS_FRAGMENT_INDEXES(fragments) (((fragments) + SQUASHFS_METADATA_SIZE - 1) / SQUASHFS_METADATA_SIZE)
#define SQUASHFS_FRAGMENT_INDEX_BYTES(fragments) (SQUASHFS_FRAGMENT_INDEXES(fragments) * sizeof(long long))
#define TRACE(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define ERROR(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define EXIT_UNSQUASH(msg) do { ERROR(msg); exit(1); } while(0)

struct squashfs_super_block {
    struct {
        long long fragment_table_start;
        unsigned int fragments;
    } s;
};

struct squashfs_fragment_entry {
    long long start_block;
    unsigned int size;
    unsigned int unused;
};

extern struct squashfs_super_block sBlk;
extern int fd;
extern struct squashfs_fragment_entry *fragment_table;

int read_fs_bytes(int fd, long long start, int length, void *buffer);
int read_block(int fd, long long start, long long *next, int length, void *buffer);
void SQUASHFS_INSWAP_FRAGMENT_INDEXES(long long *block_list, int block_count);
void SQUASHFS_INSWAP_FRAGMENT_ENTRY(struct squashfs_fragment_entry *entry);