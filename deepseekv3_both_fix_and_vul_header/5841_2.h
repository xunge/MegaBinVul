#include <string.h>
#include <stdlib.h>

#define XML_ATTR_ID "id"
#define XML_CIB_TAG_ACLS "acls"

typedef unsigned int xpf_flags;
#define xpf_created 0x01
#define xpf_acl_write 0x02

typedef struct xml_private_s {
    xpf_flags flags;
} xml_private_t;

typedef struct xmlAttr {
    const char *name;
    struct xmlAttr *next;
} xmlAttr;

typedef struct xmlDoc {
    struct xmlNode *children;
} xmlDoc;

typedef struct xmlNode {
    struct xmlNode *children;
    struct xmlNode *next;
    struct xmlNode *parent;
    struct xmlDoc *doc;
    xml_private_t *_private;
    const char *name;
} xmlNode;

#define is_set(flags, mask) ((flags & mask) == mask)
#define ID(xml) ""
#define crm_trace(...)