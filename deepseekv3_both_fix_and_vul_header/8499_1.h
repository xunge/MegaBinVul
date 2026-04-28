#include <stdio.h>

#define IDX_STDOUT 0
#define IDX_STDERR 1

struct SystemCmd {
    static FILE* _childStdin;
    static FILE* _files[2];
    static void cleanup();
};

FILE* SystemCmd::_childStdin = NULL;
FILE* SystemCmd::_files[2] = {NULL, NULL};