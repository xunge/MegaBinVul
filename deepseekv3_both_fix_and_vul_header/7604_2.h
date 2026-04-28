#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct sc_context sc_context_t;
typedef struct sc_card sc_card_t;
typedef struct sc_file sc_file_t;
typedef struct sc_pkcs15_card sc_pkcs15_card_t;

struct sc_pkcs15_auth_info {
    unsigned char auth_type;
    struct {
        struct {
            unsigned char reference;
            unsigned char flags;
            unsigned char type;
            unsigned char min_length;
            unsigned char stored_length;
            unsigned char max_length;
            char pad_char;
        } pin;
    } attrs;
    struct {
        unsigned char len;
        unsigned char value[1];
    } auth_id;
    struct {
        unsigned char len;
        unsigned char value[256];
    } path;
    int tries_left;
    int logged_in;
};

struct sc_pkcs15_object {
    char label[64];
    unsigned int flags;
    struct {
        unsigned char len;
        unsigned char value[1];
    } auth_id;
};

struct sc_context;
struct sc_card {
    int type;
    sc_context_t *ctx;
};
struct sc_file {
    unsigned char *prop_attr;
    size_t prop_attr_len;
};
struct sc_pkcs15_card {
    sc_card_t *card;
};

#define SC_CARD_TYPE_TCOS_V3 1
#define SC_PKCS15_PIN_AUTH_TYPE_PIN 1
#define SC_PKCS15_PIN_TYPE_ASCII_NUMERIC 1
#define SC_PKCS15_CO_FLAG_MODIFIABLE 1
#define SC_PKCS15_CO_FLAG_PRIVATE 2
#define SC_PIN_STATE_UNKNOWN 0
#define SC_SUCCESS 0
#define SC_RECORD_BY_REC_NR 0

int sc_pkcs15emu_add_pin_obj(sc_pkcs15_card_t *, struct sc_pkcs15_object *, struct sc_pkcs15_auth_info *);
void sc_format_path(const char *, struct sc_pkcs15_auth_info *);
void sc_append_file_id(struct sc_pkcs15_auth_info *, unsigned short);
int sc_select_file(sc_card_t *, struct sc_pkcs15_auth_info *, sc_file_t **);
int sc_read_record(sc_card_t *, int, unsigned char *, size_t, int);
void sc_log(sc_context_t *, const char *, ...);
void sc_file_free(sc_file_t *);
char *sc_print_path(struct sc_pkcs15_auth_info *);

static inline size_t strlcpy(char *dst, const char *src, size_t size) {
    size_t src_len = strlen(src);
    if (size) {
        size_t len = (src_len >= size) ? size - 1 : src_len;
        memcpy(dst, src, len);
        dst[len] = '\0';
    }
    return src_len;
}