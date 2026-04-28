#include <stdio.h>

typedef struct SWF_ACTIONRECORD {
    unsigned short ActionCode;
    unsigned int Offset;
} SWF_ACTIONRECORD;

typedef struct SWF_ACTIONJUMP {
    SWF_ACTIONRECORD SWF_ACTIONRECORD;
    short BranchOffset;
    unsigned int Offset;
} SWF_ACTIONJUMP;

typedef struct SWF_ACTIONIF {
    SWF_ACTIONRECORD SWF_ACTIONRECORD;
    int numActions;
    struct SWF_ACTION *Actions;
} SWF_ACTIONIF;

typedef struct SWF_ACTION {
    union {
        SWF_ACTIONRECORD SWF_ACTIONRECORD;
        SWF_ACTIONJUMP SWF_ACTIONJUMP;
    };
    short BranchOffset;
} SWF_ACTION;

#define SWFACTION_PUSH 0x96
#define SWFACTION_POP 0x17
#define SWFACTION_JUMP 0x99
#define SWFACTION_IF 0x9D

extern int gIndent;
extern int offseoloop;
extern SWF_ACTION *sact;

#define OUT_BEGIN2(x)
#define INDENT
#define println(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#define puts(s) printf("%s", s)

int decompileActions(int n, SWF_ACTION *actions, int indent);
int decompileRETURN(int n, SWF_ACTION *actions, int maxn);
int isLogicalOp(int n, SWF_ACTION *actions, int maxn);
int OpCode(SWF_ACTION *actions, int n, int maxn);
char *getName(char *str);
char *pop();
int stackVal(int n, SWF_ACTION *actions);