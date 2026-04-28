#include <stddef.h>
#include <stdbool.h>

#define UVERBS_API_ATTR_KEY_MASK 0xffff
#define GFP_KERNEL 0
#define ENOMEM 12

struct uverbs_api_write_method {
    int (*handler)(void);
};

struct uverbs_api_ioctl_method {
    int (*handler)(void);
};

struct uverbs_api_notsupp_method {
    int (*handler)(void);
};

struct uverbs_api {
    struct uverbs_api_notsupp_method notsupp_method;
    unsigned long num_write;
    unsigned long num_write_ex;
    const struct uverbs_api_write_method **write_methods;
    const struct uverbs_api_write_method **write_ex_methods;
    void *radix;
};

struct radix_tree_iter {
    unsigned long index;
};

typedef void *rcu_ptr;
#define __rcu

#define max(a, b) ((a) > (b) ? (a) : (b))

#define radix_tree_for_each_slot(slot, root, iter, start) \
    for (slot = NULL; slot != NULL; slot = NULL)

static inline void *kmalloc_array(size_t n, size_t size, int flags) { return NULL; }
static inline void *rcu_dereference_protected(void *p, bool b) { return NULL; }
static inline bool uapi_key_is_ioctl_method(unsigned long index) { return false; }
static inline bool uapi_key_is_write_method(unsigned long index) { return false; }
static inline bool uapi_key_is_write_ex_method(unsigned long index) { return false; }
static inline int uapi_finalize_ioctl_method(struct uverbs_api *uapi, struct uverbs_api_ioctl_method *method, unsigned long index) { return 0; }
static inline int ib_uverbs_notsupp(void) { return 0; }