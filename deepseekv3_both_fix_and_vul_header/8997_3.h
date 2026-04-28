#include <stdlib.h>

#define ERR_R_NESTED_ASN1_ERROR 1
#define ERR_R_MALLOC_FAILURE 2
#define ASN1_R_UNEXPECTED_EOC 3
#define ASN1_R_MISSING_EOC 4

typedef struct ASN1_VALUE_st ASN1_VALUE;
typedef struct ASN1_TLC_st ASN1_TLC;
typedef struct ASN1_ITEM_st ASN1_ITEM;

typedef struct ASN1_TEMPLATE_st {
    long flags;
    long tag;
    const ASN1_ITEM *item;
} ASN1_TEMPLATE;

#define V_ASN1_UNIVERSAL 0x00
#define V_ASN1_SET 0x11
#define V_ASN1_SEQUENCE 0x10

#define ASN1_F_ASN1_TEMPLATE_NOEXP_D2I 0

#define ASN1_TFLG_TAG_CLASS 0x300
#define ASN1_TFLG_SK_MASK 0x400
#define ASN1_TFLG_IMPTAG 0x100
#define ASN1_TFLG_SET_OF 0x200
#define ASN1_TFLG_COMBINE 0x800

typedef struct stack_st_ASN1_VALUE {
    int dummy;
} STACK_OF_ASN1_VALUE;

#define STACK_OF(type) struct stack_st_##type
#define sk_new_null() ((STACK_OF_ASN1_VALUE*)malloc(sizeof(STACK_OF_ASN1_VALUE)))
#define sk_ASN1_VALUE_num(st) (0)
#define sk_ASN1_VALUE_pop(st) (NULL)
#define sk_ASN1_VALUE_push(st, val) (1)

void ASN1err(int a, int b) {}
void ASN1_item_ex_free(ASN1_VALUE **val, const ASN1_ITEM *it) {}
int asn1_check_tlen(long *len, void *a, void *b, char *c, void *d, const unsigned char **e, long f, int g, int h, char i, ASN1_TLC *j) { return 0; }
int asn1_check_eoc(const unsigned char **in, long len) { return 0; }
int ASN1_item_ex_d2i(ASN1_VALUE **val, const unsigned char **in, long len, const ASN1_ITEM *it, int tag, int aclass, char opt, ASN1_TLC *ctx) { return 0; }
void ASN1_template_free(ASN1_VALUE **val, const ASN1_TEMPLATE *tt) {}
const ASN1_ITEM *ASN1_ITEM_ptr(const ASN1_ITEM *it) { return it; }