#include <string.h>

typedef enum {
    http_auth_basic,
    http_auth_digest
} cherokee_http_auth_t;

typedef enum {
    ret_ok,
    ret_error
} ret_t;

typedef unsigned int cuint_t;

typedef struct {
    int req_auth_type;
} cherokee_connection_t;

typedef struct {
    char nonce[256]; // Assuming nonce is a buffer, adjust size as needed
} cherokee_validator_t;

#define CHR_CR '\r'
#define CHR_LF '\n'

#define LOG_ERROR_S(x)
#define CHEROKEE_ERROR_CONNECTION_AUTH 0

static int equal_str(const char *a, const char *b);
static char *cherokee_min_str(char *a, char *b);
static int cherokee_buffer_is_empty(char *buf);
static ret_t cherokee_validator_parse_basic(cherokee_validator_t *validator, char *ptr, int ptr_len);
static ret_t cherokee_validator_parse_digest(cherokee_validator_t *validator, char *ptr, int ptr_len);