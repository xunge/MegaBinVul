#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>

typedef int64_t TSK_OFF_T;
typedef int64_t ssize_t;
#define PRIuOFF PRIu64

typedef struct TSK_FS_INFO {
    int endian;
} TSK_FS_INFO;

typedef struct HFS_INFO {
    TSK_FS_INFO fs_info;
    struct {
        uint16_t nodesize;
        uint32_t rootNode;
        uint32_t totalNodes;
    } catalog_header;
    void *catalog_attr;
} HFS_INFO;

typedef struct hfs_btree_node {
    uint8_t type;
    uint16_t num_rec;
    uint32_t flink;
} hfs_btree_node;

typedef struct hfs_btree_key_cat {
    uint16_t key_len;
    uint32_t parent_cnid;
} hfs_btree_key_cat;

typedef struct hfs_btree_index_record {
    uint32_t childNode;
} hfs_btree_index_record;

typedef uint8_t (*TSK_HFS_BTREE_CB)(HFS_INFO *, uint8_t, void *, TSK_OFF_T, void *);

#define TSK_ERR_FS_GENFS 1
#define TSK_ERR_FS_READ 2
#define TSK_ERR_FS_WRITE 3
#define HFS_BT_NODE_TYPE_IDX 0
#define HFS_BT_NODE_TYPE_LEAF 1
#define HFS_BTREE_CB_ERR 1
#define HFS_BTREE_CB_IDX_LT 2
#define HFS_BTREE_CB_IDX_EQGT 3
#define HFS_BTREE_CB_LEAF_STOP 4

extern void tsk_error_reset(void);
extern void tsk_error_set_errno(int err);
extern void tsk_error_set_errstr(const char *fmt, ...);
extern void tsk_error_set_errstr2(const char *fmt, ...);
extern uint16_t tsk_getu16(int endian, const void *buf);
extern uint32_t tsk_getu32(int endian, const void *buf);
extern void *tsk_malloc(size_t size);
extern ssize_t tsk_fs_attr_read(void *attr, TSK_OFF_T off, void *buf, size_t len, int flags);
extern int tsk_verbose;
extern int tsk_fprintf(FILE *stream, const char *fmt, ...);
extern int hfs_get_idxkeylen(HFS_INFO *hfs, uint16_t key_len, void *header);

static inline uint16_t tsk_getu16_wrapper(int endian, uint16_t value) {
    return tsk_getu16(endian, &value);
}

static inline uint32_t tsk_getu32_wrapper(int endian, uint32_t value) {
    return tsk_getu32(endian, &value);
}