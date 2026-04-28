#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <syslog.h>

#define LOW_START 0
#define HIGH_START 0
#define NUM_USE 0

extern uint16_t permutation[];
extern struct {
    int debug;
} T;

void make_random_permutation(int start);