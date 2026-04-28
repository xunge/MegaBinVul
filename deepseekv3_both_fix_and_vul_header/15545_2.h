#include <stdlib.h>
#include <stdatomic.h>

#define FIO_TLS_WEAK __attribute__((weak))

typedef struct alpn_list_s {
    // dummy definition
    void *data;
} alpn_list_s;

typedef struct cert_ary_s {
    // dummy definition
    void *data;
} cert_ary_s;

typedef struct trust_ary_s {
    // dummy definition
    void *data;
} trust_ary_s;

typedef struct fio_tls_s {
    _Atomic int ref;
    alpn_list_s alpn;
    cert_ary_s sni;
    trust_ary_s trust;
} fio_tls_s;

void REQUIRE_LIBRARY(void);
int fio_atomic_sub(_Atomic int *ptr, int val);
void fio_tls_destroy_context(fio_tls_s *tls);
void alpn_list_free(alpn_list_s *alpn);
void cert_ary_free(cert_ary_s *sni);
void trust_ary_free(trust_ary_s *trust);