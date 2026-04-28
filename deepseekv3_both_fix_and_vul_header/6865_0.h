#include <stdio.h>
#include <stdint.h>

#define MAX_ALN 256
#define verbprintf(level, ...) if (level <= VERBOSITY) printf(__VA_ARGS__)
unsigned int VERBOSITY = 3;