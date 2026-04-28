#include <stddef.h>

struct cpuinfo_x86 {
    unsigned int x86_clflush_size;
};

extern struct cpuinfo_x86 current_cpu_data;

#define HAVE_AS_CLWB
#define HAVE_AS_XSAVEOPT
#define X86_FEATURE_CLFLUSHOPT (1 << 0)
#define X86_FEATURE_CLWB (1 << 1)

#define alternative_io_2(a, b, c, d, e, f, ...)
#define alternative_2(a, b, c, d, e)