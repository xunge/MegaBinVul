#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct ftpbuf_t {
    int fd;
    int pasv;
    char inbuf[1024];
    int resp;
    struct sockaddr_storage pasvaddr;
} ftpbuf_t;

union ipbox {
    unsigned char c[4];
    unsigned short s[2];
    struct in_addr ia[1];
};