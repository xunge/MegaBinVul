#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/stat.h>

#define ANET_ERR -1
#define redis_strlcpy strncpy

int anetSetError(char *err, const char *fmt, ...);
int anetCreateSocket(char *err, int domain);
int anetListen(char *err, int s, struct sockaddr *sa, socklen_t len, int backlog, ...);

int anetUnixServer(char *err, char *path, mode_t perm, int backlog);
int anetUnixServer(char *err, char *path, mode_t perm, int backlog);