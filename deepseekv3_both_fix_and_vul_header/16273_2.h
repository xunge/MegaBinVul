#include <stdint.h>
#include <stddef.h>

typedef int krb5_error_code;

typedef struct asn1buf {
    /* structure definition not provided */
} asn1buf;

typedef struct taginfo {
    /* structure definition not provided */
} taginfo;

#define ASN1_BAD_LENGTH 1

krb5_error_code get_tag(const uint8_t *der, size_t len, taginfo *tag_out,
                        const uint8_t **contents, size_t *clen,
                        const uint8_t **remainder, size_t *rlen, ...);

void insert_bytes(asn1buf *buf, const uint8_t *contents, size_t clen);