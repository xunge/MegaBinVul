#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define XT_FUNCTION_MAXNAMELEN 32
#define XT_ALIGN(s) (((s) + (__alignof__(struct {int a;}) - 1)) & ~(__alignof__(struct {int a;}) - 1))

struct module;

struct xt_target {
    const char name[XT_FUNCTION_MAXNAMELEN];
    unsigned int targetsize;
    unsigned int (*compat_from_user)(void *dst, const void *src);
    struct module *me;
};

struct xt_entry_target {
    union {
        struct {
            uint16_t target_size;
            char name[XT_FUNCTION_MAXNAMELEN - 1];
            uint8_t revision;
        } user;
        struct {
            uint16_t target_size;
            struct xt_target *target;
        } kernel;
    } u;
    unsigned char data[0];
};

struct compat_xt_entry_target {
    union {
        struct {
            uint16_t target_size;
            uint16_t __pad1;
            char name[XT_FUNCTION_MAXNAMELEN - 1];
            uint8_t revision;
            uint8_t __pad2;
        } user;
    } u;
    unsigned char data[0];
};

static inline unsigned int xt_compat_target_offset(const struct xt_target *target) { return 0; }
static inline void module_put(struct module *mod) { (void)mod; }
static inline void strlcpy(char *dest, const char *src, size_t size) { strncpy(dest, src, size); }