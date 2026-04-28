#include <stdlib.h>
#include <string.h>

typedef unsigned char zend_bool;
#define TSRMLS_DC
#define TSRMLS_CC
#define PHPAPI
#define SUCCESS 1
#define FAILURE 0
#define E_STRICT 0
#define E_ERROR 0
#define ENT_HTML_DOC_TYPE_MASK 0
#define ENT_HTML_IGNORE_ERRORS 0
#define ENT_HTML_SUBSTITUTE_DISALLOWED_CHARS 0
#define ENT_HTML_SUBSTITUTE_ERRORS 0
#define ENT_HTML_QUOTE_SINGLE 0
#define ENT_HTML_QUOTE_DOUBLE 0
#define ENT_HTML_DOC_XHTML 0

enum entity_charset {
    CS_UTF_8,
    cs_utf_8 = CS_UTF_8
};

typedef struct {
    const void *table;
    const void *ms_table;
} entity_table_opt;

typedef struct {
    /* structure definition not provided */
} enc_to_uni;

typedef struct {
    /* structure definition not provided */
} entity_ht;

extern const enc_to_uni *enc_to_uni_index[];
extern void php_error_docref0(const char *ref, int type, const char *format);
extern void zend_error_noreturn(int type, const char *format);
extern char *emalloc(size_t size);
extern char *safe_erealloc(void *ptr, size_t size, size_t count, size_t add);
extern void efree(void *ptr);
extern char *STR_EMPTY_ALLOC(void);
extern enum entity_charset determine_charset(char *hint_charset TSRMLS_DC);
extern entity_table_opt determine_entity_table(int all, int doctype);
extern const entity_ht *unescape_inverse_map(int arg, int flags);
extern unsigned int get_next_char(enum entity_charset charset, unsigned char *old, size_t oldlen, size_t *cursor, int *status);
extern void map_to_unicode(unsigned int c, const enc_to_uni *table, unsigned int *result);
extern void find_entity_for_char(unsigned int c, enum entity_charset charset, const void *table, const unsigned char **rep, size_t *rep_len, unsigned char *old, size_t oldlen, size_t *cursor);
extern void find_entity_for_char_basic(unsigned int c, const void *table, const unsigned char **rep, size_t *rep_len);
extern int unicode_cp_is_allowed(unsigned int cp, int doctype);
extern int process_numeric_entity(const char **pos, unsigned *code_point);
extern int process_named_entity_html(const char **next, const char **start, size_t *ent_len);
extern int resolve_named_entity_html(const char *start, size_t ent_len, const entity_ht *inv_map, unsigned *dummy1, unsigned *dummy2);
extern int numeric_entity_is_allowed(unsigned code_point, int doctype);

#define CHARSET_PARTIAL_SUPPORT(charset) 0
#define CHARSET_UNICODE_COMPAT(charset) 0
#define LIMIT_ALL(all, doctype, charset)