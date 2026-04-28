#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long Datum;

typedef struct StringInfo
{
    char *data;
    int len;
} *StringInfo;

typedef struct NameData
{
    char data[64];
} NameData;

#define NameStr(name) ((const char *)(name).data)

typedef struct Hypertable
{
    unsigned int main_table_relid;
    struct
    {
        NameData schema_name;
        NameData table_name;
    } fd;
    void *space;
} Hypertable;

typedef struct Dimension
{
    struct
    {
        NameData column_name;
    } fd;
} Dimension;

typedef struct hyperspace
{
    int dummy;
} hyperspace;

struct SPI_tuptable
{
    void *tupdesc;
    void **vals;
};

extern struct SPI_tuptable *SPI_tuptable;

#define SPI_OK_CONNECT 1
#define SPI_OK_FINISH 1
#define ERROR 1
#define ERRCODE_INTERNAL_ERROR 1

extern const Dimension *hyperspace_get_open_dimension(hyperspace *space, int dimension_index);
extern int ts_dimension_get_partition_type(const Dimension *dim);
extern char *get_rel_name(unsigned int relid);
extern StringInfo makeStringInfo(void);
extern void appendStringInfo(StringInfo str, const char *fmt, ...);
extern char *quote_identifier(const char *ident);
extern int SPI_connect(void);
extern int SPI_execute(const char *src, bool read_only, long count);
extern int SPI_gettypeid(void *tupdesc, int col);
extern Datum SPI_getbinval(void *tuple, void *tupdesc, int col, bool *isnull);
extern int SPI_finish(void);
extern char *SPI_result_code_string(int res);
extern void elog(int level, const char *fmt, ...);
extern void ereport(int level, void *data);
extern void Ensure(bool condition, const char *fmt, ...);
extern int errcode(int sqlerrcode);
extern char *errmsg(const char *fmt, ...);