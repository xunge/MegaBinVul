#include <stdlib.h>
#include <unistd.h>

typedef struct afl_forkserver {
    int qemu_mode;
    int frida_mode;
    char *cmplog_binary;
    char *target_path;
} afl_forkserver_t;