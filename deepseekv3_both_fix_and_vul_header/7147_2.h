#include <stdbool.h>
#include <stddef.h>

typedef struct CallContext {
    int type;
    bool atomic;
} CallContext;

typedef struct FunctionCallInfoBaseData {
    void *context;
} FunctionCallInfoBaseData;

typedef unsigned int Datum;
typedef FunctionCallInfoBaseData *FunctionCallInfo;

#define PG_FUNCTION_ARGS FunctionCallInfo fcinfo
#define PG_ARGISNULL(n) 0
#define PG_GETARG_NAME(n) ((NameData*)0)
#define NameStr(name) ""
#define IsA(nodeptr, type) (0)
#define castNode(type, nodeptr) ((type *)nodeptr)
#define TS_PREVENT_FUNC_IF_READ_ONLY()
#define PreventInTransactionBlock(b, str)
#define get_func_name(oid) ""
#define FC_FN_OID(fcinfo) 0
#define ereport(level, ...)
#define errcode(code) 0
#define errmsg(str) 0
#define elog(level, ...)
#define PG_RETURN_VOID() return (Datum)0

#define SPI_connect_ext(opt) 0
#define SPI_OPT_NONATOMIC 0
#define SPI_OK_CONNECT 0
#define SPI_result_code_string(rc) ""
#define SPI_finish() 0
#define SPI_OK_FINISH 0

#define ERROR 0
#define ERRCODE_INVALID_PARAMETER_VALUE 0

typedef struct NameData {
    char data[64];
} NameData;

extern void chunk_copy_cleanup(const char *operation_id);