#include <stdint.h>
#include <stddef.h>

typedef int krb5_error_code;

typedef struct krb5_data {
    uint8_t *data;
    size_t length;
} krb5_data;

struct atype_info;

typedef struct taginfo {
    int dummy;
} taginfo;

static inline krb5_error_code get_tag(uint8_t *data, size_t length, struct taginfo *t,
                                     const uint8_t **contents, size_t *clen,
                                     const uint8_t **remainder, size_t *rlen, ...) {
    return 0;
}

static inline int check_atype_tag(const struct atype_info *a, const struct taginfo *t) {
    return 0;
}

static inline krb5_error_code decode_atype_to_ptr(const struct taginfo *t,
                                                const uint8_t *contents, size_t clen,
                                                const struct atype_info *a, void **retrep) {
    return 0;
}

#define ASN1_BAD_ID 1