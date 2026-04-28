#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <stdio.h>
#include <string.h>

#define MAXPATHLEN 256
#define IS_UDP(x) ((x) == 1)

typedef struct {
    int transport;
} conn;