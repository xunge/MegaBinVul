#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define Max_num_extensions 100
#define EX_ROUTER_IP_v4 1
#define EX_ROUTER_ID 2
#define EX_RECEIVED 3
#define IPFIX_ReverseInformationElement 0xFFFFFFFF
#define PF_INET6 10

typedef struct exporter_ipfix_domain_t {
    struct {
        unsigned int id;
    } info;
} exporter_ipfix_domain_t;

typedef struct FlowSource_t {
    int sa_family;
} FlowSource_t;

typedef struct input_translation_t {
    int extension_map_changed;
    struct {
        struct {
            int map_id;
        } *map;
    } extension_info;
} input_translation_t;

typedef struct ipfix_template_record_t {
    uint16_t TemplateID;
    uint16_t FieldCount;
    uint8_t elements[];
} ipfix_template_record_t;

typedef struct ipfix_template_elements_std_t {
    uint16_t Type;
    uint16_t Length;
} ipfix_template_elements_std_t;

typedef struct ipfix_template_elements_e_t {
    uint16_t Type;
    uint16_t Length;
    uint32_t EnterpriseNumber;
} ipfix_template_elements_e_t;

typedef struct {
    uint32_t id;
} ipfix_element_map_t;

typedef struct element_param_s {
    int index;
} element_param_s;

typedef struct order_s {
    // placeholder structure
} order_s;

typedef struct {
    uint32_t common_extensions[Max_num_extensions+1];
    struct element_param_s lookup_info[65536];
    struct order_s *input_order;
    int input_count;
} cache_t;

typedef struct {
    int enabled;
    int id;
} extension_descriptor_t;

extern cache_t cache;
extern ipfix_element_map_t ipfix_element_map[];
extern extension_descriptor_t extension_descriptor[];

static uint32_t MapElement(uint16_t Type, uint16_t Length, int i);
static int compact_input_order(void);
static input_translation_t *setup_translation_table(exporter_ipfix_domain_t *exporter, uint32_t table_id);
static void AddExtensionMap(FlowSource_t *fs, void *map);
static int reorder_sequencer(input_translation_t *translation_table);
static void remove_translation_table(FlowSource_t *fs, exporter_ipfix_domain_t *exporter, uint32_t table_id);
static void LogError(const char *format, ...);
static void dbg_printf(const char *format, ...);