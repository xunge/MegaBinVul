#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ASN1_VALUE_st ASN1_VALUE;
typedef struct ASN1_TLC_st ASN1_TLC;

typedef struct ASN1_TEMPLATE_st {
    unsigned long flags;
    const char *field_name;
} ASN1_TEMPLATE;

typedef int ASN1_aux_cb(int operation, ASN1_VALUE **pval, const struct ASN1_ITEM_st *it, void *exarg);

typedef struct ASN1_AUX_st {
    int flags;
    ASN1_aux_cb *asn1_cb;
} ASN1_AUX;

typedef struct ASN1_COMPAT_FUNCS_st {
    ASN1_VALUE *(*asn1_d2i)(ASN1_VALUE **pval, const unsigned char **in, long len);
} ASN1_COMPAT_FUNCS;

typedef struct ASN1_EXTERN_FUNCS_st {
    int (*asn1_ex_d2i)(ASN1_VALUE **pval, const unsigned char **in, long len,
                      const struct ASN1_ITEM_st *it, int tag, int aclass, char opt, ASN1_TLC *ctx);
} ASN1_EXTERN_FUNCS;

typedef struct ASN1_ITEM_st {
    int itype;
    const ASN1_TEMPLATE *templates;
    int tcount;
    long utype;
    const void *funcs;
    const char *sname;
} ASN1_ITEM;

#define ASN1_F_ASN1_ITEM_EX_D2I 0
#define ASN1_R_ILLEGAL_OPTIONS_ON_ITEM_TEMPLATE 0
#define ASN1_R_MSTRING_NOT_UNIVERSAL 0
#define ASN1_R_MSTRING_WRONG_TAG 0
#define ASN1_R_NO_MATCHING_CHOICE_TYPE 0
#define ASN1_R_SEQUENCE_NOT_CONSTRUCTED 0
#define ASN1_R_UNEXPECTED_EOC 0
#define ASN1_R_MISSING_EOC 0
#define ASN1_R_SEQUENCE_LENGTH_MISMATCH 0
#define ASN1_R_FIELD_MISSING 0
#define ASN1_R_AUX_ERROR 0

#define ERR_R_NESTED_ASN1_ERROR 0

#define V_ASN1_UNIVERSAL 0
#define V_ASN1_CONSTRUCTED (0x20)
#define V_ASN1_SEQUENCE (0x10)

#define ASN1_OP_D2I_PRE 0
#define ASN1_OP_D2I_POST 0

#define ASN1_TFLG_COMBINE (0x1)
#define ASN1_TFLG_OPTIONAL (0x1)
#define ASN1_TFLG_ADB_MASK (0x3)

#define ASN1_AFLG_BROKEN (0x1)

#define ASN1_ITYPE_PRIMITIVE 0x0
#define ASN1_ITYPE_MSTRING 0x1
#define ASN1_ITYPE_EXTERN 0x2
#define ASN1_ITYPE_COMPAT 0x3
#define ASN1_ITYPE_CHOICE 0x4
#define ASN1_ITYPE_NDEF_SEQUENCE 0x5
#define ASN1_ITYPE_SEQUENCE 0x6

void ASN1err(int function, int reason);
int asn1_template_ex_d2i(ASN1_VALUE **pval, const unsigned char **in, long len,
                        const ASN1_TEMPLATE *tt, char opt, ASN1_TLC *ctx);
int asn1_d2i_ex_primitive(ASN1_VALUE **pval, const unsigned char **in, long len,
                         const ASN1_ITEM *it, int tag, int aclass, char opt,
                         ASN1_TLC *ctx);
int asn1_check_tlen(long *olen, int *otag, unsigned char *oclass, char *inf,
                    char *cst, const unsigned char **in, long len,
                    int exptag, int expclass, char opt, ASN1_TLC *ctx);
unsigned long ASN1_tag2bit(int tag);
int asn1_get_choice_selector(ASN1_VALUE **pval, const ASN1_ITEM *it);
ASN1_VALUE **asn1_get_field_ptr(ASN1_VALUE **pval, const ASN1_TEMPLATE *tt);
void ASN1_template_free(ASN1_VALUE **pval, const ASN1_TEMPLATE *tt);
int asn1_set_choice_selector(ASN1_VALUE **pval, int value, const ASN1_ITEM *it);
int ASN1_item_ex_new(ASN1_VALUE **pval, const ASN1_ITEM *it);
int asn1_check_eoc(const unsigned char **in, long len);
const ASN1_TEMPLATE *asn1_do_adb(ASN1_VALUE **pval, const ASN1_TEMPLATE *tt, int nullerr);
int asn1_enc_save(ASN1_VALUE **pval, const unsigned char *in, int inlen,
                 const ASN1_ITEM *it);
void ASN1_item_ex_free(ASN1_VALUE **pval, const ASN1_ITEM *it);
void ERR_add_error_data(int num, ...);