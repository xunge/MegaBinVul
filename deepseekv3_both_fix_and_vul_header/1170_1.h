#include <stdlib.h>

typedef struct XML_ParserStruct *XML_Parser;
typedef unsigned char XML_Bool;
typedef unsigned short XML_Char;

struct XML_Encoding {
    int map[256];
    void *data;
    int (*convert)(void *data, const char *s);
    void (*release)(void *data);
};

struct XML_Content {
    int type;
    const XML_Char *name;
    struct XML_Content *firstchild;
    struct XML_Content *lastchild;
    struct XML_Content *next;
    int ocurrence;
    const XML_Char *quant;
};

typedef void (*XML_StartElementHandler)(void *userData, const XML_Char *name, const XML_Char **atts);
typedef void (*XML_EndElementHandler)(void *userData, const XML_Char *name);
typedef void (*XML_CharacterDataHandler)(void *userData, const XML_Char *s, int len);
typedef void (*XML_ProcessingInstructionHandler)(void *userData, const XML_Char *target, const XML_Char *data);
typedef void (*XML_CommentHandler)(void *userData, const XML_Char *data);
typedef void (*XML_StartCdataSectionHandler)(void *userData);
typedef void (*XML_EndCdataSectionHandler)(void *userData);
typedef void (*XML_DefaultHandler)(void *userData, const XML_Char *s, int len);
typedef void (*XML_UnparsedEntityDeclHandler)(void *userData, const XML_Char *entityName, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId, const XML_Char *notationName);
typedef void (*XML_NotationDeclHandler)(void *userData, const XML_Char *notationName, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId);
typedef void (*XML_StartNamespaceDeclHandler)(void *userData, const XML_Char *prefix, const XML_Char *uri);
typedef void (*XML_EndNamespaceDeclHandler)(void *userData, const XML_Char *prefix);
typedef int (*XML_NotStandaloneHandler)(void *userData);
typedef int (*XML_ExternalEntityRefHandler)(XML_Parser parser, const XML_Char *context, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId);
typedef void (*XML_SkippedEntityHandler)(void *userData, const XML_Char *entityName, int is_parameter_entity);
typedef int (*XML_UnknownEncodingHandler)(void *encodingHandlerData, const XML_Char *name, struct XML_Encoding *info);
typedef void (*XML_ElementDeclHandler)(void *userData, const XML_Char *name, struct XML_Content *model);
typedef void (*XML_AttlistDeclHandler)(void *userData, const XML_Char *elname, const XML_Char *attname, const XML_Char *att_type, const XML_Char *dflt, int isrequired);
typedef void (*XML_EntityDeclHandler)(void *userData, const XML_Char *entityName, int is_parameter_entity, const XML_Char *value, int value_length, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId, const XML_Char *notationName);
typedef void (*XML_XmlDeclHandler)(void *userData, const XML_Char *version, const XML_Char *encoding, int standalone);

typedef struct DTD DTD;
typedef struct ELEMENT_TYPE ELEMENT_TYPE;

struct XML_ParserStruct {
    DTD *m_dtd;
    XML_StartElementHandler m_startElementHandler;
    XML_EndElementHandler m_endElementHandler;
    XML_CharacterDataHandler m_characterDataHandler;
    XML_ProcessingInstructionHandler m_processingInstructionHandler;
    XML_CommentHandler m_commentHandler;
    XML_StartCdataSectionHandler m_startCdataSectionHandler;
    XML_EndCdataSectionHandler m_endCdataSectionHandler;
    XML_DefaultHandler m_defaultHandler;
    XML_UnparsedEntityDeclHandler m_unparsedEntityDeclHandler;
    XML_NotationDeclHandler m_notationDeclHandler;
    XML_StartNamespaceDeclHandler m_startNamespaceDeclHandler;
    XML_EndNamespaceDeclHandler m_endNamespaceDeclHandler;
    XML_NotStandaloneHandler m_notStandaloneHandler;
    XML_ExternalEntityRefHandler m_externalEntityRefHandler;
    XML_SkippedEntityHandler m_skippedEntityHandler;
    XML_UnknownEncodingHandler m_unknownEncodingHandler;
    XML_ElementDeclHandler m_elementDeclHandler;
    XML_AttlistDeclHandler m_attlistDeclHandler;
    XML_EntityDeclHandler m_entityDeclHandler;
    XML_XmlDeclHandler m_xmlDeclHandler;
    ELEMENT_TYPE *m_declElementType;
    void *m_userData;
    void *m_handlerArg;
    XML_Bool m_defaultExpandInternalEntities;
    XML_Parser m_externalEntityRefHandlerArg;
    XML_Bool m_ns_triplets;
    unsigned long m_hash_secret_salt;
    XML_Parser m_parentParser;
    XML_Bool m_ns;
    XML_Char m_namespaceSeparator;
    void *m_mem;
    void *m_processor;
    XML_Bool m_isParamEntity;
    struct {
        int inEntityValue;
    } m_prologState;
#ifdef XML_DTD
    enum XML_ParamEntityParsing m_paramEntityParsing;
#endif
};

#define XMLCALL
#define XML_TRUE 1
#define XML_FALSE 0

extern XML_Parser parserCreate(const XML_Char *encodingName, void *mem, const XML_Char *namespaceSeparator, DTD *dtd);
extern int dtdCopy(XML_Parser oldParser, DTD *newDtd, DTD *oldDtd, void *mem);
extern int setContext(XML_Parser parser, const XML_Char *context);
extern void XML_ParserFree(XML_Parser parser);
extern void XmlPrologStateInitExternalEntity(void *prologState);
extern void *externalEntityInitProcessor;
extern void *externalParEntInitProcessor;