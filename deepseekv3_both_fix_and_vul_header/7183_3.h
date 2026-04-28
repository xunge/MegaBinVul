#include <stdint.h>
#include <stddef.h>

#define PLIST_API extern
#define XML_PARSE_NONET (1<<11)

typedef void* plist_t;
typedef void* xmlDocPtr;
typedef void* xmlNodePtr;
typedef void* xmlParserCtxtPtr;
typedef void* xmlParserInputPtr;

extern void xml_to_node(xmlNodePtr node, plist_t * plist);
extern xmlParserInputPtr plist_xml_external_entity_loader(const char *URL, const char *ID, xmlParserCtxtPtr ctxt);
extern void xmlSetExternalEntityLoader(xmlParserInputPtr (*f)(const char *, const char *, xmlParserCtxtPtr));
extern xmlDocPtr xmlReadMemory(const char *buf, int size, const char *URL, const char *encoding, int options);
extern xmlNodePtr xmlDocGetRootElement(xmlDocPtr doc);
extern void xmlFreeDoc(xmlDocPtr doc);
extern xmlDocPtr xmlParseMemory(const char *buffer, int size);