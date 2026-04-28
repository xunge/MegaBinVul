#include <stdint.h>

#define SCOPE_LOCAL_CPU 0

typedef uint8_t u8;

struct midr_range {
    unsigned long min;
    unsigned long max;
};

#define MIDR_ALL_VERSIONS(midr) { .min = midr, .max = midr }

#define MIDR_CORTEX_A78     0x410FD410
#define MIDR_CORTEX_A78AE   0x410FD4E0
#define MIDR_CORTEX_A78C    0x410FD4B0
#define MIDR_CORTEX_X1      0x410FD440
#define MIDR_CORTEX_A710    0x412FD410
#define MIDR_CORTEX_X2      0x411FD4C0
#define MIDR_NEOVERSE_N2    0x410FD4F0
#define MIDR_NEOVERSE_V1    0x411FD4D0
#define MIDR_CORTEX_A76     0x410FD0B0
#define MIDR_CORTEX_A77     0x410FD0D0
#define MIDR_NEOVERSE_N1    0x410FD0C0
#define MIDR_AMPERE1        0x410FD0E0
#define MIDR_CORTEX_A72     0x410FD080
#define MIDR_CORTEX_A57     0x410FD070

unsigned long read_cpuid_id(void);
int is_midr_in_range_list(unsigned long midr, const struct midr_range *range_list);
#define max(a, b) ((a) > (b) ? (a) : (b))