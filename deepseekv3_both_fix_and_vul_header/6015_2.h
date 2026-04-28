#include <linux/module.h>
#include <linux/netfilter/x_tables.h>
#include <linux/string.h>
#include <linux/types.h>
#include <stdint.h>
#include <string.h>

typedef uint16_t u_int16_t;
typedef uint8_t u_int8_t;

struct xt_match {
    const char *name;
    void (*compat_from_user)(void *dst, const void *src);
    unsigned int matchsize;
    struct module *me;
};

struct compat_xt_entry_match {
    union {
        struct {
            u_int16_t match_size;
            char name[XT_FUNCTION_MAXNAMELEN - 1];
            u_int8_t revision;
        } user;
        struct {
            u_int16_t match_size;
            const struct xt_match *match;
        } kernel;
        u_int16_t match_size;
    } u;
    unsigned char data[0];
};

unsigned int xt_compat_match_offset(const struct xt_match *match);

#define XT_ALIGN(s) (((s) + (__alignof__(struct xt_entry_match) - 1)) & ~(__alignof__(struct xt_entry_match) - 1))