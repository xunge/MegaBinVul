#include <stdint.h>

typedef struct GetBitContext GetBitContext;
typedef struct Pulse {
    int num_pulse;
    int pos[4];
    int amp[4];
} Pulse;

int get_bits(GetBitContext *gb, int n);