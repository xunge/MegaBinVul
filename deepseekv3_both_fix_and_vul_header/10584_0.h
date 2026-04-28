#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stdarg.h>

#define STI 0
#define STO 1
#define RUNCMD_ARGS_MAX 64
#define RUNCMD_EXEC_FAIL 127
#define EXEC "/bin/sh"