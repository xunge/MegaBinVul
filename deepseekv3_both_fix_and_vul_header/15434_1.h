#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

typedef int SOCK_RET;
typedef struct PNVCTL_TCP_PACKET_HEADER {
    short type;
    short payloadLength;
} *PNVCTL_TCP_PACKET_HEADER;

extern int ctlSock;
extern int ServerMajorVersion;
#define LC_ASSERT(cond)