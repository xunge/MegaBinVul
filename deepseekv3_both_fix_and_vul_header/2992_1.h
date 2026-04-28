#include <linux/types.h>
#include <linux/socket.h>
#include <linux/tcp.h>
#include <linux/kernel.h>
#include <linux/uio.h>
#include <stddef.h>
#include <linux/errno.h>

struct TCP_Server_Info {
    struct socket *ssocket;
    int tcpStatus;
};

struct smb_rqst {
    struct kvec *rq_iov;
    int rq_nvec;
    unsigned int rq_npages;
    struct page **rq_pages;
};

struct kvec {
    void *iov_base;
    size_t iov_len;
};

#define CifsNeedReconnect 1
#define cFYI(level, fmt, ...)
#define cERROR(level, fmt, ...)
#define dump_smb(base, len)
#define kunmap(page)
#define kernel_setsockopt(sock, level, optname, optval, optlen) 0

static unsigned int get_rfc1002_length(void *base) { return 0; }
static int smb_send_kvec(struct TCP_Server_Info *server, struct kvec *iov, int n_vec, size_t *sent) { return 0; }
static void cifs_rqst_page_to_kvec(struct smb_rqst *rqst, unsigned int i, struct kvec *p_iov) {}