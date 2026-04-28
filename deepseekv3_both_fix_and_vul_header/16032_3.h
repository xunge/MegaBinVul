#include <stddef.h>

typedef void* VALUE;
typedef unsigned char xmlChar;

struct _xmlNode {
    struct _xmlAttr* properties;
};

struct _xmlAttr {
    const xmlChar* name;
    struct _xmlAttr* next;
};

typedef struct xmlTextReader xmlTextReader;
typedef xmlTextReader* xmlTextReaderPtr;
typedef struct _xmlNode xmlNode;
typedef xmlNode* xmlNodePtr;
typedef struct _xmlAttr xmlAttr;
typedef xmlAttr* xmlAttrPtr;

#define Qnil ((VALUE)0)
#define NOKOGIRI_STR_NEW2(str) (str ? (VALUE)str : Qnil)
#define Data_Get_Struct(obj, type, sval) ((sval) = (type*)(obj))
#define rb_hash_new() ((VALUE)0)
#define rb_hash_aset(hash, key, val) (void)0

static int has_attributes(xmlTextReaderPtr reader) { return 0; }
static xmlNodePtr xmlTextReaderExpand(xmlTextReaderPtr reader) { return 0; }
static xmlChar* xmlNodeGetContent(xmlNode* node) { return 0; }
static void xmlFree(void* ptr) {}