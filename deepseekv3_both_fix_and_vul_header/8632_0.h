#include <stdint.h>
#include <math.h>

#define Fltsize 1.0
#define CODE_MASK 0xFFFF
#define LogK1 1.0
#define LogK2 1.0
#define REPEAT(n, op) { int i; for (i = 0; i < n; i++) { op; } }

typedef uint16_t uint16;
typedef int32_t int32;