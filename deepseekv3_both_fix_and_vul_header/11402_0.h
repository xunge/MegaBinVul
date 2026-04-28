#include <stdlib.h>

typedef struct ParseCommon ParseCommon;
typedef struct ExprDef ExprDef;

struct ExprDef {
    struct {
        void *syms;
        void *symsMapIndex;
        void *symsNumEntries;
    } keysym_list;
};

void FreeStmt(ParseCommon *stmt);
unsigned darray_size(void *array);
void darray_append(void *array, unsigned value);
void darray_concat(void *dest, void *src);