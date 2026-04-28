#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <wchar.h>

#define XML_Char wchar_t
#define XML_Bool int
#define XML_TRUE 1
#define XML_FALSE 0
#define XML_MAP_FILE 0x01
#define XML_EXTERNAL_ENTITIES 0x02
#define XMLWF_EXIT_SUCCESS 0
#define XMLWF_EXIT_USAGE_ERROR 1
#define XMLWF_EXIT_INTERNAL_ERROR 2
#define XMLWF_EXIT_OUTPUT_ERROR 3
#define XMLWF_EXIT_NOT_WELLFORMED 4

typedef struct XML_Encoding {
    int map[256];
    void *data;
    int (*convert)(void *data, const char *s);
    void (*release)(void *data);
} XML_Encoding;

enum XML_ParamEntityParsing {
    XML_PARAM_ENTITY_PARSING_NEVER,
    XML_PARAM_ENTITY_PARSING_ALWAYS
};

typedef struct {
    FILE *fp;
    void *buffer;
    size_t buffer_size;
} XmlwfUserData;

typedef void *XML_Parser;

#define T(x) L##x
#define tcscmp wcscmp
#define tcslen wcslen
#define tcsrchr wcsrchr
#define tcscpy wcscpy
#define tcscat wcscat
#define tfopen _wfopen
#define puttc fputwc
#define tremove _wremove
#define tperror _wperror
#define ftprintf fwprintf
#define tcstoull wcstoull
#define tcstof wcstof

#define NSSEP L'\0'
#define XMLWF_SHIFT_ARG_INTO(var, argc, argv, i, j) \
    do { \
        if (argv[i][j+1] == T('\0')) { \
            if (i+1 >= argc) { \
                usage(argv[0], XMLWF_EXIT_USAGE_ERROR); \
            } \
            var = argv[++i]; \
            j = 0; \
        } else { \
            var = argv[i] + j + 1; \
            j = 0; \
        } \
    } while (0)

extern int g_read_size_bytes;
extern void usage(const XML_Char *prog, int exitCode);
extern void showVersion(const XML_Char *prog);
extern int XML_ProcessFile(XML_Parser parser, const XML_Char *filename, unsigned flags);
extern XML_Parser XML_ParserCreate(const XML_Char *encoding);
extern XML_Parser XML_ParserCreateNS(const XML_Char *encoding, XML_Char nssep);
extern void XML_ParserFree(XML_Parser parser);
extern void XML_SetUserData(XML_Parser parser, void *userData);
extern void XML_UseParserAsHandlerArg(XML_Parser parser);
extern void XML_SetElementHandler(XML_Parser parser, void *start, void *end);
extern void XML_SetCharacterDataHandler(XML_Parser parser, void *handler);
extern void XML_SetProcessingInstructionHandler(XML_Parser parser, void *handler);
extern void XML_SetCommentHandler(XML_Parser parser, void *handler);
extern void XML_SetCdataSectionHandler(XML_Parser parser, void *start, void *end);
extern void XML_SetDoctypeDeclHandler(XML_Parser parser, void *start, void *end);
extern void XML_SetEntityDeclHandler(XML_Parser parser, void *handler);
extern void XML_SetNotationDeclHandler(XML_Parser parser, void *handler);
extern void XML_SetNamespaceDeclHandler(XML_Parser parser, void *start, void *end);
extern void XML_SetDefaultHandler(XML_Parser parser, void *handler);
extern void XML_SetUnknownEncodingHandler(XML_Parser parser, int (*handler)(void *encodingHandlerData, const XML_Char *name, XML_Encoding *info), void *data);
extern void XML_SetParamEntityParsing(XML_Parser parser, enum XML_ParamEntityParsing parsing);
extern void XML_SetNotStandaloneHandler(XML_Parser parser, int (*handler)(void *userData));
extern void XML_SetBillionLaughsAttackProtectionMaximumAmplification(XML_Parser parser, float max_amplification);
extern void XML_SetBillionLaughsAttackProtectionActivationThreshold(XML_Parser parser, unsigned long long threshold);

extern int notStandalone(void *userData);
extern void nopStartElement(void *userData, const XML_Char *name, const XML_Char **atts);
extern void nopEndElement(void *userData, const XML_Char *name);
extern void nopCharacterData(void *userData, const XML_Char *s, int len);
extern void nopProcessingInstruction(void *userData, const XML_Char *target, const XML_Char *data);
extern void metaStartElement(void *userData, const XML_Char *name, const XML_Char **atts);
extern void metaEndElement(void *userData, const XML_Char *name);
extern void metaCharacterData(void *userData, const XML_Char *s, int len);
extern void metaProcessingInstruction(void *userData, const XML_Char *target, const XML_Char *data);
extern void metaComment(void *userData, const XML_Char *data);
extern void metaStartCdataSection(void *userData);
extern void metaEndCdataSection(void *userData);
extern void metaStartDoctypeDecl(void *userData, const XML_Char *doctypeName, const XML_Char *sysid, const XML_Char *pubid, int has_internal_subset);
extern void metaEndDoctypeDecl(void *userData);
extern void metaEntityDecl(void *userData, const XML_Char *entityName, int is_parameter_entity, const XML_Char *value, int value_length, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId, const XML_Char *notationName);
extern void metaNotationDecl(void *userData, const XML_Char *notationName, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId);
extern void metaStartNamespaceDecl(void *userData, const XML_Char *prefix, const XML_Char *uri);
extern void metaEndNamespaceDecl(void *userData, const XML_Char *prefix);
extern void metaStartDocument(void *userData);
extern void metaEndDocument(void *userData);
extern void markup(void *userData, const XML_Char *s, int len);
extern void defaultStartElement(void *userData, const XML_Char *name, const XML_Char **atts);
extern void defaultEndElement(void *userData, const XML_Char *name);
extern void defaultCharacterData(void *userData, const XML_Char *s, int len);
extern void defaultProcessingInstruction(void *userData, const XML_Char *target, const XML_Char *data);
extern void startElementNS(void *userData, const XML_Char *name, const XML_Char **atts);
extern void endElementNS(void *userData, const XML_Char *name);
extern void startElement(void *userData, const XML_Char *name, const XML_Char **atts);
extern void endElement(void *userData, const XML_Char *name);
extern void characterData(void *userData, const XML_Char *s, int len);
extern void processingInstruction(void *userData, const XML_Char *target, const XML_Char *data);
extern void startDoctypeDecl(void *userData, const XML_Char *doctypeName, const XML_Char *sysid, const XML_Char *pubid, int has_internal_subset);
extern void endDoctypeDecl(void *userData);
extern void notationDecl(void *userData, const XML_Char *notationName, const XML_Char *base, const XML_Char *systemId, const XML_Char *publicId);
extern int unknownEncoding(void *encodingHandlerData, const XML_Char *name, XML_Encoding *info);
extern void cleanupUserData(XmlwfUserData *userData);