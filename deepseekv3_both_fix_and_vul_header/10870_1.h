#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SWF_ACTION SWF_ACTION;
struct Stack;

extern char *pool;
extern int poolcounter;
extern char *regs[256];
extern struct Stack *Stack;
extern char *dcstr;

char *newVar(const char *name);
void dcinit(void);
void decompileActions(int n, SWF_ACTION *actions, int indent);
char *dcgetstr(void);
void pop(void);