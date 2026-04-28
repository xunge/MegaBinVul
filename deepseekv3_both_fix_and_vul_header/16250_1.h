#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <syslog.h>

#define TAC_PLUS_ACCT_FLAG_START 1
#define TAC_PLUS_ACCT_FLAG_STOP 2
#define TAC_PLUS_ACCT_STATUS_SUCCESS 0

struct tac_attrib {
    /* dummy structure definition */
    int dummy;
};

struct areply {
    char *msg;
};

extern unsigned short task_id;
extern char tac_service[];
extern char tac_protocol[];

void *xcalloc(size_t nmemb, size_t size);
void tac_add_attrib(struct tac_attrib **attr, const char *name, const char *value);
void tac_free_attrib(struct tac_attrib **attr);
int tac_acct_send(int tac_fd, int type, const char *user, char *tty, char *r_addr, struct tac_attrib *attr);
int tac_acct_read(int tac_fd, struct areply *re);
const char *tac_acct_flag2str(int type);
void _pam_log(int priority, const char *format, ...);