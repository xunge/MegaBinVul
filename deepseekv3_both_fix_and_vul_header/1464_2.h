#include <stdint.h>
#include <stddef.h>

#define _PUBLIC_ 
#define __location__ ""
#define __func__ ""
#define GNUTLS_RND_RANDOM 0

int gnutls_rnd(int type, void *data, size_t len);
void genrand_panic(int ret, const char *location, const char *func);