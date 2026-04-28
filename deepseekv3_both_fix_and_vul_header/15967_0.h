#include <stdlib.h>

typedef struct _xmlDict xmlDict;
typedef xmlDict *xmlDictPtr;
typedef struct _xmlDoc xmlDoc;
typedef struct _xmlNode xmlNode;
typedef struct _xmlNode *xmlNodePtr;
typedef struct _xmlEntity xmlEntity;
typedef xmlEntity *xmlEntityPtr;

struct _xmlDoc {
    xmlDictPtr dict;
};

struct _xmlNode {
    xmlNodePtr parent;
};

struct _xmlEntity {
    xmlDoc *doc;
    char *name;
    char *ExternalID;
    char *SystemID;
    char *URI;
    char *content;
    char *orig;
    xmlNodePtr children;
    int owner;
};

void xmlFree(void *ptr);
void xmlFreeNodeList(xmlNodePtr node);
int xmlDictOwns(xmlDictPtr dict, const char *str);