#include <stddef.h>

struct cpuinfo_x86 {
    unsigned int x86_clflush_size;
};

extern struct cpuinfo_x86 current_cpu_data;

#define X86_FEATURE_CLFLUSHOPT (0*32+23)
#define X86_BUG_CLFLUSH_MFENCE (0*32+0)

#define alternative(oldinstr, newinstr, feature) \
    asm volatile (oldinstr "\n" newinstr)

#define alternative_io(oldinstr, newinstr, feature, output, input...) \
    asm volatile (oldinstr "\n" newinstr : output : input)

#define alternative_2(oldinstr, newinstr1, feature1, newinstr2, feature2) \
    asm volatile (oldinstr "\n" newinstr1 "\n" newinstr2)