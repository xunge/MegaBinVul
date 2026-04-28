#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define MAXPATHLEN PATH_MAX
#define DEFAULT_SLASH '/'
#define DOM_LOAD_FILE 1
#define XML_PARSE_DTDVALID 1
#define XML_PARSE_DTDATTR 2
#define XML_PARSE_NOENT 4
#define XML_PARSE_NOBLANKS 8
#define E_WARNING 2

typedef unsigned char xmlChar;

typedef struct _xmlParserInput {
    char *filename;
    char *directory;
} xmlParserInput;

typedef struct _xmlSAXHandler {
    void (*error)(void *ctx, const char *msg, ...);
    void (*warning)(void *ctx, const char *msg, ...);
} xmlSAXHandler;

typedef struct _xmlDoc {
    char *URL;
    // 其他必要字段...
} xmlDoc;
typedef xmlDoc *xmlDocPtr;

typedef struct _xmlParserCtxt {
    xmlParserInput *directory;
    xmlDocPtr myDoc;
    int wellFormed;
    int recovery;
    xmlSAXHandler *sax;
    struct {
        void (*error)(void *ctx, const char *msg, ...);
        void (*warning)(void *ctx, const char *msg, ...);
    } vctxt;
} xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;

typedef struct _dom_doc_props {
    int validateonparse;
    int resolveexternals;
    int preservewhitespace;
    int substituteentities;
    int recover;
} dom_doc_props;
typedef dom_doc_props *dom_doc_propsptr;

typedef struct _dom_object {
    struct _php_libxml_ref_obj *document;
} dom_object;

typedef struct _php_libxml_ref_obj {
    // 必要字段...
} php_libxml_ref_obj;

typedef struct _zval {
    // 必要字段...
} zval;

typedef struct _zend_executor_globals {
    int error_reporting;
} zend_executor_globals;

extern zend_executor_globals executor_globals;

#define TSRMLS_DC
#define TSRMLS_CC
#define EG(e) executor_globals.e

void php_libxml_ctx_error(void *ctx, const char *msg, ...);
void php_libxml_ctx_warning(void *ctx, const char *msg, ...);

void xmlInitParser(void);
void xmlFree(char *mem);
char *xmlCanonicPath(const xmlChar *path);
void xmlCtxtUseOptions(xmlParserCtxtPtr ctxt, int options);
void xmlParseDocument(xmlParserCtxtPtr ctxt);
char *xmlStrdup(const char *cur);
void xmlFreeDoc(xmlDocPtr cur);
void xmlFreeParserCtxt(xmlParserCtxtPtr ctxt);
xmlParserCtxtPtr xmlCreateFileParserCtxt(const char *filename);
xmlParserCtxtPtr xmlCreateMemoryParserCtxt(const char *buffer, int size);

void *zend_object_store_get_object(void *id);
dom_doc_propsptr dom_get_doc_props(php_libxml_ref_obj *document);
char *_dom_get_valid_file_path(char *source, char *resolved_path, int maxlen);
void efree(void *ptr);