#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <assert.h>

#define ERROR_SUCCESS 0
#define ERROR_INSUFFICIENT_MEMORY 1
#define RE_FLAGS_WIDE 1
#define YR_CONFIG_MAX_MATCH_DATA 0

typedef struct _YR_STRING {
    uint32_t length;
    int idx;
} YR_STRING;

typedef struct _YR_MATCH {
    uint8_t* data;
    uint32_t data_length;
    uint64_t base;
    size_t offset;
    int32_t match_length;
    struct _YR_MATCH* prev;
    struct _YR_MATCH* next;
    int is_private;
} YR_MATCH;

typedef struct _YR_CONTEXT {
    void* matches_notebook;
    YR_MATCH** matches;
} YR_CONTEXT;

typedef struct _CALLBACK_ARGS {
    uint8_t* data;
    YR_STRING* string;
    uint64_t data_base;
    size_t data_size;
    uint32_t forward_matches;
    int full_word;
    YR_CONTEXT* context;
} CALLBACK_ARGS;

#define STRING_IS_CHAIN_PART(s) 0
#define STRING_IS_PRIVATE(s) 0
#define STRING_IS_GREEDY_REGEXP(s) 0
#define YR_DEBUG_FPRINTF(level, stream, ...) fprintf(stream, __VA_ARGS__)

int yr_get_configuration(int config, uint32_t* value);
int yr_isalnum(const uint8_t* c);
int _yr_scan_verify_chained_string_match(YR_STRING* string, YR_CONTEXT* context, const uint8_t* match_data, uint64_t data_base, size_t match_offset, int match_length);
int _yr_scan_add_match_to_list(YR_MATCH* match, YR_MATCH** list, int greedy);
void* yr_notebook_alloc(void* notebook, size_t size);
#define yr_min(a, b) ((a) < (b) ? (a) : (b))
#define FAIL_ON_ERROR(x) { int ret = (x); if (ret != ERROR_SUCCESS) { result = ret; goto _exit; } }