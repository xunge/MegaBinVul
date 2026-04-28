#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#define _GNU_SOURCE

typedef struct MemoryContext {
    void* opaque;
} *MemoryContext;

typedef struct Node {
    int type;
} Node;

typedef struct CreateFunctionStmt {
    int dummy;
} CreateFunctionStmt;

typedef struct {
    char* error;
    char* plpgsql_funcs;
} PgQueryPlpgsqlParseResult;

typedef struct {
    Node* tree;
    char* error;
    char* stderr_buffer;
} PgQueryInternalParsetreeAndError;

typedef struct {
    void* func;
    char* error;
} PgQueryInternalPlpgsqlFuncAndError;

typedef struct {
    CreateFunctionStmt** stmts;
    size_t stmts_count;
    size_t stmts_buf_size;
} createFunctionStmts;

void* palloc(size_t size);
void pfree(void* pointer);
MemoryContext pg_query_enter_memory_context(const char* context_name);
void pg_query_exit_memory_context(MemoryContext ctx);
PgQueryInternalParsetreeAndError pg_query_raw_parse(const char* input);
void create_function_stmts_walker(Node* node, createFunctionStmts* statements);
PgQueryInternalPlpgsqlFuncAndError pg_query_raw_parse_plpgsql(CreateFunctionStmt* stmt);
char* plpgsqlToJSON(void* func);
void plpgsql_free_function_memory(void* func);