#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char bin128[16];
typedef unsigned int u32;
typedef enum {
    GF_OK,
    GF_BAD_PARAM
} GF_Err;
#define GF_EXPORT
#define GF_LOG_ERROR 0
#define GF_LOG_CORE 0
#define GF_LOG(level, category, message)
#define strnicmp strncasecmp