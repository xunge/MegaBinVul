#include <stdbool.h>

#define KDB_ENABLE_MASK 0x0F
#define KDB_ENABLE_ALWAYS_SAFE 0x10
#define KDB_ENABLE_NO_ARGS_SHIFT 4
#define KDB_ENABLE_ALL 0x1F

typedef unsigned int kdb_cmdflags_t;