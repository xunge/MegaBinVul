#include <stdlib.h>
#include <string.h>

typedef void* trio_pointer_t;
typedef void (*trio_callback_t)(void*);

typedef struct trio_userdef_t {
    trio_callback_t callback;
    char* name;
    struct trio_userdef_t* next;
} trio_userdef_t;

extern trio_userdef_t* internalUserDef;
extern trio_callback_t internalEnterCriticalRegion;
extern trio_callback_t internalLeaveCriticalRegion;

#define TRIO_ARGS2(args, a1, a2) (a1, a2)
#define TRIO_CONST const
#define TRIO_MALLOC(size) malloc(size)
#define MAX_USER_NAME 256

size_t trio_length(const char* str);
int trio_equal(const char* first, const char* second);
char* trio_duplicate(const char* source);
trio_userdef_t* TrioFindNamespace(const char* name, trio_userdef_t** prev);

static trio_pointer_t trio_register_impl(trio_callback_t callback, TRIO_CONST char* name);
#define trio_register(callback, name) trio_register_impl(callback, name)