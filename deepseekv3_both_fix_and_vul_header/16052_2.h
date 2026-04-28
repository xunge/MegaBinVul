#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

typedef struct coap_str_const_t {
  const unsigned char *s;
  size_t length;
} coap_str_const_t;

typedef struct coap_bin_const_t {
  const unsigned char *s;
  size_t length;
} coap_bin_const_t;

typedef struct oscore_value_t {
  union {
    coap_bin_const_t *value_bin;
    int value_int;
    coap_str_const_t value_str;
  } u;
  int encoding;
  const char *encoding_name;
} oscore_value_t;

typedef struct coap_oscore_conf_t {
  coap_bin_const_t *master_secret;
  coap_bin_const_t *sender_id;
  coap_bin_const_t **recipient_id;
  size_t recipient_id_count;
  uint32_t replay_window;
  uint32_t ssn_freq;
  int aead_alg;
  int hkdf_alg;
  int rfc8613_b_1_2;
  int rfc8613_b_2;
  int break_sender_key;
  int break_recipient_key;
} coap_oscore_conf_t;

typedef struct {
  const char *keyword;
  coap_str_const_t str_keyword;
  int encoding;
  size_t offset;
  struct {
    const char *text;
    int value;
  } text_mapping[];
} oscore_config_entry_t;

extern oscore_config_entry_t oscore_config[1];

extern void *coap_malloc_type(int type, size_t size);
extern void *coap_realloc_type(int type, void *ptr, size_t size);
extern void coap_delete_bin_const(coap_bin_const_t *bin);
extern void coap_delete_oscore_conf(coap_oscore_conf_t *conf);
extern int coap_string_equal(const coap_str_const_t *str1, const coap_str_const_t *str2);
extern const coap_str_const_t *coap_make_str_const(const char *str);
extern void coap_log_warn(const char *format, ...);

#define COAP_STRING 0
#define COAP_OSCORE_DEFAULT_REPLAY_WINDOW 32
#define COSE_ALGORITHM_AES_CCM_16_64_128 10
#define COSE_HKDF_ALG_HKDF_SHA_256 5

enum {
  COAP_ENC_HEX,
  COAP_ENC_ASCII,
  COAP_ENC_INTEGER,
  COAP_ENC_BOOL,
  COAP_ENC_TEXT,
  COAP_ENC_LAST
};

extern int get_split_entry(const char **start, size_t length, coap_str_const_t *keyword, oscore_value_t *value);