#include <stdlib.h>
#include <string.h>
#include <syslog.h>

#define DLT_CONFIG_FILE_SECTIONS_MAX 100
#define DLT_CONFIG_FILE_ENTRY_MAX_LEN 256
#define DLT_CONFIG_FILE_KEYS_MAX 100

typedef struct {
    char *name;
    char *keys;
} DltConfigFileSection;

typedef struct {
    DltConfigFileSection sections[DLT_CONFIG_FILE_SECTIONS_MAX];
    int num_sections;
} DltConfigFile;

int dlt_config_file_is_section_name(DltConfigFile *file, char *name);
void dlt_log(int level, const char *format, ...);