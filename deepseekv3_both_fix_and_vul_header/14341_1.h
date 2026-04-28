#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

typedef struct GF_BitStream GF_BitStream;
typedef uint32_t u32;
typedef bool Bool;

#define GF_FALSE false
#define GF_TRUE true
#define GF_LOG_ERROR 0
#define GF_LOG_CODING 0

void GF_LOG(int level, int category, const char* format, ...);
char gf_bs_read_int(GF_BitStream* bs, int bits);