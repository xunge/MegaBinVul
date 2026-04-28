#include <stddef.h>

typedef struct gnutls_session_int *gnutls_session_t;
typedef struct {
    int entity;
} security_parameters_st;
typedef struct {
    int initial_negotiation_completed;
    int hsk_flags;
} internals_st;
struct gnutls_session_int {
    security_parameters_st security_parameters;
    internals_st internals;
};

#define GNUTLS_E_WARNING_ALERT_RECEIVED 1
#define GNUTLS_E_GOT_APPLICATION_DATA 2
#define GNUTLS_E_UNEXPECTED_PACKET 3
#define GNUTLS_E_INTERNAL_ERROR 4
#define GNUTLS_A_NO_RENEGOTIATION 5
#define GNUTLS_SERVER 6
#define HSK_SERVER_HELLO_RECEIVED 7

#define STATE0 0
extern int STATE;

int gnutls_alert_get(gnutls_session_t session);
int gnutls_assert_val(int x);