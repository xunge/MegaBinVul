#include <stddef.h>
#include <string.h>

#define LZ4_ARCH64 0
#define ML_BITS 4
#define RUN_MASK 15
#define COPYLENGTH 8
#define ML_MASK 15
#define STEPSIZE 8

typedef unsigned char BYTE;

#define LZ4_WILDCOPY(d,s,e) do { memcpy(d,s,e-s); } while(0)
#define LZ4_READ_LITTLEENDIAN_16(d,s,p) { d = s; memcpy(&d, p, 2); }
#define LZ4_COPYSTEP(s,d) { memcpy(d,s,8); }
#define LZ4_SECURECOPY(s,d,e) { memcpy(d,s,e-d); }
#define PUT4(s,d) { memcpy(d,s,4); }

#define unlikely(x) (x)