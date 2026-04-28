#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#define ANET_OK 0
#define ANET_ERR -1

static void anetSetError(char *err, const char *fmt, ...);