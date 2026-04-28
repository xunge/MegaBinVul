#include <string.h>
#include <stddef.h>

typedef struct _zval_struct zval;

#define LONGEST_ENTITY_LENGTH 32
#define FAILURE (-1)
#define CHARSET_UNICODE_COMPAT(charset) (0)

enum entity_charset {
    CS_UTF8,
    CS_ISO88591
};

typedef struct entity_multicodepoint_row {
    struct {
        const char *default_entity;
        size_t default_entity_len;
        unsigned size;
    } leading_entry;
    struct {
        unsigned second_cp;
        const char *entity;
        size_t entity_len;
    } normal_entry;
} entity_multicodepoint_row;

typedef struct entity_stage3_row {
    unsigned ambiguous;
    union {
        struct {
            const char *entity;
            size_t entity_len;
        } ent;
        const entity_multicodepoint_row *multicodepoint_table;
    } data;
} entity_stage3_row;

static inline size_t write_octet_sequence(char *key, enum entity_charset charset, unsigned cp);
static inline int map_from_unicode(unsigned uni_cp, enum entity_charset charset, unsigned *spe_cp);
void add_assoc_stringl_ex(zval *arr, const char *key, size_t key_len, const char *str, size_t str_len, int dup);