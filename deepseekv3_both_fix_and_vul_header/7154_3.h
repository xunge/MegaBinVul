#include <stdbool.h>
#include <stdint.h>

#define SPI_OK_CONNECT 1
#define SPI_OK_FINISH 2
#define ERROR 1
#define ERRCODE_INTERNAL_ERROR 1

typedef struct ReplicationInfo {
    bool got_num_wal_senders;
    int num_wal_senders;
    bool got_is_wal_receiver;
    bool is_wal_receiver;
} ReplicationInfo;

typedef uintptr_t Datum;

typedef struct {
    void* vals[1];
    void* tupdesc;
} SPITupleTable;

extern SPITupleTable* SPI_tuptable;

int SPI_connect(void);
int SPI_exec(const char* query, int count);
int SPI_execute(const char* query, bool read_only, long count);
Datum SPI_getbinval(void* value, void* tupdesc, int fnumber, bool* isnull);
int SPI_finish(void);
int32_t DatumGetInt32(Datum x);
bool DatumGetBool(Datum x);
void elog(int level, const char* fmt, ...);
void ereport(int level, ...);
int errcode(int code);
char* errmsg(const char* msg);
char* SPI_result_code_string(int code);