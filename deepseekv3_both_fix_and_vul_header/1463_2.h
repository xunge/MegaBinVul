#include <stdint.h>
#include <stddef.h>

#define _PUBLIC_
#define GNUTLS_RND_KEY 0
#define __location__ ""
#define __func__ ""

typedef int gnutls_rnd_t;
extern int gnutls_rnd(gnutls_rnd_t type, void *data, size_t len);
extern void genrand_panic(int ret, const char *location, const char *func);