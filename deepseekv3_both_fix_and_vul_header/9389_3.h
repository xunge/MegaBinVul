#include <stdlib.h>

typedef struct srtp_protection_profile_st {
    int id;
} SRTP_PROTECTION_PROFILE;

typedef struct stack_st_SRTP_PROTECTION_PROFILE {
    SRTP_PROTECTION_PROFILE **data;
    int num;
} STACK_OF_SRTP_PROTECTION_PROFILE;
#define STACK_OF(SRTP_PROTECTION_PROFILE) STACK_OF_SRTP_PROTECTION_PROFILE

struct ssl_st {
    SRTP_PROTECTION_PROFILE *srtp_profile;
};
typedef struct ssl_st SSL;

#define SSL_F_SSL_PARSE_CLIENTHELLO_USE_SRTP_EXT 0
#define SSL_R_BAD_SRTP_PROTECTION_PROFILE_LIST 0
#define SSL_R_BAD_SRTP_MKI_VALUE 0
#define SSL_AD_DECODE_ERROR 0

#define n2s(c,s) do { \
    (s) = ((unsigned int)((c)[0]) << 8) | (unsigned int)((c)[1]); \
    (c) += 2; \
} while(0)

STACK_OF_SRTP_PROTECTION_PROFILE *sk_SRTP_PROTECTION_PROFILE_new_null(void);
void sk_SRTP_PROTECTION_PROFILE_free(STACK_OF_SRTP_PROTECTION_PROFILE *sk);
int sk_SRTP_PROTECTION_PROFILE_push(STACK_OF_SRTP_PROTECTION_PROFILE *sk, SRTP_PROTECTION_PROFILE *p);
int sk_SRTP_PROTECTION_PROFILE_num(STACK_OF_SRTP_PROTECTION_PROFILE *sk);
SRTP_PROTECTION_PROFILE *sk_SRTP_PROTECTION_PROFILE_value(STACK_OF_SRTP_PROTECTION_PROFILE *sk, int idx);
int find_profile_by_num(int id, SRTP_PROTECTION_PROFILE **prof);
STACK_OF_SRTP_PROTECTION_PROFILE *SSL_get_srtp_profiles(SSL *s);
void SSLerr(int func, int reason);