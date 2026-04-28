#include <stdio.h>

typedef struct bio_st BIO;
typedef struct asn1_object_st ASN1_OBJECT;

int OBJ_obj2txt(char *buf, int buf_len, const ASN1_OBJECT *a, int no_name);
int BIO_write(BIO *b, const void *data, int dlen);