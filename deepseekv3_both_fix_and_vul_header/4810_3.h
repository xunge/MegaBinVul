#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/icmp6.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

struct ndp {
    int sock;
};

#define err(ndp, msg) perror(msg)