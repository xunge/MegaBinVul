#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

#define LINESIZE 8192
#define STRING_S 0
#define ADMIN 0
#define NONE 0
#define TYPE_SERVER 0
#define WEBBANNERS 0
#define CLIENT 0

#define PRINTF_INT64_MODIFIER "ll"

struct clientparam {
    unsigned char *username;
    unsigned char *password;
    int operation;
    int redirected;
    struct {
        int (*authfunc)(struct clientparam *);
        int singlepacket;
        void (*logfunc)(struct clientparam *, unsigned char *);
    } *srv;
};

struct printparam {
    int inbuf;
    struct clientparam *cp;
};

struct trafcount {
    struct trafcount *next;
    char *comment;
    int disabled;
    struct {
        char *users;
        char *src;
        char *dst;
        char *ports;
    } *ace;
    int type;
    uint64_t traflim64;
    uint64_t traf64;
    time_t cleared;
    time_t updated;
    int number;
};

struct {
    int timeouts[1];
    char **stringtable;
    struct trafcount *trafcounter;
    int needreload;
    int services;
} conf;

#define RETURN(x) do { res = x; goto CLEANRET; } while(0)

char *myalloc(int size);
void myfree(void *ptr);
char *mystrdup(const char *s);
int sockgetlinebuf(struct clientparam *param, int client, unsigned char *buf, int size, char delim, int timeout);
int de64(unsigned char *src, unsigned char *dst, int maxlen);
int ACLmatches(void *ace, struct clientparam *param);
int printuserlist(char *buf, int size, char *users, const char *sep);
int printiplist(char *buf, int size, char *iplist, const char *sep);
int printportlist(char *buf, int size, char *ports, const char *sep);
void printstr(struct printparam *pp, const char *str);
void stdpr(struct printparam *pp, void *ptr, int len);
void printval(int services, int type, int flag, struct printparam *pp);
void decodeurl(unsigned char *str, int flag);
void freeparam(struct clientparam *param);

FILE *confopen(void);
FILE *writable;

const char *ok = "";
const char *authreq = "";
const char *counters = "";
const char *counterstail = "";
const char *style = "";
const char *xml = "";
const char *postxml = "";
const char *tail = "";
const char *rotations[] = {""};