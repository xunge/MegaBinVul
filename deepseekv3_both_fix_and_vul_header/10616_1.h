#include <stdint.h>
#include <ctype.h>
#include <stddef.h>

#define ERROR_SUCCESS 0
#define RE_FLAGS_WIDE 0x01
#define MAX_MATCH_DATA 0
#define STRING_IS_CHAIN_PART(s) 0
#define STRING_IS_GREEDY_REGEXP(s) 0
#define FAIL_ON_ERROR(x) if (x != ERROR_SUCCESS) return x

typedef struct YR_STRING YR_STRING;
typedef struct YR_MATCH YR_MATCH;
typedef struct CALLBACK_ARGS CALLBACK_ARGS;
typedef struct YR_CONTEXT YR_CONTEXT;

struct YR_MATCH {
    int data_length;
    uint8_t* data;
    uint8_t* base;
    size_t offset;
    int32_t match_length;
    struct YR_MATCH* prev;
    struct YR_MATCH* next;
};

struct YR_STRING {
    struct {
        int count;
        YR_MATCH* head;
    } matches[1];
};

struct YR_CONTEXT {
    int tidx;
    void* matching_strings_arena;
    void* matches_arena;
};

struct CALLBACK_ARGS {
    YR_STRING* string;
    YR_CONTEXT* context;
    uint8_t* data;
    uint8_t* data_base;
    size_t data_size;
    int forward_matches;
    int full_word;
};

static int yr_min(int a, int b) { return a < b ? a : b; }
static int _yr_scan_verify_chained_string_match(YR_STRING* string, YR_CONTEXT* context, uint8_t* match_data, uint8_t* data_base, size_t match_offset, int match_length) { return ERROR_SUCCESS; }
static int yr_arena_write_data(void* arena, void* data, size_t size, void** output) { return ERROR_SUCCESS; }
static int yr_arena_allocate_memory(void* arena, size_t size, void** output) { return ERROR_SUCCESS; }
static int _yr_scan_add_match_to_list(YR_MATCH* new_match, void* matches, int is_greedy) { return ERROR_SUCCESS; }