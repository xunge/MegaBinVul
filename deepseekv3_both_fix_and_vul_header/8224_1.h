#include <assert.h>
#include <stddef.h>

typedef struct {
    void *ms_table;
    void *table;
} entity_table_opt;

#define ENT_HTML_DOC_XML1 0
#define ENT_HTML_DOC_HTML5 1
#define ENT_HTML_DOC_HTML4 2
#define ENT_HTML_DOC_HTML401 3

extern void *entity_ms_table_html5;
extern void *entity_ms_table_html4;
extern void *stage3_table_be_noapos_00000;
extern void *stage3_table_be_apos_00000;