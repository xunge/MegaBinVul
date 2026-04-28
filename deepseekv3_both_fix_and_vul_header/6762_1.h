#include <stdio.h>

#define SWF_CALLMETHOD 0
#define SWFACTION_PUSH 0
#define SWFACTION_POP 0

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

#define SanityCheck(a, b, c) 
#define INDENT 
#define pop() NULL
#define push(a) 
#define newVar_N(a, b, c, d, e, f) NULL
#define getName(a) NULL
#define println(a, ...) 
#define puts(a) 
#define OpCode(a, b, c) 0