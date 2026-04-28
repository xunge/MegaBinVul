#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>

typedef struct V9fsPDU V9fsPDU;
typedef struct V9fsState V9fsState;
typedef struct V9fsFidState V9fsFidState;
typedef struct QEMUIOVector QEMUIOVector;

enum {
    P9_FID_DIR,
    P9_FID_FILE,
    P9_FID_XATTR
};

struct V9fsFidState {
    int fid_type;
};

struct QEMUIOVector {
    int niov;
    size_t size;
    void *iov;
};

struct V9fsPDU {
    int tag;
    int id;
    V9fsState *s;
    int cancelled;
};

extern ssize_t pdu_unmarshal(V9fsPDU *pdu, size_t offset, const char *fmt, ...);
extern int pdu_marshal(V9fsPDU *pdu, size_t offset, const char *fmt, ...);
extern V9fsFidState *get_fid(V9fsPDU *pdu, int32_t fid);
extern void put_fid(V9fsPDU *pdu, V9fsFidState *fidp);
extern void pdu_complete(V9fsPDU *pdu, ssize_t err);
extern void v9fs_co_rewinddir(V9fsPDU *pdu, V9fsFidState *fidp);
extern int v9fs_do_readdir_with_stat(V9fsPDU *pdu, V9fsFidState *fidp, uint32_t max_count);
extern void v9fs_init_qiov_from_pdu(QEMUIOVector *qiov, V9fsPDU *pdu, size_t offset, uint32_t max_count, bool is_write);
extern void qemu_iovec_init(QEMUIOVector *qiov, int niov);
extern void qemu_iovec_reset(QEMUIOVector *qiov);
extern void qemu_iovec_concat(QEMUIOVector *dst, QEMUIOVector *src, size_t skip, size_t size);
extern void qemu_iovec_destroy(QEMUIOVector *qiov);
extern int v9fs_co_preadv(V9fsPDU *pdu, V9fsFidState *fidp, void *iov, int niov, uint64_t off);
extern int v9fs_xattr_read(V9fsState *s, V9fsPDU *pdu, V9fsFidState *fidp, uint64_t off, uint32_t max_count);
extern void print_sg(void *iov, int niov);
extern void trace_v9fs_read(int tag, int id, int32_t fid, uint64_t off, uint32_t max_count);
extern void trace_v9fs_read_return(int tag, int id, int32_t count, ssize_t err);