#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

/* Basic XML types */
typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlDoc xmlDoc;
typedef xmlDoc *xmlDocPtr;
typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;
typedef struct _xmlDtd xmlDtd;
typedef xmlDtd *xmlDtdPtr;
typedef struct _xmlSAXHandler xmlSAXHandler;
typedef struct _xmlValidCtxt xmlValidCtxt;
typedef struct _xmlSchema xmlSchema;
typedef struct _xmlRelaxNG xmlRelaxNG;
typedef struct _xmlSchematron xmlSchematron;

/* Validation context structure */
struct _xmlValidCtxt {
    void (*error)(void *ctx, const char *msg, ...);
    void (*warning)(void *ctx, const char *msg, ...);
    /* Other members omitted for brevity */
};

/* Parser context structure */
struct _xmlParserCtxt {
    struct _xmlSAXHandler *sax;
    struct _xmlValidCtxt vctxt;
    /* Other members omitted for brevity */
};

/* SAX handler structure */
struct _xmlSAXHandler {
    void (*error)(void *ctx, const char *msg, ...);
    void (*warning)(void *ctx, const char *msg, ...);
    /* Other members omitted for brevity */
};

typedef unsigned char xmlChar;
#define BAD_CAST (xmlChar *)

/* IO callback types */
typedef int (*xmlInputReadCallback)(void *context, char *buffer, int len);
typedef int (*xmlInputCloseCallback)(void *context);

/* Error codes */
enum {
    XMLLINT_ERR_UNCLASS = 1,
    XMLLINT_ERR_RDFILE = 2,
    XMLLINT_ERR_OUT = 3,
    XMLLINT_ERR_DTD = 4,
    XMLLINT_ERR_VALID = 5
};

/* XML parser functions */
xmlDocPtr xmlReadFd(int fd, const char *URL, const char *encoding, int options);
xmlDocPtr xmlReadIO(xmlInputReadCallback ioread, xmlInputCloseCallback ioclose, 
                   void *ioctx, const char *URL, const char *encoding, int options);
xmlDocPtr xmlCtxtReadIO(xmlParserCtxtPtr ctxt, xmlInputReadCallback ioread, 
                       xmlInputCloseCallback ioclose, void *ioctx, 
                       const char *URL, const char *encoding, int options);
xmlParserCtxtPtr xmlNewParserCtxt(void);
void xmlFreeParserCtxt(xmlParserCtxtPtr ctxt);
xmlDocPtr xmlCtxtReadFile(xmlParserCtxtPtr ctxt, const char *filename, 
                         const char *encoding, int options);
xmlDocPtr xmlReadFile(const char *filename, const char *encoding, int options);
xmlDtdPtr xmlGetIntSubset(xmlDocPtr doc);
void xmlUnlinkNode(xmlNodePtr node);
void xmlFreeDtd(xmlDtdPtr dtd);
void xmlFreeDoc(xmlDocPtr doc);

/* Error handler functions */
typedef void (*xmlHTMLErrorFunc)(void *ctx, const char *msg, ...);
typedef void (*xmlHTMLWarningFunc)(void *ctx, const char *msg, ...);
typedef void (*xmlHTMLValidityErrorFunc)(void *ctx, const char *msg, ...);
typedef void (*xmlHTMLValidityWarningFunc)(void *ctx, const char *msg, ...);

/* Global variables */
extern int timing;
extern int repeat;
extern int generate;
extern int html;
extern int push;
extern int options;
extern int pushsize;
extern int memory;
extern int dropdtd;
extern int xinclude;
extern char *xpathquery;
extern int shell;
extern int copy;
extern int insert;
extern int walker;
extern int noout;
extern int xmlout;
extern int compress;
extern char *encoding;
extern int format;
extern int oldout;
extern int debug;
extern int quiet;
extern int postvalid;
extern char *dtdvalid;
extern char *dtdvalidfpi;
extern xmlRelaxNG *relaxngschemas;
extern xmlSchema *wxschemas;
extern xmlSchematron *wxschematron;
extern int recovery;
extern int testIO;
extern int htmlout;
extern int valid;
extern int sax1;
extern int canonical;
extern int canonical_11;
extern int exc_canonical;
extern int progresult;

/* Timer functions */
void startTimer(void);
void endTimer(const char *msg);

/* IO callback functions */
int myRead(void *context, char *buffer, int len);
int myClose(void *context);

/* Error handler functions */
extern xmlHTMLErrorFunc xmlHTMLError;
extern xmlHTMLWarningFunc xmlHTMLWarning;
extern xmlHTMLValidityErrorFunc xmlHTMLValidityError;
extern xmlHTMLValidityWarningFunc xmlHTMLValidityWarning;