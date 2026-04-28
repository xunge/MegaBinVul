#include <stdlib.h>
#include <string.h>

typedef unsigned long long ut64;

typedef enum {
    DW_AT_name,
    DW_AT_type
} DW_AT;

typedef struct {
    char *content;
} RBinDwarfString;

typedef struct {
    ut64 reference;
    RBinDwarfString string;
    DW_AT attr_name;
} RBinDwarfAttrValue;

typedef struct {
    RBinDwarfAttrValue *attr_values;
    size_t count;
    ut64 offset;
} RBinDwarfDie;

typedef enum {
    R_ANAL_BASE_TYPE_KIND_TYPEDEF
} RAnalBaseTypeKind;

typedef struct {
    char *name;
    char *type;
    RAnalBaseTypeKind kind;
} RAnalBaseType;

typedef struct RAnal {
    // Placeholder for RAnal structure
} RAnal;

typedef struct RStrBuf {
    // Placeholder for RStrBuf structure
} RStrBuf;

void r_return_if_fail(const void *);
void r_strbuf_init(RStrBuf *);
char *r_strbuf_drain_nofree(RStrBuf *);
void r_strbuf_fini(RStrBuf *);
RAnalBaseType *r_anal_new_base_type(RAnalBaseTypeKind kind);
void r_anal_save_base_type(const RAnal *, RAnalBaseType *);
void r_anal_free_base_type(RAnalBaseType *);
void parse_type(const RBinDwarfDie *, ut64, ut64, RStrBuf *, ut64 *);
char *create_type_name_from_offset(ut64 offset);