#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

static char *get_rundir(void);
static int mkdir_p(const char *dir, mode_t mode);