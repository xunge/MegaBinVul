#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint64_t ut64;

typedef struct RzListIter {
    void *data;
    struct RzListIter *n;
} RzListIter;

typedef struct RzList {
    RzListIter *head;
    RzListIter *tail;
} RzList;

typedef struct RzBinFile RzBinFile;
typedef struct RzBinObject RzBinObject;
typedef struct RzBinSymbol RzBinSymbol;
typedef struct RzBinClass RzBinClass;
typedef struct RzBinField RzBinField;

struct RzBinFile {
    RzBinObject *o;
};

struct RzBinObject {
    RzList *symbols;
    RzList *classes;
};

struct RzBinSymbol {
    char *name;
    char *classname;
    char *dname;
    ut64 paddr;
    ut64 vaddr;
    ut64 size;
};

struct RzBinClass {
    RzList *fields;
    RzList *methods;
};

#define rz_list_foreach(list, it, pos) \
    for (it = (list) ? (list)->head : NULL; it && (pos = it->data, 1); it = it->n)

extern RzBinClass *rz_bin_file_add_class(RzBinFile *bf, const char *name, const char *super, int visibility);
extern RzBinField *rz_bin_field_new(ut64 paddr, ut64 vaddr, ut64 size, const char *name, const char *type, const char *comment, bool is_virtual);
extern char *swiftField(char *dname, const char *classname);
extern void rz_list_append(RzList *list, void *data);