#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>

typedef uint32_t ProtocolVersion;
typedef int32_t int32;
typedef void* MemoryContext;

#define STATUS_ERROR (-1)
#define STATUS_OK 0
#define MAX_STARTUP_PACKET_LENGTH (1024)
#define CANCEL_REQUEST_CODE (80877102)
#define NEGOTIATE_SSL_CODE (80877103)
#define NEGOTIATE_GSS_CODE (80877104)
#define NAMEDATALEN 64
#define EOF (-1)
#define EINTR 4

#define COMMERROR 1
#define FATAL 2

#define ERRCODE_PROTOCOL_VIOLATION 1
#define ERRCODE_FEATURE_NOT_SUPPORTED 2
#define ERRCODE_INVALID_PARAMETER_VALUE 3
#define ERRCODE_INVALID_AUTHORIZATION_SPECIFICATION 4
#define ERRCODE_CANNOT_CONNECT_NOW 5
#define ERRCODE_TOO_MANY_CONNECTIONS 6

#define PG_PROTOCOL_MAJOR(v) ((v) >> 16)
#define PG_PROTOCOL_MINOR(v) ((v) & 0x0000ffff)
#define PG_PROTOCOL_EARLIEST 0
#define PG_PROTOCOL_LATEST 0

#define NIL NULL

typedef enum BackendType {
    B_BACKEND,
    B_WAL_SENDER
} BackendType;

typedef enum CAC_state {
    CAC_STARTUP,
    CAC_NOTCONSISTENT,
    CAC_SHUTDOWN,
    CAC_RECOVERY,
    CAC_TOOMANY,
    CAC_SUPERUSER,
    CAC_OK
} CAC_state;

typedef struct List List;
typedef struct Port {
    ProtocolVersion proto;
    int sock;
    struct {
        struct {
            int ss_family;
        } addr;
    } laddr;
    char *database_name;
    char *user_name;
    char *cmdline_options;
    List *guc_options;
    char *application_name;
    CAC_state canAcceptConnections;
} Port;

typedef struct {
    int elevel;
    int errcode;
    const char *message;
    const char *detail;
    const char *hint;
} ErrorData;

extern BackendType MyBackendType;
extern bool am_walsender;
extern bool am_db_walsender;
extern bool Db_user_namespace;
extern bool EnableHotStandby;
extern bool LoadedSSL;
extern ProtocolVersion FrontendProtocol;
extern MemoryContext TopMemoryContext;

void pq_startmsgread(void);
int pq_getbytes(char *s, size_t len);
void pq_endmsgread(void);
uint32_t pg_ntoh32(uint32_t net);
void *palloc(size_t size);
void processCancelRequest(Port *port, char *buf);
void ereport(int elevel, ErrorData *edata);
int errcode(int code);
const char *errmsg(const char *fmt, ...);
const char *errdetail(const char *fmt, ...);
const char *errhint(const char *fmt, ...);
int errcode_for_socket_access(void);
bool parse_bool(const char *value, bool *result);
char *pstrdup(const char *in);
char *psprintf(const char *fmt, ...);
void pg_clean_ascii(char *str);
void SendNegotiateProtocolVersion(List *options);
List *lappend(List *list, void *datum);
void *MemoryContextSwitchTo(void *context);