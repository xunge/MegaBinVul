#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include <netdb.h>
#include <stdarg.h>

#define COMPLETE 1
#define ERROR -1

extern int passivemode;
extern int options;
extern int doepsv4;
extern int sendport;
extern int data;
extern char *pasv;
extern struct sockaddr_storage myctladdr;
extern struct sockaddr_storage hisctladdr;
extern struct sockaddr_storage data_addr;
extern socklen_t ctladdrlen;
extern char ia[INET6_ADDRSTRLEN];
extern char portstr[6];

int command(const char *format, ...);
void error(int status, int errnum, const char *format);