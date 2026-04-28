#include <stdint.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

typedef struct {
    struct {
        uint32_t id;
    } info;
} exporter_ipfix_domain_t;

typedef struct FlowSource_t FlowSource_t;
typedef struct ipfix_template_record_t {
    uint16_t TemplateID;
    uint16_t FieldCount;
} ipfix_template_record_t;

#define IPFIX_TEMPLATE_FLOWSET_ID 2

extern void LogError(const char *format, ...);
extern void dbg_printf(const char *format, ...);
extern void remove_all_translation_tables(exporter_ipfix_domain_t *exporter);
extern void ReInitExtensionMapList(FlowSource_t *fs);
extern void remove_translation_table(FlowSource_t *fs, exporter_ipfix_domain_t *exporter, uint32_t id);