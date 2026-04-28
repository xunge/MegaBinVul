#include <stdlib.h>

#define XML_MAXLEVEL 100

typedef void* XML_Parser;

typedef struct _xml_parser {
    XML_Parser parser;
    int level;
    char **ltags;
    void* startElementHandler;
    void* endElementHandler;
    void* characterDataHandler;
    void* processingInstructionHandler;
    void* defaultHandler;
    void* unparsedEntityDeclHandler;
    void* notationDeclHandler;
    void* externalEntityRefHandler;
    void* unknownEncodingHandler;
    void* startNamespaceDeclHandler;
    void* endNamespaceDeclHandler;
    char *baseURI;
    void* object;
} xml_parser;

typedef struct _zend_rsrc_list_entry {
    void *ptr;
} zend_rsrc_list_entry;

#define TSRMLS_DC

void XML_ParserFree(XML_Parser parser);
void efree(void *ptr);
void zval_ptr_dtor(void *zval_ptr);