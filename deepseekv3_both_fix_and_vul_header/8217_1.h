#include <stddef.h>

enum entity_charset {
    ENTITY_CHARSET_UTF8,
    ENTITY_CHARSET_OTHER
};

typedef enum {
    SUCCESS,
    FAILURE
} status_t;

typedef struct {
    const char *entity;
    size_t entity_len;
} entity_entry;

typedef struct {
    unsigned second_cp;
    const unsigned char *entity;
    size_t entity_len;
} entity_multicodepoint_normal_entry;

typedef struct {
    const unsigned char *default_entity;
    size_t default_entity_len;
    unsigned size;
} entity_multicodepoint_leading_entry;

typedef struct {
    entity_multicodepoint_leading_entry leading_entry;
    entity_multicodepoint_normal_entry normal_entry;
} entity_multicodepoint_row;

typedef union {
    entity_entry ent;
    entity_multicodepoint_row multicodepoint_table[2];
} entity_stage3_row_data;

typedef struct {
    unsigned ambiguous;
    entity_stage3_row_data data;
} entity_stage3_row;

typedef entity_stage3_row entity_stage1_row[30][64][64];

#define ENT_STAGE1_INDEX(k) ((k) >> 12)
#define ENT_STAGE2_INDEX(k) (((k) >> 6) & 0x3F)
#define ENT_STAGE3_INDEX(k) ((k) & 0x3F)

unsigned get_next_char(enum entity_charset charset, const unsigned char *old, size_t oldlen, size_t *cursor, int *status);