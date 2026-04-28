#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Server Server;

extern int enableSSL;
extern int forceSSL;
extern int certificateFd;
extern char *certificateDir;

void serverSetupSSL(Server *server, int enableSSL, int forceSSL);
void serverEnableSSL(Server *server, int enableSSL);
int serverSupportsSSL(void);
void serverSetCertificateFd(Server *server, int fd);
void serverSetCertificate(Server *server, const char *path, int flag);
void fatal(const char *fmt, ...);
void check(int condition);
char *stringPrintf(void *unused, const char *fmt, ...);