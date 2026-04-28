#include <stddef.h>

struct xt_match {
    int (*compat)(void *, void *, int *, int);
};

struct ipt_entry_match {
    union {
        struct {
            struct xt_match *match;
        } kernel;
    } u;
};

#define COMPAT_CALC_SIZE 0

int xt_compat_match(struct ipt_entry_match *m, void *null, int *size, int compat_calc_size);