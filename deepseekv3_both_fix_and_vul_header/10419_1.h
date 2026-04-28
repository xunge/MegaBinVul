#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <ctype.h>

#define ERROR_SUCCESS 0
#define ERROR_INSUFFICIENT_MEMORY -1
#define ERROR_TOO_MANY_RE_FIBERS -2
#define ERROR_TOO_MANY_MATCHES -3

#define RE_FLAGS_WIDE 0x01
#define RE_FLAGS_BACKWARDS 0x02
#define RE_FLAGS_DOT_ALL 0x04
#define RE_FLAGS_NO_CASE 0x08
#define RE_FLAGS_NOT_AT_START 0x10
#define RE_FLAGS_EXHAUSTIVE 0x20
#define RE_FLAGS_SCAN 0x40

#define RE_SCAN_LIMIT 0x10000

#define TRUE 1
#define FALSE 0

#define CHAR_IN_CLASS(c, class) (((uint8_t*)(class))[(c)/8] & (1 << ((c)%8)))
#define IS_WORD_CHAR(c) (isalnum(c) || (c) == '_')

typedef int (*RE_MATCH_CALLBACK_FUNC)(void*, int, int, void*);

typedef struct _RE_FIBER {
    uint8_t* ip;
    struct _RE_FIBER* next;
} RE_FIBER;

typedef struct {
    RE_FIBER* head;
    RE_FIBER* tail;
} RE_FIBER_LIST;

typedef struct _RE_THREAD_STORAGE {
    void* fiber_pool;
} RE_THREAD_STORAGE;

#define RE_OPCODE_ANY 0
#define RE_OPCODE_REPEAT_ANY_GREEDY 1
#define RE_OPCODE_REPEAT_ANY_UNGREEDY 2
#define RE_OPCODE_LITERAL 3
#define RE_OPCODE_MASKED_LITERAL 4
#define RE_OPCODE_CLASS 5
#define RE_OPCODE_WORD_CHAR 6
#define RE_OPCODE_NON_WORD_CHAR 7
#define RE_OPCODE_SPACE 8
#define RE_OPCODE_NON_SPACE 9
#define RE_OPCODE_DIGIT 10
#define RE_OPCODE_NON_DIGIT 11
#define RE_OPCODE_WORD_BOUNDARY 12
#define RE_OPCODE_NON_WORD_BOUNDARY 13
#define RE_OPCODE_MATCH_AT_START 14
#define RE_OPCODE_MATCH_AT_END 15
#define RE_OPCODE_MATCH 16

extern uint8_t yr_lowercase[256];
extern uint8_t yr_altercase[256];

static inline size_t yr_min(size_t a, size_t b) { return a < b ? a : b; }

int _yr_re_alloc_storage(RE_THREAD_STORAGE** storage);
int _yr_re_fiber_create(void* pool, RE_FIBER** fiber);
int _yr_re_fiber_sync(RE_FIBER_LIST* fibers, void* pool, RE_FIBER* fiber);
RE_FIBER* _yr_re_fiber_kill(RE_FIBER_LIST* fibers, void* pool, RE_FIBER* fiber);
void _yr_re_fiber_kill_tail(RE_FIBER_LIST* fibers, void* pool, RE_FIBER* fiber);
void _yr_re_fiber_kill_all(RE_FIBER_LIST* fibers, void* pool);
void _yr_re_fiber_append(RE_FIBER_LIST* fibers, RE_FIBER* fiber);