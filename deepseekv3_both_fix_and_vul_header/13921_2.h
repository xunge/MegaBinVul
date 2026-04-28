#include <stdio.h>

#define SWFACTION_PUSH 0
#define SWF_CALLMETHOD 0
#define SWFACTION_POP 0

#define INDENT
#define SanityCheck(a, b, c)
#define OpCode(a, b, c) 0

typedef struct SWF_ACTIONRECORD {
    int ActionCode;
} SWF_ACTIONRECORD;

typedef struct SWF_ACTION {
    SWF_ACTIONRECORD SWF_ACTIONRECORD;
} SWF_ACTION;

typedef struct SWF_ACTIONPUSHPARAM {
    union {
        int Integer;
    } p;
} SWF_ACTIONPUSHPARAM;

static SWF_ACTIONPUSHPARAM* pop(void);
static void push(SWF_ACTIONPUSHPARAM*);
static void println(const char*, ...);
static char* getName(SWF_ACTIONPUSHPARAM*);
static SWF_ACTIONPUSHPARAM* newVar_N(const char*, const char*, const char*, const char*, int, const char*);