#include <stdlib.h>
#include <string.h>

typedef unsigned long long ut64;

#define DW_AT_name 0x03
#define DW_AT_type 0x49

typedef struct RBinDwarfDie {
    struct RBinDwarfAttrValue *attr_values;
    ut64 count;
    ut64 offset;
} RBinDwarfDie;

typedef struct RBinDwarfAttrValue {
    int attr_name;
    union {
        struct {
            char *content;
        } string;
        ut64 reference;
    };
} RBinDwarfAttrValue;

typedef struct RAnal RAnal;

typedef enum {
    R_ANAL_BASE_TYPE_KIND_TYPEDEF
} RAnalBaseTypeKind;

typedef struct RAnalBaseType {
    char *name;
    char *type;
    RAnalBaseTypeKind kind;
} RAnalBaseType;

typedef struct RStrBuf {
    char *buf;
    size_t len;
    size_t capacity;
} RStrBuf;

#define r_return_if_fail(cond) do { if (!(cond)) return; } while(0)

static char *create_type_name_from_offset(ut64 offset);
static void parse_type(const RBinDwarfDie *all_dies, const ut64 count, ut64 reference, RStrBuf *strbuf, ut64 *size);
static RAnalBaseType *r_anal_new_base_type(RAnalBaseTypeKind kind);
static void r_anal_save_base_type(const RAnal *anal, RAnalBaseType *base_type);
static void r_anal_free_base_type(RAnalBaseType *base_type);
static void r_strbuf_init(RStrBuf *sb);
static void r_strbuf_fini(RStrBuf *sb);
static char *r_strbuf_drain_nofree(RStrBuf *sb);