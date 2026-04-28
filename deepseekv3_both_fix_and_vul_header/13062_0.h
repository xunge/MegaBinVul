#include <stdio.h>
#include <string.h>

#define EXPORT_CALL
#define FILENAMESIZE 256

static FILE *logFile = NULL;
static char initialLogFileName[FILENAMESIZE] = {0};