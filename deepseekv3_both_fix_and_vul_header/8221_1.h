#include <stddef.h>

#define PHPAPI
#define TSRMLS_DC
#define TSRMLS_CC
#define TRAVERSE_FOR_ENTITIES_EXPAND_SIZE(oldlen) ((oldlen) * 2)

typedef enum entity_charset {
    cs_8859_1
} entity_charset;

typedef struct entity_ht entity_ht;

extern char *estrndup(const char *s, size_t length);
extern void *emalloc(size_t size);
extern entity_charset determine_charset(char *hint_charset TSRMLS_DC);
extern const entity_ht *unescape_inverse_map(int all, int flags);
extern void traverse_for_entities(unsigned char *old, size_t oldlen, char *ret, size_t *retlen, int all, int flags, const entity_ht *inverse_map, entity_charset charset);