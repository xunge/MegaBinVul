#include <string.h>

struct credential {
    char *username;
    char *password;
    char *protocol;
    char *host;
    char *path;
};

extern void credential_clear(struct credential *);
extern char *url_decode_mem(const char *, size_t);
extern char *xmemdupz(const void *, size_t);
extern char *url_decode(const char *);
extern int check_url_component(const char *, int, const char *, const char *);