#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

typedef int Jsi_RC;
#define JSI_OK 0

typedef struct Jsi_Interp {
    struct Jsi_Hash *lexkeyTbl;
} Jsi_Interp;

typedef struct Jsi_Hash Jsi_Hash;
typedef struct Jsi_HashEntry Jsi_HashEntry;

struct Jsi_Hash {
    unsigned int numEntries;
};

#define IF 1
#define ELSE 2
#define FOR 3
#define IN 4
#define WHILE 5
#define DO 6
#define CONTINUE 7
#define SWITCH 8
#define CASE 9
#define DEFAULT 10
#define BREAK 11
#define FUNC 12
#define RETURN 13
#define LOCAL 14
#define LOCALLET 15
#define LOCALCONST 16
#define OF 17
#define NEW 18
#define DELETE 19
#define TRY 20
#define CATCH 21
#define THROW 22
#define FINALLY 23
#define WITH 24
#define UNDEF 25
#define _TRUE 26
#define _FALSE 27
#define _THIS 28
#define ARGUMENTS 29
#define VOID 30
#define TYPEOF 31
#define INSTANCEOF 32
#define TYPESTRING 33
#define TYPENUMBER 34
#define TYPEREGEXP 35
#define TYPEANY 36
#define TYPEUSEROBJ 37
#define TYPEITEROBJ 38
#define TYPEOBJECT 39
#define TYPEBOOLEAN 40
#define TYPEARRAY 41
#define TYPENULL 42
#define EXPORT 43
#define OBJSET 44
#define OBJGET 45
#define ELLIPSIS 46
#define __DEBUG 47

typedef unsigned int uint;

Jsi_HashEntry* Jsi_HashEntryNew(Jsi_Hash *tbl, const char *key, bool *isNew);
void* Jsi_HashValueGet(Jsi_HashEntry *hPtr);
void Jsi_HashValueSet(Jsi_HashEntry *hPtr, void *value);