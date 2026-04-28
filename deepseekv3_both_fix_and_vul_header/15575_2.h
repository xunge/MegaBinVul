#include <sys/types.h>
#include <stddef.h>
#include <sys/uio.h>

struct sock;
struct page;

struct msghdr {
    struct iovec msg_iter;
};

struct sk_msg {
    struct {
        int copybreak;
        int curr;
        int end;
    } sg;
};

#define WARN_ON_ONCE(cond) (cond)
#define EIO 5

static inline int sendpage_ok(struct page *page) { return 1; }
static inline void iov_iter_revert(struct iovec *iter, ssize_t bytes) {}
static inline ssize_t iov_iter_extract_pages(struct iovec *iter, struct page ***pages, size_t size, int maxpages, unsigned int gup_flags, size_t *off) { return 0; }
static inline void sk_msg_page_add(struct sk_msg *msg, struct page *page, size_t size, size_t off) {}
static inline int sk_msg_full(struct sk_msg *msg) { return 0; }
static inline void sk_mem_charge(struct sock *sk, ssize_t size) {}