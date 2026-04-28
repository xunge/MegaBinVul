#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

#define AY_CONNECTION_REFUSED -1
#define AY_PROXY_AUTH_REQUIRED -2
#define AY_PROXY_PERMISSION_DENIED -3

typedef struct {
    char *username;
} AyProxyData;

char *encode_proxy_auth_str(AyProxyData *proxy);
int ay_recv_line(int sockfd, char **inputline);
void debug_print(const char *msg);
void g_free(void *ptr);