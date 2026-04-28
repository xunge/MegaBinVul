#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define NAMEDATALEN 64
#define SPI_OK_CONNECT 1
#define SPI_OK_FINISH 2
#define ERRCODE_INTERNAL_ERROR 0
#define ERROR 1

typedef int32_t int32;

typedef struct SchemaAndName
{
    const char *schema;
    const char *name;
} SchemaAndName;

typedef struct InternalTimeRange
{
    int64_t start;
    int64_t end;
} InternalTimeRange;

typedef struct NameData
{
    char data[NAMEDATALEN];
} NameData;

int SPI_connect(void);
int SPI_exec(const char *src, int cnt);
int SPI_finish(void);
const char *SPI_result_code_string(int code);
void elog(int level, const char *fmt, ...);
void ereport(int level, const char *msg);
void Assert(bool condition);
int64_t range_length(InternalTimeRange range);
bool ranges_overlap(InternalTimeRange range1, InternalTimeRange range2);
int64_t int64_min(int64_t a, int64_t b);
void spi_update_materializations(SchemaAndName partial_view,
                               SchemaAndName materialization_table,
                               const NameData *time_column_name,
                               void *time_range,
                               int32 chunk_id);
void *internal_time_range_to_time_range(InternalTimeRange range);