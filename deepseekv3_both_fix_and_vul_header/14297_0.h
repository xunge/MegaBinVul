#include <stdio.h>
#include <stdarg.h>

typedef struct {
    int verbosity;
} Server;

void PySys_WriteStdout(const char *format, ...);