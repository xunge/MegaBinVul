#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define MANADDR_ALL802 1
#define MANADDR_IPV4 2
#define MANADDR_IPV6 3

#define IFNUM_UNKNOWN 0
#define IFNUM_IFINDEX 1
#define IFNUM_SYS_PORT_NUM 2

extern int hexstr2bin(const char *hex, u8 *buf, size_t len);