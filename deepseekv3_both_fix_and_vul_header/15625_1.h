#include <sys/time.h>
#include <stdio.h>

struct fib6_info {
    unsigned long expires;
    unsigned int fib6_flags;
};

struct fib6_gc_args {
    int more;
};

#define RTF_EXPIRES 0x0001
#define RT6_TRACE(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define jiffies (unsigned long)time(NULL)
#define time_after(a,b) ((long)(b) - (long)(a) < 0)