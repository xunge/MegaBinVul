#include <stdlib.h>

struct io_ring_ctx {
    struct mm_struct *sqo_mm;
    void *rings;
    void *sq_sqes;
    void *refs;
    int account_mem;
    struct user_struct *user;
    unsigned long sq_entries;
    unsigned long cq_entries;
    void *completions;
    void *fallback_req;
    struct sock *ring_sock;
    struct cred *creds;
};

struct mm_struct;
struct sock;
struct user_struct;
struct cred;

extern void io_finish_async(struct io_ring_ctx *ctx);
extern void io_iopoll_reap_events(struct io_ring_ctx *ctx);
extern void io_sqe_buffer_unregister(struct io_ring_ctx *ctx);
extern void io_sqe_files_unregister(struct io_ring_ctx *ctx);
extern void io_eventfd_unregister(struct io_ring_ctx *ctx);
extern void io_mem_free(void *ptr);
extern void io_unaccount_mem(struct user_struct *user, unsigned long pages);
extern unsigned long ring_pages(unsigned long sq_entries, unsigned long cq_entries);
extern void mmdrop(struct mm_struct *mm);
extern void sock_release(struct sock *sk);
extern void free_uid(struct user_struct *user);
extern void put_cred(struct cred *cred);
extern void percpu_ref_exit(void *ref);
extern void kfree(void *ptr);
extern void kmem_cache_free(void *cachep, void *obj);

extern void *req_cachep;