#include <stdlib.h>

typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlCharEncodingHandler xmlCharEncodingHandler;
typedef xmlCharEncodingHandler *xmlCharEncodingHandlerPtr;
typedef unsigned char xmlChar;
typedef enum {
    XML_CHAR_ENCODING_ERROR,
    XML_CHAR_ENCODING_NONE,
    XML_CHAR_ENCODING_UTF8,
    XML_CHAR_ENCODING_UTF16LE,
    XML_CHAR_ENCODING_UTF16BE,
    XML_CHAR_ENCODING_UCS4LE,
    XML_CHAR_ENCODING_UCS4BE,
    XML_CHAR_ENCODING_UCS4_2143,
    XML_CHAR_ENCODING_UCS4_3412,
    XML_CHAR_ENCODING_EBCDIC,
    XML_CHAR_ENCODING_UCS2,
    XML_CHAR_ENCODING_8859_1,
    XML_CHAR_ENCODING_8859_2,
    XML_CHAR_ENCODING_8859_3,
    XML_CHAR_ENCODING_8859_4,
    XML_CHAR_ENCODING_8859_5,
    XML_CHAR_ENCODING_8859_6,
    XML_CHAR_ENCODING_8859_7,
    XML_CHAR_ENCODING_8859_8,
    XML_CHAR_ENCODING_8859_9,
    XML_CHAR_ENCODING_2022_JP,
    XML_CHAR_ENCODING_SHIFT_JIS,
    XML_CHAR_ENCODING_EUC_JP,
    XML_CHAR_ENCODING_ASCII
} xmlCharEncoding;

#define BAD_CAST (xmlChar *)

struct _xmlParserInput {
    xmlChar *cur;
    xmlChar *encoding;
};

struct _xmlParserCtxt {
    xmlCharEncoding charset;
    struct _xmlParserInput *input;
    xmlChar *encoding;
    int inputNr;
    int errNo;
};

void __xmlErrEncoding(xmlParserCtxtPtr ctxt, int error, const char *msg, const char *str1, const char *str2);
xmlCharEncodingHandlerPtr xmlGetCharEncodingHandler(xmlCharEncoding enc);
int xmlSwitchToEncodingInt(xmlParserCtxtPtr ctxt, xmlCharEncodingHandlerPtr handler, int len);
void xmlStopParser(xmlParserCtxtPtr ctxt);
xmlChar *xmlStrdup(const xmlChar *cur);

#define XML_ERR_UNKNOWN_ENCODING 1000
#define XML_ERR_UNSUPPORTED_ENCODING 1001
#define XML_I18N_CONV_FAILED 2000