#include <stdlib.h>

typedef int krb5_error_code;
typedef enum {
    otp_response_success
} otp_response;

struct request_state {
    struct {
        int flags;
    } *enc_tkt_reply;
    void (*respond)(void *, krb5_error_code, void *, void *, void *);
    void *arg;
};

#define KRB5_PREAUTH_FAILED (-1)
#define TKT_FLG_PRE_AUTH 0