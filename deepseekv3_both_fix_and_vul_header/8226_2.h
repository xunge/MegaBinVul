#include <assert.h>
#include <stddef.h>

#define FAILURE (-1)
#define ENT_HTML_DOC_TYPE_MASK 0xF
#define ENT_HTML_DOC_HTML5 0
#define ENT_HTML_DOC_XHTML 1
#define ENT_HTML_QUOTE_SINGLE (1<<0)
#define ENT_HTML_QUOTE_DOUBLE (1<<1)

typedef struct {
    struct {
        struct {
            const char *entity;
        } ent;
    } data;
} stage3_table_entry;

extern stage3_table_entry stage3_table_be_apos_00000[64];

typedef struct entity_ht entity_ht;

enum entity_charset {
    cs_utf_8
};

extern int process_numeric_entity(const char **next, unsigned *code);
extern int process_named_entity_html(const char **next, const char **start, size_t *ent_len);
extern int resolve_named_entity_html(const char *start, size_t ent_len, const entity_ht *inv_map, unsigned *code, unsigned *code2);
extern int unicode_cp_is_allowed(unsigned code, int doctype);
extern int map_from_unicode(unsigned code, enum entity_charset charset, unsigned *out);
extern size_t write_octet_sequence(char *q, enum entity_charset charset, unsigned code);