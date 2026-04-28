#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char* crypt_key;
extern char* note_encrypt(char* value, char* key);
extern char* db_err();

struct sqlite3;
struct sqlite3_stmt;

struct {
    struct sqlite3* db;
    char* error_msg;
} db_data;

#define SQLITE_OK 0
#define SQLITE_DONE 101

int asprintf(char **strp, const char *fmt, ...);
int sqlite3_prepare_v2(struct sqlite3 *db, const char *sql, int nByte, struct sqlite3_stmt **ppStmt, const char **pzTail);
int sqlite3_bind_text(struct sqlite3_stmt*, int, const char*, int, void(*)(void*));
int sqlite3_step(struct sqlite3_stmt*);
int sqlite3_finalize(struct sqlite3_stmt*);
int sqlite3_exec(struct sqlite3 *db, const char *sql, int (*callback)(void*,int,char**,char**), void *arg, char **errmsg);

typedef struct sqlite3_stmt sqlite3_stmt;