#include <stdint.h>
#include <string.h>
#include <sys/types.h>

#define MAX_SERVER_NAME_SIZE 256
#define MAX_SERVER_NAME_EXTENSIONS 10
#define GNUTLS_SERVER 1
#define GNUTLS_NAME_DNS 0

typedef unsigned char opaque;

typedef struct {
    int type;
    size_t name_length;
    char name[MAX_SERVER_NAME_SIZE];
} server_name_t;

typedef struct {
    int server_names_size;
    server_name_t server_names[MAX_SERVER_NAME_EXTENSIONS];
} extensions_t;

typedef struct {
    int entity;
    extensions_t extensions;
} security_parameters_t;

typedef struct gnutls_session_int {
    security_parameters_t security_parameters;
} *gnutls_session_t;

#define DECR_LENGTH_RET(a, b, c) if ((a) < (b)) return (c); else (a) -= (b)
#define DECR_LEN(a, b) (a) -= (b)

ssize_t _gnutls_read_uint16(const opaque *data);
void gnutls_assert(void);