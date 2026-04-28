#include <string.h>

typedef unsigned char XML_Bool;
#define XML_FALSE 0
#define XML_TRUE 1

typedef enum {
    XML_ERROR_NONE,
    XML_ERROR_NO_MEMORY
} XML_Error;

typedef enum {
    XML_INITIALIZED,
    XML_PARSING,
    XML_FINISHED
} ParsingStatus;

typedef struct {
    XML_Bool parsing;
} ParsingStatusStruct;

typedef struct {
    int debugLevel;
    unsigned maximumAmplificationFactor;
    unsigned activationThresholdBytes;
} ACCOUNTING;

typedef struct {
    int debugLevel;
} ENTITY_STATS;

typedef struct {
    int dummy;
} POSITION;

typedef struct {
    int dummy;
} XmlEncoding;

typedef struct {
    int dummy;
} XmlPrologState;

typedef struct {
    int dummy;
} MEM;

typedef char XML_Char;

struct XML_ParserStruct {
    void (*m_processor)(void);
    XmlPrologState m_prologState;
    XML_Char *m_protocolEncodingName;
    MEM m_mem;
    void *m_curBase;
    XmlEncoding m_initEncoding;
    XmlEncoding m_encoding;
    void *m_userData;
    void *m_handlerArg;
    void *m_startElementHandler;
    void *m_endElementHandler;
    void *m_characterDataHandler;
    void *m_processingInstructionHandler;
    void *m_commentHandler;
    void *m_startCdataSectionHandler;
    void *m_endCdataSectionHandler;
    void *m_defaultHandler;
    void *m_startDoctypeDeclHandler;
    void *m_endDoctypeDeclHandler;
    void *m_unparsedEntityDeclHandler;
    void *m_notationDeclHandler;
    void *m_startNamespaceDeclHandler;
    void *m_endNamespaceDeclHandler;
    void *m_notStandaloneHandler;
    void *m_externalEntityRefHandler;
    void *m_externalEntityRefHandlerArg;
    void *m_skippedEntityHandler;
    void *m_elementDeclHandler;
    void *m_attlistDeclHandler;
    void *m_entityDeclHandler;
    void *m_xmlDeclHandler;
    char *m_bufferPtr;
    char *m_bufferEnd;
    char m_buffer[1];
    unsigned long m_parseEndByteIndex;
    char *m_parseEndPtr;
    void *m_declElementType;
    void *m_declAttributeId;
    void *m_declEntity;
    XML_Char *m_doctypeName;
    XML_Char *m_doctypeSysid;
    XML_Char *m_doctypePubid;
    void *m_declAttributeType;
    XML_Char *m_declNotationName;
    XML_Char *m_declNotationPublicId;
    XML_Bool m_declAttributeIsCdata;
    XML_Bool m_declAttributeIsId;
    POSITION m_position;
    XML_Error m_errorCode;
    char *m_eventPtr;
    char *m_eventEndPtr;
    char *m_positionPtr;
    void *m_openInternalEntities;
    XML_Bool m_defaultExpandInternalEntities;
    int m_tagLevel;
    void *m_tagStack;
    void *m_inheritedBindings;
    int m_nSpecifiedAtts;
    void *m_unknownEncodingMem;
    void (*m_unknownEncodingRelease)(void *);
    void *m_unknownEncodingData;
    struct XML_ParserStruct *m_parentParser;
    ParsingStatusStruct m_parsingStatus;
    XML_Bool m_isParamEntity;
    XML_Bool m_useForeignDTD;
    int m_paramEntityParsing;
    unsigned m_hash_secret_salt;
    ACCOUNTING m_accounting;
    ENTITY_STATS m_entity_stats;
};

typedef struct XML_ParserStruct *XML_Parser;

static void prologInitProcessor(void) {}
static void XmlPrologStateInit(XmlPrologState *state) {}
static XML_Char *copyString(const XML_Char *str, MEM *mem) { return NULL; }
static void XmlInitEncoding(XmlEncoding *initEnc, XmlEncoding *enc, int flag) {}
static unsigned getDebugLevel(const char *name, unsigned defaultLevel) { return 0; }

#define EXPAT_BILLION_LAUGHS_ATTACK_PROTECTION_MAXIMUM_AMPLIFICATION_DEFAULT 100
#define EXPAT_BILLION_LAUGHS_ATTACK_PROTECTION_ACTIVATION_THRESHOLD_DEFAULT 1000000