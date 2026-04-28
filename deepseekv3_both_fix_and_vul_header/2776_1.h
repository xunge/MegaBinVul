#include <stddef.h>

typedef enum {
    XML_CHAR_ENCODING_NONE = 0
} xmlCharEncoding;

typedef struct _xmlParserInputBuffer {
    void *context;
    int (*readcallback)(void *context, char *buffer, int len);
    int (*closecallback)(void *context);
} xmlParserInputBuffer;
typedef xmlParserInputBuffer *xmlParserInputBufferPtr;

#define TSRMLS_FETCH()
#define LIBXML(x) (0)

extern void *php_libxml_streams_IO_open_read_wrapper(const char *URI);
extern int php_libxml_streams_IO_read(void *context, char *buffer, int len);
extern int php_libxml_streams_IO_close(void *context);
extern xmlParserInputBufferPtr xmlAllocParserInputBuffer(xmlCharEncoding enc);