#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/un.h>

#define CMD_PATH "/tmp/cmd_socket"
extern const char *g_client_usage;