#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <mutex>

#define assertx(expr) ((void)0)

extern "C" {
    char *crypt(const char *key, const char *salt);
    int php_crypt_blowfish_rn(const char *key, const char *salt, char *output, int size);
    char *php_crypt_r(const char *key, const char *salt);
}

void ito64(char *s, long v, int n);
char *strdup(const char *s);

using Mutex = std::mutex;
using Lock = std::lock_guard<std::mutex>;