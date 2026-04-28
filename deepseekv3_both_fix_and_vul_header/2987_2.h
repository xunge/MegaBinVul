#include <stdlib.h>

typedef struct xml_data {
    int dummy;  // 添加至少一个成员使结构体完整
} xml_data;

typedef struct modsec_rec {
    void *mp;
    xml_data *xml;
    struct {
        int xml_external_entity;
    } *txcfg;
} modsec_rec;

typedef void* (*xmlParserInputBufferCreateFilenameFunc)(const char *filename, int enc);
void* xmlParserInputBufferCreateFilenameDefault(void *func);
void* xml_unload_external_entity(const char *filename, int enc);
void* apr_pcalloc(void *mp, size_t size);