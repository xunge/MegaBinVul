#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <dlfcn.h>

struct sshsk_provider {
    char *path;
    void *dlhandle;
    uint32_t (*sk_api_version)(void);
    int (*sk_enroll)(void);
    int (*sk_sign)(void);
    int (*sk_load_resident_keys)(void);
};

#define SSH_SK_VERSION_MAJOR 0x00010000
#define SSH_SK_VERSION_MAJOR_MASK 0xffff0000

extern void error(const char *fmt, ...);
extern void error_f(const char *fmt, ...);
extern void debug_f(const char *fmt, ...);
extern int ssh_sk_enroll(void);
extern int ssh_sk_sign(void);
extern int ssh_sk_load_resident_keys(void);
extern void sshsk_free(struct sshsk_provider *p);