#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

typedef struct _XML_Entity {
    char *name;
    uint32_t namelen;
    char sep;
    char *value;
} XML_Entity;

typedef struct _GF_SAXParser {
    char *buffer;
    uint32_t current_pos;
    uint32_t line_size;
    uint32_t line;
    uint32_t sax_state;
    void *entities;
} GF_SAXParser;

#define GF_SAFEALLOC(ptr, type) \
    ptr = (type *)malloc(sizeof(type)); \
    if (ptr) memset(ptr, 0, sizeof(type));

void gf_dynstrcat(char **dst, const char *src, void *unused);
void gf_free(void *ptr);
void *gf_list_last(void *list);
void gf_list_add(void *list, void *item);
char *gf_strdup(const char *str);
void xml_sax_store_text(GF_SAXParser *parser, uint32_t i);
void xml_sax_swap(GF_SAXParser *parser);
char *xml_get_current_text(GF_SAXParser *parser);

enum {
    SAX_STATE_SKIP_DOCTYPE,
    SAX_STATE_ALLOC_ERROR,
    SAX_STATE_SYNTAX_ERROR
};

typedef uint8_t u8;
typedef uint32_t u32;