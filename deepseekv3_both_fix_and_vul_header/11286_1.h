#include <stdbool.h>
#include <errno.h>
#include <stdint.h>
#include <stddef.h>
#include <sys/uio.h>

typedef struct NBDClientSession NBDClientSession;
typedef struct NBDRequest NBDRequest;
typedef struct NBDReply NBDReply;
typedef struct QEMUIOVector QEMUIOVector;

struct NBDReply {
    uint64_t handle;
    int error;
};

struct NBDRequest {
    uint64_t handle;
    size_t len;
};

struct QEMUIOVector {
    struct iovec *iov;
    int niov;
};

struct NBDClientSession {
    NBDReply reply;
    void *ioc;
};

void qemu_coroutine_yield(void);
int nbd_wr_syncv(void *ioc, struct iovec *iov, int niov, size_t len, bool write);