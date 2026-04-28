#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <time.h>

#define MAX_EXTENSION_MAPS 64
#define IDENTLEN 128
#define COMPAT15
#define INIT_ID 0
#define EX_IO_SNMP_2 0
#define EX_AS_2 0
#define CommonRecordV0Type 0
#define CommonRecordType 1
#define ExtensionMapType 2
#define ExporterRecordType 3
#define SamplerRecordype 4
#define ExporterInfoRecordType 5
#define ExporterStatRecordType 6
#define SamplerInfoRecordype 7
#define DATA_BLOCK_TYPE_1 1
#define DATA_BLOCK_TYPE_2 2
#define Large_BLOCK_Type 3
#define NF_CORRUPT -1
#define NF_ERROR -2
#define NF_EOF -3
#define IP_ANONYMIZED(x) 0
#define LogError(...)
#define dbg_printf(...)
#define DEVEL

typedef struct stat_record_s {
    int first_seen;
    int last_seen;
    int msec_first;
    uint64_t numflows;
} stat_record_t;

typedef struct common_record_s {
    uint32_t ext_map;
    uint32_t exporter_sysid;
    uint32_t size;
    uint32_t type;
} common_record_t;

typedef struct common_record_v1_s {
    uint32_t ext_map;
    uint32_t exporter_sysid;
    uint32_t size;
    uint32_t type;
} common_record_v1_t;

typedef struct master_record_s {
    time_t first;
    time_t last;
    char *label;
} master_record_t;

typedef struct nffile_s {
    struct {
        uint32_t id;
        uint32_t NumRecords;
    } *block_header;
    void *buff_ptr;
    stat_record_t *stat_record;
    struct {
        char ident[IDENTLEN];
    } *file_header;
} nffile_t;

typedef void (*printer_t)();

typedef struct extension_map_s {
    int type;
    int size;
    uint32_t map_id;
    uint16_t ex_id[3];
    int extension_size;
    master_record_t master_record;
    int ref_count;
    struct extension_map_s *slot[MAX_EXTENSION_MAPS];
} extension_map_t;

typedef struct generic_exporter_s {
    void *info;
} generic_exporter_t;

typedef struct exporter_info_record_s {
    // dummy structure
} exporter_info_record_t;

typedef struct exporter_stats_record_s {
    // dummy structure
} exporter_stats_record_t;

typedef struct sampler_info_record_s {
    // dummy structure
} sampler_info_record_t;

typedef uintptr_t pointer_addr_t;

extern int is_anonymized;
extern char Ident[IDENTLEN];
extern time_t t_first_flow, t_last_flow;
extern uint64_t total_bytes, total_flows, skipped_blocks;
extern nffile_t *EMPTY_LIST;
extern extension_map_t *extension_map_list;
extern generic_exporter_t **exporter_list;
extern struct {
    uint64_t *nfrecord;
    char *label;
    int (*FilterEngine)(void *);
} *Engine;

extern struct extension_descriptor_s {
    int size;
} extension_descriptor[];

nffile_t *GetNextFile(nffile_t *file, time_t start, time_t end);
nffile_t *OpenNewFile(char *filename, void *unused, int compress, int anonymized, void *unused2);
void CloseFile(nffile_t *file);
nffile_t *DisposeFile(nffile_t *file);
int ReadBlock(nffile_t *file);
char *GetCurrentFilename();
int Insert_Extension_Map(extension_map_t *list, extension_map_t *map);
void Convert_v1_to_v2(void *record);
int ConvertCommonV0(void *src, common_record_t *dst);
void ExpandRecord_v2(common_record_t *flow_record, extension_map_t *map, void *info, master_record_t *master_record);
void UpdateStat(stat_record_t *stat, master_record_t *record);
void AddFlow(common_record_t *flow_record, master_record_t *master_record, extension_map_t *map);
void AddStat(common_record_t *flow_record, master_record_t *master_record);
void InsertFlow(common_record_t *flow_record, master_record_t *master_record, extension_map_t *map);
int AppendToBuffer(nffile_t *file, void *data, int size);
int AddExporterInfo(exporter_info_record_t *record);
int AddExporterStat(exporter_stats_record_t *record);
int AddSamplerInfo(sampler_info_record_t *record);
int WriteBlock(nffile_t *file);
void CloseUpdateFile(nffile_t *file, char *ident);
void PackExtensionMapList(extension_map_t *list);