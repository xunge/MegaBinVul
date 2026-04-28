#include <stdint.h>
#include <limits.h>
#include <stddef.h>

#define MIN_INT16 INT16_MIN
#define MAX_INT16 INT16_MAX
#define AF_BAD_COMPRESSION 1

struct ms_adpcm_state {
    int16_t sample1;
    int16_t sample2;
    int delta;
};

extern const int adaptationTable[];
extern int multiplyCheckOverflow(int a, int b, int* result);
extern void _af_error(int code, const char* message);

static inline int clamp(int value, int min, int max) {
    return (value < min) ? min : (value > max) ? max : value;
}