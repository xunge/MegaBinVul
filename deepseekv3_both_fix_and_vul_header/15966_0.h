#include <stdlib.h>
#include <string.h>

typedef struct _xmlDict xmlDict;
typedef xmlDict *xmlDictPtr;
typedef unsigned char xmlChar;
typedef struct _xmlEntity xmlEntity;
typedef xmlEntity *xmlEntityPtr;

typedef enum {
    XML_ENTITY_DECL
} xmlElementType;

typedef enum {
    XML_INTERNAL_GENERAL_ENTITY,
    XML_EXTERNAL_GENERAL_PARSED_ENTITY,
    XML_EXTERNAL_GENERAL_UNPARSED_ENTITY,
    XML_INTERNAL_PARAMETER_ENTITY,
    XML_EXTERNAL_PARAMETER_ENTITY,
    XML_INTERNAL_PREDEFINED_ENTITY
} xmlEntityType;

struct _xmlEntity {
    void           *_private;
    xmlElementType  type;
    const xmlChar  *name;
    struct _xmlNode *children;
    struct _xmlNode *last;
    struct _xmlDtd  *parent;
    struct _xmlNode *next;
    struct _xmlNode *prev;
    struct _xmlDoc  *doc;
    xmlChar        *orig;
    xmlChar        *content;
    int             length;
    xmlEntityType   etype;
    const xmlChar  *ExternalID;
    const xmlChar  *SystemID;
    struct _xmlEntity *nexte;
    const xmlChar  *URI;
    int             owner;
    int             checked;
};

extern void *xmlMalloc(size_t size);
extern void xmlEntitiesErrMemory(const char *extra);
extern xmlChar *xmlStrdup(const xmlChar *cur);
extern xmlChar *xmlStrndup(const xmlChar *cur, int len);
extern int xmlStrlen(const xmlChar *str);
extern const xmlChar *xmlDictLookup(xmlDictPtr dict, const xmlChar *name, int len);