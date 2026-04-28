#include <stddef.h>

struct dns_context {
    unsigned char *ptr;
};

static int _dns_get_domain_offset(struct dns_context *context, const char *domain);
static void _dns_write_short(unsigned char **ptr, int value);
static int _dns_left_len(struct dns_context *context);