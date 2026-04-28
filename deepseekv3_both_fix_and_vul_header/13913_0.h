#include <stdio.h>

typedef struct {
    int ActionCode;
} SWF_ACTIONRECORD;

typedef struct {
    SWF_ACTIONRECORD SWF_ACTIONRECORD;
} SWF_ACTION;

#define DEBUG 1
void SWF_warn(const char *format, ...);