#include <stddef.h>

typedef struct _krb5_key_salt_tuple {
    int ks_enctype;
    int ks_salttype;
} krb5_key_salt_tuple;

typedef struct _kadm5_principal_ent_rec {
    unsigned long attributes;
} *kadm5_principal_ent_t;

#define KADM5_ATTRIBUTES 0x00000001
#define KRB5_KDB_DISALLOW_ALL_TIX 0x00000001