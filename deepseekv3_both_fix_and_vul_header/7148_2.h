#include <stdbool.h>
#include <stddef.h>

typedef unsigned int Oid;
#define InvalidOid ((Oid) 0)
#define OidIsValid(oid) ((oid) != InvalidOid)

typedef struct NodeTag
{
    int type;
} NodeTag;

typedef struct CallContext
{
    NodeTag type;
    bool atomic;
} CallContext;

typedef struct FunctionCallInfoBaseData
{
    void *context;
} *FunctionCallInfo;

typedef char* Name;

#define PG_ARGISNULL(n) (0)
#define PG_GETARG_OID(n) (0)
#define PG_GETARG_NAME(n) ((Name)NULL)
#define NameStr(name) ("")
#define FC_FN_OID(fcinfo) (0)
#define SPI_OPT_NONATOMIC (0)
#define SPI_OK_CONNECT (0)
#define SPI_OK_FINISH (0)
#define SPI_result_code_string(rc) ("")
#define ERROR (0)
#define ERRCODE_INVALID_PARAMETER_VALUE (0)

#define TS_PREVENT_FUNC_IF_READ_ONLY()
#define PreventInTransactionBlock(b, s)
#define ereport(level, ...)
#define elog(level, ...)
#define IsA(node, type) (0)
#define castNode(type, node) ((type *)node)

int SPI_connect_ext(int options);
int SPI_finish(void);
void chunk_copy(Oid chunk_id, const char *src_node_name, const char *dst_node_name, const char *op_id, bool delete_on_src_node);
const char *get_func_name(Oid func_oid);