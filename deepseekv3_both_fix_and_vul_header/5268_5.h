#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char xmlChar;

typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;
struct _xmlNode {
    int type;
    const xmlChar *name;
    struct _xmlNode *children;
    struct _xmlNode *next;
    struct _xmlNs *ns;
};

typedef struct _xmlNs xmlNs;
struct _xmlNs {
    const xmlChar *prefix;
};

typedef struct _xmlDoc xmlDoc;
typedef xmlDoc *xmlDocPtr;
struct _xmlDoc {
    const xmlChar *version;
    const xmlChar *encoding;
    int charset;
    struct _xmlNode *children;
    void *dict;
    void *intSubset;
    int type;
};

typedef enum {
    XML_CHAR_ENCODING_UTF8 = 0,
    XML_CHAR_ENCODING_NONE = -1
} xmlCharEncoding;

typedef enum {
    XSLT_OUTPUT_XML,
    XSLT_OUTPUT_HTML,
    XSLT_OUTPUT_TEXT
} xsltOutputType;

typedef struct _xsltStylesheet xsltStylesheet;
typedef xsltStylesheet *xsltStylesheetPtr;
struct _xsltStylesheet {
    xmlChar *version;
    xmlChar *encoding;
    xmlChar *method;
    xmlChar *methodURI;
    xmlChar *doctypeSystem;
    xmlChar *doctypePublic;
    int standalone;
    int indent;
    int omitXmlDeclaration;
    void *stripSpaces;
    xsltStylesheetPtr parent;
    int errors;
    int warnings;
};

typedef struct _xsltTransformContext xsltTransformContext;
typedef xsltTransformContext *xsltTransformContextPtr;
struct _xsltTransformContext {
    const char *outputFile;
    xmlDocPtr output;
    xmlNodePtr insert;
    xsltOutputType type;
    void *sec;
    void *dict;
};

typedef struct _xsltElemPreComp xsltElemPreComp;
typedef xsltElemPreComp *xsltElemPreCompPtr;
struct _xsltElemPreComp {
    int type;
};

typedef struct _xsltStyleItemDocument xsltStyleItemDocument;
typedef xsltStyleItemDocument *xsltStyleItemDocumentPtr;
struct _xsltStyleItemDocument {
    xsltElemPreComp castedComp;
    xmlChar *filename;
};

typedef struct _xsltStylePreComp xsltStylePreComp;
typedef xsltStylePreComp *xsltStylePreCompPtr;
struct _xsltStylePreComp {
    xsltElemPreComp castedComp;
    xmlChar *filename;
};

typedef struct _xmlXPathCompExpr xmlXPathCompExpr;
typedef xmlXPathCompExpr *xmlXPathCompExprPtr;
struct _xmlXPathCompExpr {
    int dummy;
};

typedef enum {
    XML_ELEMENT_NODE = 1,
    XML_TEXT_NODE = 3,
    XML_HTML_DOCUMENT_NODE = 13
} xmlElementType;

#define XSLT_REFACTORED
#define WITH_XSLT_DEBUG
#define WITH_XSLT_DEBUG_EXTRA
#define WITH_XSLT_DEBUG_PARSING
#define XSLT_GENERATE_HTML_DOCTYPE

#define XSLT_SAXON_NAMESPACE ((const xmlChar *) "http://icl.com/saxon")
#define XSLT_XALAN_NAMESPACE ((const xmlChar *) "http://xml.apache.org/xalan")

#define IS_BLANK_CH(c) (((c) == 0x20) || ((c) == 0x9) || ((c) == 0xA) || ((c) == 0xD))

#define BAD_CAST (xmlChar *)

#define XSLT_GET_IMPORT_PTR(res, style, name) \
    if ((style)->name != NULL) (res) = (style)->name; \
    else if ((style)->parent != NULL) { \
        xsltStylesheetPtr cur = (style)->parent; \
        while (cur != NULL && (res) == NULL) { \
            if (cur->name != NULL) (res) = cur->name; \
            cur = cur->parent; \
        } \
    }

xmlChar *xmlStrdup(const xmlChar *str);
int xmlStrEqual(const xmlChar *str1, const xmlChar *str2);
int xmlStrcasecmp(const xmlChar *str1, const xmlChar *str2);
xmlChar *xmlStrndup(const xmlChar *str, int len);
int xmlIsBlankNode(xmlNodePtr node);
xmlChar *xsltEvalAttrValueTemplate(xsltTransformContextPtr ctxt, xmlNodePtr node, const xmlChar *name, const xmlChar *ns);
void xsltTransformError(xsltTransformContextPtr ctxt, xsltStylesheetPtr style, xmlNodePtr node, const char *msg, ...);
xmlChar *xmlBuildURI(const xmlChar *URI, const xmlChar *base);
xmlChar *xmlURIEscapeStr(const xmlChar *str, const xmlChar *list);
void xmlFree(void *ptr);
int xsltCheckWrite(void *sec, xsltTransformContextPtr ctxt, const xmlChar *URL);
xsltStylesheetPtr xsltNewStylesheet(void);
void xsltFreeStylesheet(xsltStylesheetPtr style);
xmlDocPtr htmlNewDoc(const xmlChar *URI, const xmlChar *ExternalID);
xmlDocPtr htmlNewDocNoDtD(const xmlChar *URI, const xmlChar *ExternalID);
xmlDocPtr xmlNewDoc(const xmlChar *version);
void xmlFreeDoc(xmlDocPtr cur);
xmlNodePtr xmlDocGetRootElement(const xmlDocPtr doc);
xmlXPathCompExprPtr xmlXPathCompile(const xmlChar *str);
xmlChar *xsltEvalXPathString(xsltTransformContextPtr ctxt, xmlXPathCompExprPtr comp);
void xmlXPathFreeCompExpr(xmlXPathCompExprPtr comp);
void xsltApplySequenceConstructor(xsltTransformContextPtr ctxt, xmlNodePtr node, xmlNodePtr inst, void *comp);
int xsltSaveResultToFile(FILE *file, xmlDocPtr doc, xsltStylesheetPtr style);
int xsltSaveResultToFilename(const char *filename, xmlDocPtr doc, xsltStylesheetPtr style, int compression);
void xsltGenericDebug(void *ctx, const char *msg, ...);
void *xsltGenericDebugContext;
const xmlChar *xsltGetQNameURI(xmlNodePtr node, const xmlChar **name);
void *xmlHashCreate(int size);
int xmlHashAddEntry2(void *table, const xmlChar *name, const xmlChar *name2, void *userdata);
void *xmlCreateIntSubset(xmlDocPtr doc, const xmlChar *name, const xmlChar *ExternalID, const xmlChar *SystemID);
void xsltGetHTMLIDs(const xmlChar *version, const xmlChar **publicId, const xmlChar **systemId);
const xmlChar *xmlDictQLookup(void *dict, const xmlChar *prefix, const xmlChar *name);
void xmlDictReference(void *dict);