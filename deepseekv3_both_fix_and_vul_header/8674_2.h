#include <stdint.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>

#define coroutine_fn

typedef struct V9fsPDU V9fsPDU;
typedef struct V9fsState V9fsState;
typedef struct V9fsFidState V9fsFidState;
typedef struct QEMUIOVector QEMUIOVector;

enum {
    P9_FID_FILE,
    P9_FID_XATTR
};

struct QEMUIOVector {
    void *iov;
    int niov;
    size_t size;
};

struct V9fsFidState {
    int fid_type;
    union {
        int fd;
    } fs;
};

struct V9fsPDU {
    int tag;
    int id;
    V9fsState *s;
    bool cancelled;
};

#define EINTR 4
#define EINVAL 22

ssize_t pdu_unmarshal(V9fsPDU *pdu, size_t offset, const char *fmt, ...);
void pdu_complete(V9fsPDU *pdu, ssize_t err);
void v9fs_init_qiov_from_pdu(QEMUIOVector *qiov, V9fsPDU *pdu, size_t offset, uint32_t count, bool is_write);
void trace_v9fs_write(int tag, int id, int32_t fid, uint64_t off, uint32_t count, int niov);
V9fsFidState *get_fid(V9fsPDU *pdu, int32_t fid);
ssize_t v9fs_xattr_write(V9fsState *s, V9fsPDU *pdu, V9fsFidState *fidp, uint64_t off, uint32_t count, void *iov, int niov);
void qemu_iovec_init(QEMUIOVector *qiov, int niov);
void qemu_iovec_reset(QEMUIOVector *qiov);
void qemu_iovec_concat(QEMUIOVector *dst, QEMUIOVector *src, size_t soffset, size_t sbytes);
void print_sg(void *iov, int niov);
ssize_t v9fs_co_pwritev(V9fsPDU *pdu, V9fsFidState *fidp, void *iov, int niov, uint64_t off);
ssize_t pdu_marshal(V9fsPDU *pdu, size_t offset, const char *fmt, ...);
void trace_v9fs_write_return(int tag, int id, int32_t total, ssize_t err);
void qemu_iovec_destroy(QEMUIOVector *qiov);
void put_fid(V9fsPDU *pdu, V9fsFidState *fidp);