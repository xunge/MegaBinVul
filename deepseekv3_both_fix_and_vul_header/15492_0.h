#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HEADER_SIZE 8192
#define MAX_BODY_SIZE 8192
#define MAX_HTTP_METHOD_LEN 16
#define MAX_HTTP_URI_LEN 2048
#define MAX_HEADER_FIELDS 128
#define EAGAIN 11
#define EWOULDBLOCK 11

typedef int SOCKET;

typedef struct {
    char *key;
    char *value;
} HTTPHeaderField;

typedef struct {
    char *Method;
    char *URI;
    char *Version;
    HTTPHeaderField Fields[MAX_HEADER_FIELDS];
    int Amount;
} HTTPHeader;

typedef struct {
    char _buf[MAX_HEADER_SIZE + MAX_BODY_SIZE];
    int _index;
    HTTPHeader Header;
} HTTPReqMessage;

typedef struct {
    SOCKET clisock;
    HTTPReqMessage req;
    int work_state;
} HTTPReq;

#define CLOSE_SOCKET 0

int HaveMethod(char *method);
int _CheckLine(char *line);
int _CheckFieldSep(char *sep);
void DebugMsg(const char *msg);