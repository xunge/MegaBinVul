#include <stdint.h>
#include <stddef.h>

#define AF_INET 2
#define COMPAT_CALC_SIZE 0
#define ENOENT 2

struct ipt_match;
struct ipt_ip;

struct ipt_entry_match {
    union {
        struct {
            char name[32];
            uint8_t revision;
        } user;
        struct {
            struct ipt_match *match;
        } kernel;
    } u;
};

struct ipt_match {
    int (*compat)(struct ipt_entry_match *m, void *userdata, int *size, int op);
};

static inline void *xt_find_match(int af, const char *name, uint8_t revision) { return NULL; }
static inline void *try_then_request_module(void *fn_result, const char *fmt, ...) { return NULL; }
static inline int PTR_ERR(const void *ptr) { return 0; }
static inline int IS_ERR(const void *ptr) { return 0; }
static inline void duprintf(const char *fmt, ...) {}
static inline void xt_compat_match(struct ipt_entry_match *m, void *userdata, int *size, int op) {}