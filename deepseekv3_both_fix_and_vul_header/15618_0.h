#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct coap_str_const_t {
  const uint8_t *s;
  size_t length;
} coap_str_const_t;

typedef struct oscore_value_t {
  enum {
    COAP_ENC_ASCII,
    COAP_ENC_HEX,
    COAP_ENC_INTEGER,
    COAP_ENC_TEXT,
    COAP_ENC_BOOL,
    COAP_ENC_LAST
  } encoding;
  const char *encoding_name;
  union {
    const void *value_bin;
    int value_int;
    coap_str_const_t value_str;
  } u;
} oscore_value_t;

typedef struct {
  coap_str_const_t name;
  int encoding;
} oscore_encoding_entry_t;

extern oscore_encoding_entry_t oscore_encoding[];
extern void *coap_new_bin_const(const uint8_t *data, size_t size);
extern void *parse_hex_bin(const char *begin, const char *end);
extern int coap_string_equal(const coap_str_const_t *string1, const coap_str_const_t *string2);
extern void coap_log_warn(const char *format, ...);