#include <stdlib.h>
#include <string.h>

typedef struct ASN1_VALUE_st ASN1_VALUE;
typedef struct ASN1_ITEM_st ASN1_ITEM;
typedef struct ASN1_TEMPLATE_st ASN1_TEMPLATE;
typedef struct ASN1_AUX_st ASN1_AUX;
typedef struct ASN1_TLC_st ASN1_TLC;
typedef struct ASN1_COMPAT_FUNCS_st ASN1_COMPAT_FUNCS;
typedef struct ASN1_EXTERN_FUNCS_st ASN1_EXTERN_FUNCS;

typedef int ASN1_aux_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it, void *exarg);

struct ASN1_TEMPLATE_st {
    unsigned long flags;
    long tag;
    unsigned long offset;
    const char *field_name;
    const ASN1_ITEM *item;
};

struct ASN1_AUX_st {
    void *app_data;
    int flags;
    ASN1_aux_cb *asn1_cb;
    int ref_offset;
    int ref_lock;
};

struct ASN1_TLC_st {
    char valid;
    unsigned char ret;
    unsigned long plen;
    int ptag;
    int pclass;
};

struct ASN1_COMPAT_FUNCS_st {
    ASN1_VALUE *(*asn1_d2i)(ASN1_VALUE **, const unsigned char **, long);
    int (*asn1_i2d)(ASN1_VALUE *, unsigned char **);
};

struct ASN1_EXTERN_FUNCS_st {
    void *(*asn1_ex_new)(ASN1_VALUE **, const ASN1_ITEM *);
    void (*asn1_ex_free)(ASN1_VALUE **, const ASN1_ITEM *);
    int (*asn1_ex_clear)(ASN1_VALUE **, const ASN1_ITEM *);
    int (*asn1_ex_d2i)(ASN1_VALUE **, const unsigned char **, long,
                      const ASN1_ITEM *, int, int, char, ASN1_TLC *);
    int (*asn1_ex_i2d)(ASN1_VALUE **, unsigned char **, const ASN1_ITEM *,
                      int, int);
};

struct ASN1_ITEM_st {
    char itype;
    long utype;
    const ASN1_TEMPLATE *templates;
    long tcount;
    const void *funcs;
    long size;
    const char *sname;
};

#define ASN1_ITYPE_PRIMITIVE 0x0
#define ASN1_ITYPE_MSTRING 0x1
#define ASN1_ITYPE_EXTERN 0x2
#define ASN1_ITYPE_COMPAT 0x3
#define ASN1_ITYPE_CHOICE 0x4
#define ASN1_ITYPE_SEQUENCE 0x5
#define ASN1_ITYPE_NDEF_SEQUENCE 0x6

#define ASN1_TFLG_OPTIONAL (0x1)
#define ASN1_TFLG_ADB_MASK (0x3<<8)

#define V_ASN1_UNIVERSAL 0x00
#define V_ASN1_CONSTRUCTED 0x20
#define V_ASN1_SEQUENCE 0x10

#define ASN1_F_ASN1_ITEM_EX_D2I 0
#define ASN1_R_ILLEGAL_OPTIONS_ON_ITEM_TEMPLATE 0
#define ASN1_R_MSTRING_NOT_UNIVERSAL 0
#define ASN1_R_MSTRING_WRONG_TAG 0
#define ASN1_R_NO_MATCHING_CHOICE_TYPE 0
#define ASN1_R_SEQUENCE_NOT_CONSTRUCTED 0
#define ASN1_R_SEQUENCE_LENGTH_MISMATCH 0
#define ASN1_R_FIELD_MISSING 0
#define ASN1_R_MISSING_EOC 0
#define ASN1_R_UNEXPECTED_EOC 0
#define ASN1_R_AUX_ERROR 0

#define ASN1_OP_D2I_PRE 0
#define ASN1_OP_D2I_POST 1

#define ASN1_AFLG_BROKEN 0x1

#define ERR_R_NESTED_ASN1_ERROR 0

void ASN1err(int function, int reason);
void ERR_add_error_data(int num, ...);
int asn1_template_ex_d2i(ASN1_VALUE **pval, const unsigned char **in, long len,
                        const ASN1_TEMPLATE *tt, char opt, ASN1_TLC *ctx);
int asn1_d2i_ex_primitive(ASN1_VALUE **pval, const unsigned char **in, long len,
                         const ASN1_ITEM *it, int tag, int aclass, char opt,
                         ASN1_TLC *ctx);
int asn1_check_tlen(long *olen, int *otag, unsigned char *oclass, char *inf,
                   char *cst, const unsigned char **in, long len,
                   int exptag, int expclass, char opt, ASN1_TLC *ctx);
unsigned long ASN1_tag2bit(int tag);
const ASN1_TEMPLATE *asn1_do_adb(ASN1_VALUE **pval, const ASN1_TEMPLATE *tt, int nullerr);
ASN1_VALUE **asn1_get_field_ptr(ASN1_VALUE **pval, const ASN1_TEMPLATE *tt);
void ASN1_template_free(ASN1_VALUE **pval, const ASN1_TEMPLATE *tt);
int asn1_set_choice_selector(ASN1_VALUE **pval, int value, const ASN1_ITEM *it);
int asn1_get_choice_selector(ASN1_VALUE **pval, const ASN1_ITEM *it);
int ASN1_item_ex_new(ASN1_VALUE **pval, const ASN1_ITEM *it);
void ASN1_item_ex_free(ASN1_VALUE **pval, const ASN1_ITEM *it);
int asn1_check_eoc(const unsigned char **in, long len);
int asn1_enc_save(ASN1_VALUE **pval, const unsigned char *in, int inlen,
                 const ASN1_ITEM *it);