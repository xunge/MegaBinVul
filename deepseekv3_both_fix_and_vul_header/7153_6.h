#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct {
    char* data;
} StringInfoData;
typedef StringInfoData* StringInfo;

typedef struct JsonbParseState JsonbParseState;
typedef struct HeapTupleData* HeapTuple;
typedef struct TupleDescData* TupleDesc;
typedef struct SPITupleTable {
    HeapTuple* vals;
    TupleDesc tupdesc;
} SPITupleTable;
typedef struct MemoryContextData* MemoryContext;
typedef unsigned long Datum;

typedef struct {
    int64_t total_runs;
    int64_t total_successes;
    int64_t total_failures;
    int64_t total_crashes;
    int32_t max_consecutive_failures;
    int32_t max_consecutive_crashes;
    void* total_duration;
    void* total_duration_failures;
} TelemetryJobStats;

#define SPI_OK_CONNECT 1
#define SPI_OK_FINISH 2
#define CurrentMemoryContext ((MemoryContext)0)
#define ERROR 1
#define ERRCODE_INTERNAL_ERROR 1

extern int SPI_connect(void);
extern int SPI_exec(const char* src, int cnt);
extern int SPI_execute(const char* src, bool read_only, int cnt);
extern void elog(int level, const char* fmt, ...);
extern void ereport(int level, const char* msg);
extern StringInfo makeStringInfo(void);
extern void appendStringInfoString(StringInfo str, const char* s);
extern Datum SPI_getbinval(HeapTuple tuple, TupleDesc tupdesc, int fnumber, bool* isnull);
extern void* DatumGetIntervalP(Datum d);
extern int64_t DatumGetInt64(Datum d);
extern int32_t DatumGetInt32(Datum d);
extern char* TextDatumGetCString(Datum d);
extern void add_job_stats_internal(JsonbParseState* state, const char* str, TelemetryJobStats* stats);
extern int SPI_finish(void);
extern MemoryContext MemoryContextSwitchTo(MemoryContext context);
extern void Assert(int condition);

extern uint64_t SPI_processed;
extern SPITupleTable* SPI_tuptable;

typedef uint64_t uint64;