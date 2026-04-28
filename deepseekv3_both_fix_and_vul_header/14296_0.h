#include <stdio.h>
#include <stdarg.h>

typedef struct {
    int verbosity;
} Server;

extern void PySys_WriteStdout(const char *format, ...);