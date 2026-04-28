#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct JsonbParseState JsonbParseState;
typedef struct StringInfoData *StringInfo;
typedef struct MemoryContextData *MemoryContext;
typedef unsigned long Datum;
typedef struct Jsonb Jsonb;
typedef struct SPITupleTable SPITupleTable;
typedef uint64_t uint64;

#define SPI_OK_CONNECT 1
#define SPI_OK_FINISH 2
#define SPI_processed 0
#define CurrentMemoryContext NULL
#define ERROR 1
#define ERRCODE_INTERNAL_ERROR 0

struct StringInfoData {
    char *data;
};

struct Jsonb {
    char data[1];
};

struct SPITupleTable {
    void **vals;
    void *tupdesc;
};

StringInfo makeStringInfo();
void appendStringInfoString(StringInfo str, const char *s);

int SPI_connect();
int SPI_exec(const char *src, int cnt);
int SPI_execute(const char *src, bool read_only, long cnt);
int SPI_finish();
Datum SPI_getbinval(void *vals, void *tupdesc, int col, bool *isnull);
char *TextDatumGetCString(Datum d);
Jsonb *DatumGetJsonbP(Datum d);

void elog(int level, const char *fmt, ...);
void ereport(int level, ...);
#define errcode(code) code
#define errmsg(msg) msg

MemoryContext MemoryContextSwitchTo(MemoryContext context);
void add_errors_by_sqlerrcode_internal(JsonbParseState *parse_state, const char *jobtype, Jsonb *jsonb);
void Assert(int condition);

extern SPITupleTable *SPI_tuptable;