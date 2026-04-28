#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct janus_network_address janus_network_address;
typedef struct multiple_fds multiple_fds;

#define LOG_VERB 0
#define LOG_ERR 1
#define JANUS_LOG(level, format, ...) printf(format, ##__VA_ARGS__)

#define gulong unsigned long
#define g_snprintf snprintf
#define IN_MULTICAST(x) (((x) & 0xf0000000) == 0xe0000000)