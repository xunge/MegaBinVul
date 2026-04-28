#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#define MAX_FAST_RE_STACK 256
#define FALSE 0
#define TRUE 1

#define RE_OPCODE_MATCH 0
#define RE_OPCODE_LITERAL 1
#define RE_OPCODE_MASKED_LITERAL 2
#define RE_OPCODE_ANY 3
#define RE_OPCODE_REPEAT_ANY_UNGREEDY 4

#define RE_FLAGS_BACKWARDS 0x01
#define RE_FLAGS_EXHAUSTIVE 0x02

#define ERROR_SUCCESS 0

typedef int (*RE_MATCH_CALLBACK_FUNC)(void*, int, int, void*);

typedef struct {
    int min;
    int max;
} RE_REPEAT_ANY_ARGS;

#define FAIL_ON_ERROR(x) if ((x) != ERROR_SUCCESS) return -1