#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned int Oid;
typedef struct List List;
typedef struct ListCell ListCell;
typedef struct RawStmt RawStmt;
typedef struct Node Node;

#define PG_FUNCTION_ARGS void
#define Datum void*
#define PG_ARGISNULL(n) 0
#define PG_GETARG_TEXT_P(n) ""
#define text_to_cstring(str) (str ? strdup(str) : NULL)
#define PG_RETURN_VOID() return NULL
#define BOOTSTRAP_SUPERUSERID 0
#define SECURITY_LOCAL_USERID_CHANGE 0
#define SPI_OK_CONNECT 0
#define SPI_OK_FINISH 0
#define SPI_result_code_string(code) ""
#define T_CreateSubscriptionStmt 1
#define T_AlterSubscriptionStmt 2
#define T_DropSubscriptionStmt 3

#define elog(level, ...) fprintf(stderr, __VA_ARGS__)
#define ereport(level, args) fprintf(stderr, "%s", args)
#define ERROR 0
#define ERRCODE_INSUFFICIENT_PRIVILEGE 0
#define ERRCODE_FEATURE_NOT_SUPPORTED 0
#define ERRCODE_INTERNAL_ERROR 0
#define errmsg(...) __VA_ARGS__
#define errcode(code) code

bool superuser(void) { return false; }
bool has_rolreplication(Oid userid) { return false; }
Oid GetUserId(void) { return 0; }
void GetUserIdAndSecContext(Oid* userid, int* sec_context) {}
void SetUserIdAndSecContext(Oid userid, int sec_context) {}
List* pg_parse_query(const char* query) { return NULL; }
#define foreach(item, list) for(item=NULL; item; item=NULL)
#define lfirst_node(type, cell) NULL
#define nodeTag(node) 0
int SPI_connect(void) { return 0; }
int SPI_exec(const char* query, int limit) { return 0; }
int SPI_execute(const char* query, bool read_only, long limit) { return 0; }
int SPI_finish(void) { return 0; }