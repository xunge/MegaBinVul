#include <stdint.h>
#include <stddef.h>

#define YR_API

typedef enum {
    YR_CONFIG_STACK_SIZE,
    YR_CONFIG_MAX_STRINGS_PER_RULE,
    YR_CONFIG_MAX_MATCH_DATA,
    YR_CONFIG_MAX_PROCESS_MEMORY_CHUNK
} YR_CONFIG_NAME;

typedef union {
    uint32_t ui32;
    uint64_t ui64;
} YR_CONFIG_VALUE;

extern YR_CONFIG_VALUE yr_cfgs[];

#define ERROR_INVALID_ARGUMENT 1
#define ERROR_INTERNAL_FATAL_ERROR 2
#define ERROR_SUCCESS 0