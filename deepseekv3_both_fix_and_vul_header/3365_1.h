#include <stdbool.h>

typedef struct {
    bool m_entity_loader_disabled;
} libxml_errors_t;

typedef void* (*xmlParserInputBufferCreateFilenameFunc)(const char*);
extern xmlParserInputBufferCreateFilenameFunc (*xmlParserInputBufferCreateFilenameDefault)(xmlParserInputBufferCreateFilenameFunc);

extern libxml_errors_t* s_libxml_errors;
extern xmlParserInputBufferCreateFilenameFunc hphp_libxml_input_buffer_noload;