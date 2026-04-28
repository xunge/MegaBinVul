#include <string.h>

#define COMMON_RECORDV0_DATA_SIZE 16
#define COMMON_RECORD_DATA_SIZE 24
#define CommonRecordType 1

typedef struct common_record_v0_t {
    unsigned int size;
    unsigned int flags;
    unsigned int exporter_sysid;
    void *data;
} common_record_v0_t;

typedef struct common_record_t {
    unsigned int type;
    unsigned int size;
    unsigned int flags;
    unsigned int exporter_sysid;
    unsigned int reserved;
    void *data;
} common_record_t;