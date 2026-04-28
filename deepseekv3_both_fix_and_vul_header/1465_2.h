#include <stdint.h>
#include <stddef.h>

#define _PUBLIC_
#define GNUTLS_RND_NONCE 0
#define __location__ ""
#define __func__ ""

int gnutls_rnd(int type, void *data, size_t len);
void genrand_panic(int ret, const char *location, const char *func);