#include <stdint.h>
#include <string.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint8_t u8;

typedef struct sqlite3 sqlite3;
typedef struct sqlite3_context sqlite3_context;
typedef struct sqlite3_value sqlite3_value;

#define SQLITE_OK 0
#define SQLITE_ERROR 1
#define SQLITE_NOMEM 7
#define SQLITE_NULL 5

#define SQLITE_WriteSchema 0x00800000
#define SQLITE_IgnoreChecks 0x00004000
#define SQLITE_ForeignKeys 0x00008000
#define SQLITE_ReverseOrder 0x00000100
#define SQLITE_Defensive 0x00000200
#define SQLITE_CountRows 0x00000400

#define DBFLAG_PreferBuiltin 0x0001
#define DBFLAG_Vacuum 0x0002

struct sqlite3 {
    u64 flags;
    u32 mDbFlags;
    int nChange;
    int nTotalChange;
    u8 mTrace;
    struct {
        int iDb;
    } init;
};

extern sqlite3 *sqlite3_context_db_handle(sqlite3_context*);
extern int sqlite3_value_type(sqlite3_value*);
extern const char *sqlite3_value_text(sqlite3_value*);
extern char *sqlite3_mprintf(const char*, ...);
extern void sqlite3_free(void*);
extern void sqlite3_result_error(sqlite3_context*, const char*, int);
extern void sqlite3DbFree(sqlite3*, void*);
extern const char *sqlite3ErrStr(int);
extern int sqlite3StrICmp(const char*, const char*);
extern int sqlcipher_find_db_index(sqlite3*, const char*);
extern int sqlcipher_execExecSql(sqlite3*, char**, const char*);
extern int sqlcipher_execSql(sqlite3*, char**, const char*);