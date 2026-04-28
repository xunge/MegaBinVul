#include <stddef.h>

typedef struct EC_KEY EC_KEY;
typedef struct ECDSA_SIG ECDSA_SIG;

ECDSA_SIG *ECDSA_SIG_new(void);
void ECDSA_SIG_free(ECDSA_SIG *sig);
ECDSA_SIG *d2i_ECDSA_SIG(ECDSA_SIG **sig, const unsigned char **pp, long len);
int ECDSA_do_verify(const unsigned char *dgst, int dgst_len, const ECDSA_SIG *sig, EC_KEY *eckey);