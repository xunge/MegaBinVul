#include <stddef.h>
#include <stdbool.h>

typedef char *str;

typedef struct ValPtr {
    int vtype;
} *ValPtr;

typedef struct ValRecord {
    int vtype;
} ValRecord;

typedef struct BATatom {
    void *atomNull;
    int (*atomCmp)(void*, void*);
    int (*atomToStr)(char**, size_t*, void*, bool);
} BATatom;

extern BATatom BATatoms[];

#define TYPE_bte 1
#define TYPE_sht 2
#define TYPE_int 3
#define TYPE_flt 4
#define TYPE_dbl 5
#define TYPE_lng 6
#define TYPE_hge 7
#define TYPE_str 8

extern void *VALget(ValPtr res);
extern void *VALptr(ValPtr res);
extern void *VALinit(ValRecord *val, int type, char *buf);
extern char *VALformat(ValRecord *val);
extern void VALclear(ValRecord *val);
extern char *GDKstrdup(const char *s);
extern void GDKfree(void *ptr);