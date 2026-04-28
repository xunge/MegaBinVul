#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <assert.h>

#define S_HELLO_LEN 7
#define S_CMD_INET_CHECK 1
#define S_CMD_PACKET 2

extern int last_id;
extern int wrap;
extern int ids[256];
extern int is_dup(int last_id);