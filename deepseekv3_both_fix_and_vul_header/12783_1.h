#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

struct curl_slist {
    char *data;
    struct curl_slist *next;
};

struct connectdata {
    int sock[1];
};

struct TELNET {
    unsigned char *subbuffer;
    char *subopt_ttype;
    char *subopt_xdisploc;
    struct curl_slist *telnet_vars;
};

struct Curl_easy {
    struct {
        struct {
            struct TELNET *telnet;
        } p;
    } req;
    struct connectdata *conn;
};

#define CURL_SB_LEN(tn) (0)
#define CURL_SB_GET(tn) (0)
#define CURL_IAC 0xFF
#define CURL_SB 0xFA
#define CURL_SE 0xF0
#define CURL_TELOPT_TTYPE 0x18
#define CURL_TELOPT_XDISPLOC 0x1F
#define CURL_TELOPT_NEW_ENVIRON 0x27
#define CURL_TELQUAL_IS 0
#define CURL_NEW_ENV_VAR 0
#define CURL_NEW_ENV_VALUE 0
#define FIRSTSOCKET 0
#define SOCKERRNO errno

void printsub(struct Curl_easy *data, char direction, unsigned char *ptr, size_t len);
void failf(struct Curl_easy *data, const char *fmt, ...);
ssize_t swrite(int fd, const void *buf, size_t count);
int msnprintf(char *buffer, size_t maxlength, const char *format, ...);