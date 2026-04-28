#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <sys/types.h>
#include <limits.h>

#define BUFSIZE 4096
#define NBD_REPLY_MAGIC 0x67446698
#define NBD_REQUEST_MAGIC 0x25609513
#define NBD_CMD_DISC 2
#define NBD_CMD_WRITE 1
#define EINVAL 22
#define EPERM 1
#define TRUE 1
#define FALSE 0
#define LOG_INFO 0
#define F_COPYONWRITE (1 << 0)
#define F_READONLY (1 << 1)
#define F_AUTOREADONLY (1 << 2)

typedef int gboolean;

struct nbd_request {
    uint32_t magic;
    uint32_t type;
    char handle[8];
    uint64_t from;
    uint32_t len;
};

struct nbd_reply {
    uint32_t magic;
    uint32_t error;
    char handle[8];
};

typedef struct {
    int net;
    struct {
        unsigned int flags;
    } *server;
    void *difmap;
    int difffile;
    char *difffilename;
    off_t exportsize;
} CLIENT;

#define OFFT_MAX (~((off_t)0))

uint64_t ntohll(uint64_t netlonglong);
void negotiate(int net, CLIENT *client, void *arg);
void readit(int net, void *buf, size_t len);
void writeit(int net, void *buf, size_t len);
void SEND(int net, struct nbd_reply reply);
void DEBUG(const char *fmt, ...);
void msg2(int level, const char *fmt, ...);
void err(const char *fmt, ...);
void ERROR(CLIENT *client, struct nbd_reply reply, int error);
int expread(uint64_t from, char *buf, size_t len, CLIENT *client);
int expwrite(uint64_t from, char *buf, size_t len, CLIENT *client);