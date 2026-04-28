#include <stdlib.h>

typedef struct V9fsState {
    struct {
        char *fs_root;
    } ctx;
    char *tag;
} V9fsState;

typedef struct Error {
    // 根据需要可以添加成员
} Error;