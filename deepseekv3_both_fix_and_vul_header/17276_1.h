#include <sys/time.h>
#include <stddef.h>

struct timex {
    int modes;
    long offset;
    long freq;
    long maxerror;
    long esterror;
    int status;
    long constant;
    long precision;
    long tolerance;
    struct timeval time;
    long tick;
    long ppsfreq;
    long jitter;
    int shift;
    long stabil;
    long jitcnt;
    long calcnt;
    long errcnt;
    long stbcnt;
};

struct compat_timex {
    int modes;
    long offset;
    long freq;
    long maxerror;
    long esterror;
    int status;
    long constant;
    long precision;
    long tolerance;
    struct {
        long tv_sec;
        long tv_usec;
    } time;
    long tick;
    long ppsfreq;
    long jitter;
    int shift;
    long stabil;
    long jitcnt;
    long calcnt;
    long errcnt;
    long stbcnt;
};

#define __user
#define EFAULT 14
static inline int copy_from_user(void *dst, const void *src, size_t size) {
    (void)dst; (void)src; (void)size;
    return 0;
}