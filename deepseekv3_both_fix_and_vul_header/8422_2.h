#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct _zval {
    int type;
    union {
        long lval;
        double dval;
        char *strval;
        void *ptr;
    } value;
} zval;

typedef struct _st_entry {
    zval *data;
} st_entry;

typedef struct {
    int top;
    void **elements;
} wddx_stack;

typedef void* XML_Parser;

void wddx_stack_init(wddx_stack *stack);
void wddx_stack_destroy(wddx_stack *stack);
void wddx_stack_top(wddx_stack *stack, void **ent);
void php_wddx_push_element(void *user_data, const char *name, const char **atts);
void php_wddx_pop_element(void *user_data, const char *name);
void php_wddx_process_data(void *user_data, const char *data, int len);
void zval_copy_ctor(zval *zvalue);

XML_Parser XML_ParserCreate(const char *encoding);
void XML_SetUserData(XML_Parser parser, void *userData);
void XML_SetElementHandler(XML_Parser parser,
                          void (*start)(void *, const char *, const char **),
                          void (*end)(void *, const char *));
void XML_SetCharacterDataHandler(XML_Parser parser,
                               void (*handler)(void *, const char *, int));
int XML_Parse(XML_Parser parser, const char *s, int len, int isFinal);
void XML_ParserFree(XML_Parser parser);