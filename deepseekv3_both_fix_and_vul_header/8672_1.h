#include <stdint.h>
#include <sys/types.h>
#include <stdlib.h>

#define coroutine_fn

typedef struct V9fsString {
    char *data;
} V9fsString;

typedef struct V9fsPDU {
    int tag;
    int id;
} V9fsPDU;

typedef struct V9fsXattr {
    size_t copied_len;
    int64_t len;
    int flags;
    V9fsString name;
    void *value;
} V9fsXattr;

typedef struct V9fsFidState {
    int fid_type;
    union {
        struct V9fsXattr xattr;
    } fs;
} V9fsFidState;

enum {
    P9_FID_XATTR,
    EINVAL = 22
};

static void v9fs_string_init(V9fsString *str);
static void v9fs_string_free(V9fsString *str);
static void v9fs_string_copy(V9fsString *dst, V9fsString *src);
static ssize_t pdu_unmarshal(V9fsPDU *pdu, size_t offset, const char *fmt, ...);
static V9fsFidState *get_fid(V9fsPDU *pdu, int32_t fid);
static void put_fid(V9fsPDU *pdu, V9fsFidState *fidp);
static void pdu_complete(V9fsPDU *pdu, ssize_t err);
static void trace_v9fs_xattrcreate(int tag, int id, int32_t fid, char *data, int64_t size, int flags);
static void *g_malloc(size_t size);