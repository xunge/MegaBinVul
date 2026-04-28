#include <stdio.h>

typedef struct V9fsPath {
    char *data;
} V9fsPath;

typedef struct FsContext {
    // Add necessary fields if any
} FsContext;

static void v9fs_path_sprintf(V9fsPath *target, const char *fmt, ...);