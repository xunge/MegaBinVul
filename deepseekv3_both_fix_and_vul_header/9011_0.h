#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define PROCLEN 256

static void stripnewline(char *str);
static void prune_init_slice(char *cg);
static char *get_next_cgroup_dir(const char *linecmp, const char *cg);