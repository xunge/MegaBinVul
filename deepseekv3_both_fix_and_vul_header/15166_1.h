#include <sys/types.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <stddef.h>
#include <errno.h>

typedef struct mddev_s mddev_t;
struct mddev_s {
    unsigned long long suspend_hi;
    unsigned long long suspend_lo;
    struct {
        int (*quiesce)(mddev_t *, int);
    } *pers;
};

unsigned long long simple_strtoull(const char *cp, char **endp, unsigned int base);