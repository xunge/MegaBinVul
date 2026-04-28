#include <stddef.h>

typedef struct DSA_SIG_st DSA_SIG;
typedef struct dsa_st DSA;

DSA_SIG *DSA_SIG_new(void);
void DSA_SIG_free(DSA_SIG *sig);
DSA_SIG *d2i_DSA_SIG(DSA_SIG **sig, const unsigned char **pp, long length);
int DSA_do_verify(const unsigned char *dgst, int dgst_len, DSA_SIG *sig, DSA *dsa);