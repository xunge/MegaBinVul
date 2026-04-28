#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint64_t ut64;
typedef uint32_t ut32;

#define UT64_MAX UINT64_MAX
#define UT32_MAX UINT32_MAX
#define R_MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct r_bin_t r_bin_t;
typedef struct RBinFile RBinFile;
typedef struct RBinDexObj RBinDexObj;
typedef struct RList RList;
typedef struct dex_class_t dex_class_t;
typedef struct dex_method_t dex_method_t;
typedef struct RBinImport RBinImport;
typedef struct RBinSymbol RBinSymbol;
typedef struct sdb_t sdb_t;

typedef void (*RListFree)(void *);

struct r_bin_t {
    void (*cb_printf)(const char *fmt, ...);
};

struct RBinFile {
    r_bin_t *rbin;
};

struct dex_class_t {
    // Placeholder for dex class structure
};

struct dex_method_t {
    int class_id;
    // Placeholder for dex method structure
};

struct RBinDexObj {
    dex_class_t *classes;
    dex_method_t *methods;
    RList *methods_list;
    RList *imports_list;
    RList *classes_list;
    ut64 code_from;
    ut64 code_to;
    ut64 size;
    struct {
        ut64 method_size;
        ut64 class_size;
        ut64 strings_size;
        ut64 method_offset;
        ut64 types_size;
    } header;
    struct {
        ut64 base;
    } *b;
    struct {
        struct {
            int descriptor_id;
        } *types;
    };
};

struct RBinImport {
    char *name;
    char *type;
    char *bind;
    int ordinal;
};

struct RBinSymbol {
    char *name;
    char *type;
    char *bind;
    ut64 paddr;
    ut64 vaddr;
    int ordinal;
};

struct RList {
    int length;
};

#define R_NEW0(type) calloc(1, sizeof(type))

extern int dexdump;
extern sdb_t *mdb;

void __r_bin_class_free(void *ptr);
char *dex_class_name(RBinDexObj *bin, dex_class_t *c);
char *dex_class_super_name(RBinDexObj *bin, dex_class_t *c);
void parse_class(RBinFile *arch, RBinDexObj *bin, dex_class_t *c, int i, int *methods, int *sym_count);
bool is_class_idx_in_code_classes(RBinDexObj *bin, int class_id);
char *getstr(RBinDexObj *bin, int descriptor_id);
char *dex_method_name(RBinDexObj *bin, int i);
char *dex_method_signature(RBinDexObj *bin, int i);
void eprintf(const char *fmt, ...);
RList *r_list_newf(RListFree free);
void r_list_free(RList *list);
void r_list_append(RList *list, void *data);
char *r_str_newf(const char *fmt, ...);
char *r_str_const(const char *str);
void sdb_num_set(sdb_t *db, const char *key, ut64 value, int opts);
char *sdb_fmt(int opts, const char *fmt, ...);