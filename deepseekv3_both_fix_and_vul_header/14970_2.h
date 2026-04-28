#include <sys/socket.h>
#include <netinet/in.h>

extern int __find_callno(unsigned short callno, unsigned short dcallno, struct sockaddr_in *sin, int new, int sockfd, int, ...);