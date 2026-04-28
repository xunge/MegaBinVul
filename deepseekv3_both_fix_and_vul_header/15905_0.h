#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_AGENTS 256
#define OS_SIZE_1024 1024
#define ROOTCHECK_DIR "/var/ossec/queue/rootcheck"
#define ARGV0 "rootcheck"
#define FOPEN_ERROR "FOPEN_ERROR"
#define MEM_ERROR "MEM_ERROR"

static char *rk_agent_ips[MAX_AGENTS];
static FILE *rk_agent_fps[MAX_AGENTS];