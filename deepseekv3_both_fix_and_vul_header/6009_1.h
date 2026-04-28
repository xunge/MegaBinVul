#include <stdint.h>

#define COMPAT_TO_USER 0
#define __user

typedef unsigned int compat_uint_t;

struct xt_match {
    int (*compat)(struct ipt_entry_match *, void __user **, compat_uint_t *, int);
};

struct ipt_entry_match {
    union {
        struct {
            struct xt_match *match;
        } kernel;
    } u;
};

int xt_compat_match(struct ipt_entry_match *m, void __user **dstptr, compat_uint_t *size, int flag);