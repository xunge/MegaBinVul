#include <stddef.h>
#include <string.h>
#include <sys/types.h>

typedef unsigned char u8;
typedef unsigned int __u32;
#define __force
#define __user

struct ib_uverbs_file {
    struct ib_ucontext *ucontext;
};

struct ib_ucontext;

struct ib_qp {
    unsigned int qp_num;
};

struct ib_cq;

struct ib_wc {
    unsigned long long wr_id;
    unsigned int status;
    unsigned int opcode;
    unsigned int vendor_err;
    unsigned int byte_len;
    union {
        unsigned int imm_data;
        unsigned int invalidated_rkey;
    } ex;
    struct ib_qp *qp;
    unsigned int src_qp;
    unsigned short wc_flags;
    unsigned short pkey_index;
    unsigned short slid;
    unsigned char sl;
    unsigned char dlid_path_bits;
    unsigned char port_num;
};

struct ib_uverbs_poll_cq {
    unsigned int cq_handle;
    unsigned int ne;
    unsigned long long response;
};

struct ib_uverbs_wc {
    unsigned long long wr_id;
    unsigned int status;
    unsigned int opcode;
    unsigned int vendor_err;
    unsigned int byte_len;
    union {
        unsigned int imm_data;
        unsigned int invalidated_rkey;
    } ex;
    unsigned int qp_num;
    unsigned int src_qp;
    unsigned short wc_flags;
    unsigned short pkey_index;
    unsigned short slid;
    unsigned char sl;
    unsigned char dlid_path_bits;
    unsigned char port_num;
    unsigned char reserved[3];
};

struct ib_uverbs_poll_cq_resp {
    unsigned int count;
    unsigned int reserved;
    struct ib_uverbs_wc wc[];
};

extern struct ib_cq *idr_read_cq(unsigned int cq_handle, struct ib_ucontext *ucontext, int pd);
extern void put_cq_read(struct ib_cq *cq);
extern int ib_poll_cq(struct ib_cq *cq, int num_entries, struct ib_wc *wc);
extern int copy_wc_to_user(void *dest, struct ib_wc *src);
extern int copy_from_user(void *to, const void *from, unsigned long n);
extern int copy_to_user(void *to, const void *from, unsigned long n);
extern void *kmalloc(size_t size, int flags);
extern void kfree(const void *objp);

#define GFP_KERNEL 0
#define EFAULT 1
#define EINVAL 2
#define ENOMEM 3