#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    HEAD_AGAIN,
    HEAD_OK,
    HEAD_HANDLED
} HeadReturn;

typedef enum {
    AGOO_GET,
    AGOO_PUT,
    AGOO_POST,
    AGOO_DELETE,
    AGOO_HEAD,
    AGOO_OPTIONS,
    AGOO_CONNECT
} agooMethod;

typedef enum {
    AGOO_UP_NONE
} agooUpgrade;

struct _agooSeg {
    char *start;
    char *end;
    int len;
};

struct _agooErr {
    int code;
    char *msg;
};

struct _agooReq {
    char *msg;
    agooMethod method;
    agooUpgrade upgrade;
    void *up;
    struct _agooSeg path;
    struct _agooSeg query;
    struct _agooSeg body;
    struct _agooSeg header;
    void *res;
    void *hook;
    char remote[1];
};

struct _agooBind {
    int kind;
};

struct _agooCon {
    char buf[8192];
    size_t bcnt;
    struct _agooReq *req;
    struct _agooBind *bind;
    unsigned long long id;
    char remote[1];
};

typedef struct _agooCon *agooCon;
typedef struct _agooReq *agooReq;
typedef void *agooHook;
typedef void *agooPage;

struct {
    int on;
} agoo_req_cat;

struct {
    void *hooks;
    int root_first;
    void *hook404;
} agoo_server;

#define AGOO_ERR_INIT {0, NULL}