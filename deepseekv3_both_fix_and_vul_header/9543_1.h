#include <stdlib.h>
#include <string.h>

struct berval {
    unsigned long bv_len;
    char *bv_val;
};

typedef struct krb5_data {
    unsigned int length;
    char *data;
} krb5_data;

typedef int krb5_error_code;
typedef int krb5_kvno;
typedef int krb5_int16;

typedef struct {
    int key_data_ver;
    int key_data_kvno;
    int key_data_type[2];
    int key_data_length[2];
    char *key_data_contents[2];
} krb5_key_data;

#define KRB5_KDB_SALTTYPE_NORMAL 0
#define ENOMEM 12

void *k5calloc(size_t, size_t, krb5_error_code *);
void *k5alloc(size_t, krb5_error_code *);
krb5_error_code asn1_encode_sequence_of_keys(krb5_key_data *, krb5_int16, krb5_kvno, krb5_data **);