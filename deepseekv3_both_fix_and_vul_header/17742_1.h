#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <limits.h>
#include <syslog.h>

#define TAC_PLUS_MAXSERVERS 10
#define PAM_TAC_DEBUG 0x01
#define PAM_TAC_USE_FIRST_PASS 0x02
#define PAM_TAC_TRY_FIRST_PASS 0x04
#define PAM_TAC_ACCT 0x08

typedef struct {
    struct addrinfo *addr;
    char *key;
} tacplus_server_t;

extern tacplus_server_t tac_srv[TAC_PLUS_MAXSERVERS];
extern struct addrinfo tac_srv_addr[TAC_PLUS_MAXSERVERS];
extern struct sockaddr tac_sock_addr[TAC_PLUS_MAXSERVERS];
extern struct sockaddr_in6 tac_sock6_addr[TAC_PLUS_MAXSERVERS];
extern int tac_srv_no;
extern char tac_service[256];
extern char tac_protocol[256];
extern char tac_prompt[256];
extern char tac_login[256];
extern long tac_timeout;
extern int tac_readtimeout_enable;

void _pam_log(int level, const char *fmt, ...);
void xstrcpy(char *dest, const char *src, size_t size);
void set_tac_srv_addr(int index, struct addrinfo *server);
void set_tac_srv_key(int index, const char *key);
const char *tac_ntop(const struct sockaddr *addr);